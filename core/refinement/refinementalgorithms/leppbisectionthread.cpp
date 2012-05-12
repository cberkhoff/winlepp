#include "leppbisectionthread.h"
#include <iostream>
#include <QtCore/QThread>
#include <QtDebug>

LeppBisectionThread::LeppBisectionThread(ConcurrentLeppBisection *clb, Mesh *mesh, int expectedSize,int id)//, QString log_filename)
	: _id(id)
	//: _log_file(log_filename)
	/*: tp(expectedSize*4),
	vp(expectedSize*2)*/
{
	//_log_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
	/*tp = new TrianglePool(expectedSize*4);
	vp = new VertexPool(expectedSize*2);*/
	_clb = clb;
	_mesh = mesh;

}

LeppBisectionThread::~LeppBisectionThread()
{
	//_log_file.close();
}

/*void LeppBisectionThread::writeLog(QString message){
	QTextStream out(&_log_file);
	out << QThread::currentThread() << " " << message << "\n";
	out.flush();
}*/

void LeppBisectionThread::run(){
	Triangle *t = _clb->getNext();
	while(t!=0){
		bool checkIn = trylockTriangle(t);
		_clb->checkedNext();
		if(checkIn){
			//writeLog(QString("LeppBisectionThread::run() procesando T=")+QString::number(t->getId()));
			tryProcessTriangle(t,0);
			//writeLog(QString("LeppBisectionThread::run() procesado"));
		}
		t = _clb->getNext();
	}
	_clb->checkedNext();
	//writeLog(QString("LeppBisectionThread::run() terminando"));
	/*delete tp;
	delete vp;*/
}

bool LeppBisectionThread::tryProcessTriangle(Triangle *t, int length){
	Q_ASSERT(t!=0);
	bool working = true;
	bool ret = true;

	//if(trylockNeighbors(t)){
	if(trylockTriangle(t)){
		while(working){
			//writeLog(QString("LeppBisectionThread::tryProcessTriangle(...) working"));
			//obtengo el vecino por la arista mas larga, u
			Triangle *u = t->getNeighbor(t->longestEdgeIndex());
			//si es nulo estoy en el borde, corto nomas
			if(u==0){
				if(trylockNeighbors(t)){
					removeFromLockCount(t);
					refineTriangle(t,0);
				} else {
					//si fallo pidiendo algun vecino entonces retorno falso
					ret = false;
				}
				working = false;
			} else {
				//trato de pedir el lock de todos los vecinos de u
				if(trylockTriangle(u)){
				//if(trylockNeighbors(u)){
					//si comparten la arista mas larga entonces corto
					Edge e_u = u->getEdge(u->longestEdgeIndex());
					Edge e_t = t->getEdge(t->longestEdgeIndex());
					if(e_u.sameVertexsId(&e_t)){
						//comparte arista asi que refino
						if(trylockNeighbors(u)){
							removeFromLockCount(t);
							removeFromLockCount(u);
							refineTriangle(t,u);
						} else {
							//si fallo pidiendo algun vecino entonces retorno falso
							ret = false;
						}
						working = false;
					}else{
						//no comparten arista asi que continuo
						if(!tryProcessTriangle(u,length+1)){
							//si estoy aca es por que alguno de mis ejecuciones po pudo conseguir
							//los vecinos. ie. muero
							working = false;
							ret = false;
						}
					}
				} else {
					working = false;
					//si fallo pidiendo algun vecino entonces retorno falso
					ret = false;
				}
			} //if(u==0)
		} //while(true)
	} else {
		working = false;
		//si fallo pidiendo algun vecino entonces retorno falso
		ret = false;

	}
	if(length==0){
		unlockAll();
	}
	return ret;
} //tryProcessTriangle

bool LeppBisectionThread::trylockTriangle(Triangle *t){
	if(locks.contains(t)){
		return true;
	} else {
		if(t->getMutex()->tryLock()){
			locks << t;
			return true;
		} else {
			return false;
		}
	}
}

bool LeppBisectionThread::trylockNeighbors(Triangle *t){
	int i;
	for(i=0;i<3;i++){
		Triangle *neighbor = t->getNeighbor(i);
		if(neighbor!=0){
			if(!locks.contains(neighbor)){
				if(neighbor->getMutex()->tryLock())
					locks << t->getNeighbor(i);
				else
					break;
			}
		}
	}
	if(i!=3){
		return false;
	} else {
		return true;
	}
}

void LeppBisectionThread::unlockAll(){
	QSetIterator<Triangle*> i(locks);
	 while (i.hasNext()) {
	     i.next()->getMutex()->unlock();
	 }
	 locks.clear();
}

void LeppBisectionThread::removeFromLockCount(Triangle *t){
	locks.remove(t);
}

Vertex * LeppBisectionThread::fetchNewVertex(int id, Point2F p){
	//return vp->fetchVertex(id,p);
	return new Vertex(id,p);
}

Triangle * LeppBisectionThread::fetchNewTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v3){
	//return tp->fetchTriangle(id,v1,v2,v3);
	return new Triangle(id,v1,v2,v3);
}

void LeppBisectionThread::addVertexToMesh(Vertex *v){
	_mesh->addVertex(v);
}

void LeppBisectionThread::addTriangleToMesh(Triangle *t){
	_mesh->addTriangle(t);
}

void LeppBisectionThread::finalizeTriangle(Triangle *t){
	//writeLog(QString("finalizeTriangle(") + QString::number(t->getId()) + QString(") 1"));
	_clb->removeFromPending(t);
	//writeLog(QString("finalizeTriangle(") + QString::number(t->getId()) + QString(") 2"));
	_mesh->destroyTriangle(t);
	//writeLog(QString("finalizeTriangle() 3"));
}
