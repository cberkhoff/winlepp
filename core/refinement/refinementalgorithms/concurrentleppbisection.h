#ifndef CONCURRENTLEPPBISECTION_H_
#define CONCURRENTLEPPBISECTION_H_

#include "refinementalgorithm.h"
#include "leppbisectionthread.h"
#include <QtCore/QMutex>
#include <QMutableMapIterator>

class LeppBisectionThread;

/*!
 * Algoritmo de refinamiento de triangulos que implementa una estrategia de refinamiento
 * concurrente a travez de LeppBisectionThreads que se encargan de ir refinando la malla.
 * Esta clase es el ente coordinador.
 */
class ConcurrentLeppBisection : public RefinementAlgorithm
{
protected:
	/*!
	 * Mutex para trabajo con memoria distribuida. Protege la lista de trabajo y
	 * las estructuras anexas del algoritmo de refinamiento
	 */
	mutable QMutex mutex;
	/*!
	 * Trabajadores
	 */
	LeppBisectionThread** workers;
	int n_threads;
	QMutableMapIterator<Triangle *,bool> work_set_iterator;
public:
	/*!
	 * Constructor de la estrategia de refinamiento concurrente
	 */
	ConcurrentLeppBisection(Mesh *m,SelectionCriterion *c);
	/*!
	 * destructor
	 */
	virtual ~ConcurrentLeppBisection();
	/*!
	 * Se redefinio este metodo ya que el numero de triangulos procesados es una seccion critica
	 */
	int getDone();
	/*!
	 * Metodo auxiliar para eliminar triangulos de la lista de trabajo
	 */
	void removeFromPending(Triangle *t);
	/*!
	 * procesa la malla utilizando esta estrategia
	 */
	virtual void processMesh();
	void checkedNext();
	Triangle * getNext();
};

#endif /*CONCURRENTLEPPBISECTION_H_*/
