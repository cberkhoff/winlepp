#ifndef LEPPBISECTIONTEMPLATE_H_
#define LEPPBISECTIONTEMPLATE_H_

#include "../../geom/triangle.h"
#include "../../geom/vertex.h"
#include "../../geom/edge.h"
#include "../../geom/mesh.h"
#include "../../geom/point2f.h"

/*!
 * Esta clase define los metodos processTriangle y refineTriangle que son utilizados por
 * todos los algoritmos que quieran seguir la estrategia Longest Edge Propagation Path
 * (Lepp). Se dejan sin definir metodos que resulta conveniente modificar dependiendo
 * del escenario.
 */
class LeppBisectionTemplate
{
protected:
	/*!
	 * Estructura interna que define que tipo de vertice poseen los triangulos que van a
	 * ser refinados
	 */
	enum {FIRST_NON_SHARED=0,SECOND_NON_SHARED=1,SHARED=2};
	/*!
	 * Estructura interna utilizada para representar el triangulo actual del Lepp (T) o bien
	 * el siguiente (U)
	 */
	enum {T=0,U=1};
	/*!
	 * Prueba para revisar que los vertices seleccionados esten bien definidos
	 */
	bool vertexTest(Vertex * vertexes[][3], Triangle *);
	/*!
	 * Procesa un triangulo y refina todo el camino marcado por el lepp (queda almacenado en
	 * el stack recursivo de llamadas). Lllama al metodo refineTriangle para cortar los triangulos
	 * en 2.
	 */
	virtual bool processTriangle(Triangle *t);
	/*!
	 * Procedimiento encargado de cortar los triangulos. El primer triangulo (T) debe estar
	 * definido y el segundo (U) es opcional
	 */
	virtual void refineTriangle(Triangle *t, Triangle *u);
	/*!
	 * Metodo virtual que debe ser implementado por los algoritmos que quieran utilizar este
	 * template. Se debe definir como se creara un nuevo vertice
	 */
	virtual Vertex * fetchNewVertex(int id, Point2F p)=0;
	/*!
	 * Metodo virtual que debe ser implementado por los algoritmos que quieran utilizar este
	 * template. Se debe definir como se creara un nuevo triangulo
	 */
	virtual Triangle * fetchNewTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v3)=0;
	/*!
	 * Metodo virtual que debe ser implementado por los algoritmos que quieran utilizar este
	 * template. Se debe definir como se agregara el vertice a la malla
	 */
	virtual void addVertexToMesh(Vertex *)=0;
	/*!
	 * Metodo virtual que debe ser implementado por los algoritmos que quieran utilizar este
	 * template. Se debe definir como se agregara el triangulo a la malla
	 */
	virtual void addTriangleToMesh(Triangle *)=0;
	/*!
	 * Metodo virtual que debe ser implementado por los algoritmos que quieran utilizar este
	 * template. Se debe definir como borrar el triangulo.
	 */
	virtual void finalizeTriangle(Triangle *)=0;
};

#endif /*LEPPBISECTIONTEMPLATE_H_*/
