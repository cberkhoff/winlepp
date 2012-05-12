#ifndef REFINEMENTALGORITHM_H_
#define REFINEMENTALGORITHM_H_

#include "../selectioncriterions/selectioncriterion.h"
#include "../../geom/mesh.h"
#include "../../geom/triangle.h"
#include <QtCore/QMap>
#include <QtCore/QThread>

/*!
 * Clase que define los marcos generales de un algoritmo de refinamiento. Esta clase forma parte
 * del patron Strategy utilizado para tener diversos tipos de algoritmos de refinamiento
 */
class RefinementAlgorithm : public QThread
{
	Q_OBJECT
protected:
	/*!
	 * Puntero a la malla sobre la cual se va a trabajar
	 */
	Mesh *mesh;
	/*!
	 * Lista de trabajo. Es un map para realizar las operaciones de busqueda más rapidamente
	 */
	QMap<Triangle *,bool> work_set;
	/*!
	 * Entero que contiene el progreso actual
	 */
	int done;
	/*!
	 *  Contiene el tamaño de la lista de trabajo
	 */
	int total;
	/*!
	 * Metodo abstracto que debe ser implementado por la estrategia de refinamiento para
	 * refinar la malla (atender los elementos de la lista de trabajo)
	 */
	virtual void processMesh()=0;
	/*!
	 * Metodo generico para eliminar elementos de la cola de trabajo
	 */
	virtual void removeFromPending(Triangle *t);
public:
	RefinementAlgorithm(Mesh *m);
	/*!
	 * Constructor general de un algoritmo de refinamiento
	 */
	RefinementAlgorithm(Mesh *m,SelectionCriterion *c);
	/*!
	 * Destructor
	 */
	virtual ~RefinementAlgorithm();
	/*!
	 * Ejecuta el refinamiento llamando a la funcion run()
	 */
	void run();
	/*!
	 * Obtiene el total de elementos a refinar, es decir el tamañod e la lista de trabajo
	 */
	int getTotal(){
		return total;
	}
	/*!
	 * Obtiene el numero de triangulos que han sido refinados actualmente
	 */
	virtual int getDone(){
		return done;
	}
};

#endif /*REFINEMENTALGORITHM_H_*/
