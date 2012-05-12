#ifndef LEPPBISECTION_H_
#define LEPPBISECTION_H_

#include "refinementalgorithm.h"
#include "leppbisectiontemplate.h"
#include "../../geom/triangle.h"

/*!
 * Algoritmo de refinamiento de triangulos que implementa una estrategia de refinamiento
 * y ademas sigue el template de un algoritmo de lepp biseccion. Este caso particular es
 * un metodo que utiliza solo el thread principal.
 */
class LeppBisection : public RefinementAlgorithm, public LeppBisectionTemplate
{
protected:
	/*!
	 * Define la forma en que se obtendra un nuevo vertice. En este caso esto corresponde
	 * a solo hacer un new
	 */
	Vertex * fetchNewVertex(int id, Point2F p);
	/*!
	 * Define la forma en que se obtendra un nuevo triangulo. En este caso es solo un simple new
	 */
	Triangle * fetchNewTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v2);
	/*!
	 * Define la forma en que se se agregaran vertices al mesh. Simplemente se insertan.
	 */
	void addVertexToMesh(Vertex *);
	/*!
	 * Define la forma en que se se agregaran triangulos al mesh.
	 */
	void addTriangleToMesh(Triangle *);
	/*!
	 * Realiza ultima operaciones de eliminacion sobre el triangulo. Lo elimina de la malla
	 *  y luego lo elimina de la lista de trabajo
	 */
	void finalizeTriangle(Triangle *);
	/*!
	 * Refina la malla
	 */
	virtual void processMesh();
public:
	/*!
	 * Constructor de la estrategia de refinamiento que utiliza lepp biseccion
	 */
	LeppBisection(Mesh *m,SelectionCriterion *c);
};

#endif /*LEPPBISECTION_H_*/
