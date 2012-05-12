#include "concurrentleppbisection.h"
#include "leppbisectionthread.h"
#include <QtCore/QMutexLocker>
#include <QtCore/QList>
#include <QtCore/QThreadPool>
#include <QtCore/QRunnable>
#include <QtCore/QMapIterator>

#include <QDebug>
#include <iostream>
#include <QThread>

ConcurrentLeppBisection::ConcurrentLeppBisection(Mesh *m,SelectionCriterion *c) :
	RefinementAlgorithm(m,c),
	work_set_iterator(work_set)
	{
	n_threads = QThreadPool::globalInstance()->maxThreadCount();
	workers = new LeppBisectionThread*[n_threads];
}

ConcurrentLeppBisection::~ConcurrentLeppBisection() {
	delete[] workers;
}

void ConcurrentLeppBisection::processMesh(){
	//std::cout << QThread::currentThread() << " processMesh() iniciando threads\n";
	for(int i=0;i<n_threads;i++){
		//QString log_filename = "thread_" + QString::number(i) + ".log";
		workers[i] = new LeppBisectionThread(this,mesh,work_set.size(),i);///n_threads,log_filename);
		QThreadPool::globalInstance()->start(workers[i]);
	}
	//std::cout << QThread::currentThread() << " processMesh() esperando threads\n";
	QThreadPool::globalInstance()->waitForDone();
	//std::cout << QThread::currentThread() << " processMesh() terminando algoritmo\n";
}

int ConcurrentLeppBisection::getDone(){
	QMutexLocker locker(&mutex);
	return done;
}

void ConcurrentLeppBisection::checkedNext(){
	mutex.unlock();
}

Triangle * ConcurrentLeppBisection::getNext(){
	//std::cout << QThread::currentThread() << " getNext() 1 \n";
	mutex.lock();

	int vueltas = 0;
	while(done<total){
		//hago la lista circular
		if(!work_set_iterator.hasNext()){
			//compruebo que existan trabajos por realizar
			Q_ASSERT(work_set_iterator.findPrevious(true));
			vueltas++;
			work_set_iterator.toFront();
		}
		work_set_iterator.next();
		if(work_set_iterator.value()){
			//std::cout << QThread::currentThread() << std::dec << " (" << done << "/" << total << ") " << " getNext(): T=" << work_set_iterator.key()->getId() << std::endl;
			//std::cout.flush();
			return work_set_iterator.key();


			/*Triangle *t = work_set_iterator.key();
			if(t->getMutex()->tryLock()){
				std::cout << QThread::currentThread() << std::dec << " (" << done << "/" << total << ") " << " getNext(): T=" << t->getId() << std::endl;
				//std::cout.flush();
				return t;
			}else{
				if(vueltas>1){
					//si llego aca es pq he dado vueltas al arreglo y todos los
					//otros threads tiene ocupados sus triangulos. puede que alguno
					//quiera terminar asi que suelto el mutex
					vueltas = 0;
					mutex.unlock();
					QThread::usleep(100);
					mutex.lock();
				}
				continue;
			}*/
		} else {
			continue;
		}
	}
	return 0;
}

void ConcurrentLeppBisection::removeFromPending(Triangle *t){
	QMutexLocker locker(&mutex);
	if(work_set.contains(t)){
		if(work_set[t]){
			work_set[t] = false;
			done++;

			//std::cout << QThread::currentThread() << std::dec << " (" << done << "/" << total << ") " << " removeFromPending(): T=" << t->getId() << std::endl;
			//std::cout.flush();
			/*if(work_set.size()<10){
			QMapIterator<Triangle *,bool> i(work_set);
			std::cout << ", restantes = ";
			while (i.findNext(true)) {
				std::cout << i.key()->getId() << " ";
			}
			std::cout << std::endl;
			}*/
		}
	}
}
