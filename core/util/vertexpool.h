#ifndef VERTEXPOOL_H_
#define VERTEXPOOL_H_

#include "../geom/vertex.h"
#include "../geom/point2F.h"
#include "pool.h"
#include <iostream>

/*!
 * Esta clase extiene dpool a fin de tener un pozo de vertices
 */
class VertexPool : public Pool<Vertex>
{
protected:
	/*!
	 * Inicializa los vertices con valores Dummy
	 */
	virtual void initialize(){
		//std::cout << "Rellenando lista de vertices" << std::endl;
		for(int i=0;i<size;i++)
			pool[i] = new Vertex(-1,-1,-1);
	};
public:
	/*!
	 * Constructor
	 * \param size tamaño del pozo
	 */
	VertexPool(int s) : Pool<Vertex>(s){};
	/*!
	 * Obtiene un vertice del pozo y define sus variables como si fuese construido
	 */
	Vertex * fetchVertex(int id,const Point2F &p){
		Vertex *v = fetch();
		v->setId(id);
		v->setX(p.getX());
		v->setY(p.getY());
		return v;
	};
};

#endif /*VERTEXPOOL_H_*/
