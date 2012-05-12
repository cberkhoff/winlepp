#include "leppbisectiontemplate.h"
#include <QtGlobal>

bool LeppBisectionTemplate::processTriangle(Triangle *t){
	Q_ASSERT(t!=0);
	bool working = true;
	while(working){
		//obtengo el vecino por la arista mas larga, u
		Triangle *u = t->getNeighbor(t->longestEdgeIndex());
		//si es nulo estoy en el borde, corto nomas
		if(u==0){
			refineTriangle(t,0);
			working = false;
		} else {
			//si comparten la arista mas larga entonces corto
			Edge e_u = u->getEdge(u->longestEdgeIndex());
			Edge e_t = t->getEdge(t->longestEdgeIndex());
			if(e_u.sameVertexsId(&e_t))
			{
				refineTriangle(t,u);
				working = false;
			}
			else
			{
				processTriangle(u);
			}
		}
	}
	return true;
}

void LeppBisectionTemplate::refineTriangle(Triangle *t, Triangle *u){
	Triangle* originals[2];
	originals[T] = t;
	originals[U] = u;

	//organizo los vertices de los triangulos
	Vertex* vertexes[2][3];
	int aux_t_longest_edge = t->longestEdgeIndex();
	vertexes[T][SHARED] = t->getVertex(aux_t_longest_edge);
	vertexes[T][FIRST_NON_SHARED] = t->getVertex((aux_t_longest_edge+1)%3);
	vertexes[T][SECOND_NON_SHARED] = t->getVertex((aux_t_longest_edge+2)%3);
	if(u!=0){
		int aux_u_longest_edge = u->longestEdgeIndex();
		vertexes[U][SHARED] = u->getVertex(aux_u_longest_edge);
		vertexes[U][FIRST_NON_SHARED] = vertexes[T][FIRST_NON_SHARED];
		vertexes[U][SECOND_NON_SHARED] = vertexes[T][SECOND_NON_SHARED];
	}

	//pruebas
	//Q_ASSERT(vertexTest(vertexes,u));

	//creo nuevo vertice
	Edge e_t = t->getEdge(t->longestEdgeIndex());
	Vertex *new_vertex = fetchNewVertex(-1,e_t.midPoint());
	addVertexToMesh(new_vertex);

	//creo los nuevos triangulos
	Triangle* new_triangles[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(i==U&&u==0){
				new_triangles[i][j] = 0;
			} else {
				new_triangles[i][j] = fetchNewTriangle(
						-1,
						vertexes[i][SHARED],
						new_vertex,
						vertexes[i][j]);
				addTriangleToMesh(new_triangles[i][j]);
			}
		}
	}

	//arreglo los vecinos
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(!(i==U&&u==0)){
				//defino sus vecinos
				Triangle *new_neighbor = originals[i]->getNeighborOposedToVertex(vertexes[i][(j+1)%2]);
				new_triangles[i][j]->setNeighbors(
						new_triangles[(i+1)%2][j],
						new_neighbor,
						new_triangles[i][(j+1)%2]);
				//arreglo el vecino del nuevo triangulo
				if(new_neighbor!=0)
					new_neighbor->replaceNeighbor(originals[i],new_triangles[i][j]);
			}
		}
	}

	finalizeTriangle(t);
	if(u!=0){
		finalizeTriangle(u);
	}
}

bool LeppBisectionTemplate::vertexTest(Vertex * vertexes[][3], Triangle *u){
	for(int k=0;k<(u==0?1:2);k++){
		for(int i=0;i<3;i++){
			for(int j=0;j<i;j++){
				if(vertexes[k][i]!=vertexes[k][j])
					return false;
				if(vertexes[k][i]->getId()!=vertexes[k][j]->getId())
					return false;
			}
		}
	}
	if(vertexes[T][FIRST_NON_SHARED]!=vertexes[T][SECOND_NON_SHARED])
		return false;
	if(vertexes[T][FIRST_NON_SHARED]->getId()!=vertexes[T][SECOND_NON_SHARED]->getId())
		return false;
	if(u!=0){
		if(vertexes[T][SHARED]!=vertexes[U][SHARED])
			return false;
		if(vertexes[T][SHARED]->getId()!=vertexes[U][SHARED]->getId())
			return false;
	}
	return true;
}
