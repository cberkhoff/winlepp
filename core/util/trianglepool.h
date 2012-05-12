#ifndef TRIANGLEPOOL_H_
#define TRIANGLEPOOL_H_

#include "../geom/triangle.h"
#include "../geom/vertex.h"
#include "pool.h"
#include <iostream>

/*!
 * Esta clase extiene la clase pool a fin de tener un pozo de triangulos
 */
class TrianglePool : public Pool<Triangle>
{
protected:
	/*!
	 * Vertices auxiliares creados para tener triangulos validos
	 */
	Vertex* emptyVertexs[3];
	/*!
	 * Inicializa los triangulos con valores Dummy
	 */
	virtual void initialize(){
		//std::cout << "Rellenando lista de triangulos" << std::endl;
		for(int i=0;i<size;i++)
			pool[i] = new Triangle(-1,emptyVertexs[0],emptyVertexs[1],emptyVertexs[2]);
	};
public:
	/*!
	 * Constructor
	 * \param size tamaño del pozo
	 */
	TrianglePool(int s) : Pool<Triangle>(s){
		for(int i=0;i<3;i++)
			emptyVertexs[i] = new Vertex(-(i+1),0,0);
	};
	/*!
	 * Destructor
	 */
	virtual ~TrianglePool(){
		for(int i=0;i<3;i++)
			delete emptyVertexs[i];
		delete[] emptyVertexs;
	};
	/*!
	 * Obtiene un triangulo del pozo y define sus variables como si fuese construido
	 */
	Triangle * fetchTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v3){
		Triangle *t = fetch();

		t->setId(id);
		t->setVertex(0,v1);
		t->setVertex(1,v2);
		t->setVertex(2,v3);

		return t;
	};
};

#endif /*TRIANGLEPOOL_H_*/
