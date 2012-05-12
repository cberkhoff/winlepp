#include "leppbisection.h"

LeppBisection::LeppBisection(Mesh *m,SelectionCriterion *c) : RefinementAlgorithm(m,c)
{
}

void LeppBisection::processMesh(){
	QMap<Triangle *,bool>::iterator work_set_it;
	//por cada triangulo seleccionado voy secuencialmente
	for(work_set_it=work_set.begin();work_set_it!=work_set.end();work_set_it++){
		// si tiene el triangulo

		if(work_set_it.value()){
			processTriangle(work_set_it.key());
		}
		//caso contrario asumo que fue cortado
	}
}

Vertex * LeppBisection::fetchNewVertex(int id, Point2F p){
	return new Vertex(id,p);
}

Triangle * LeppBisection::fetchNewTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v3){
	return new Triangle(id,v1,v2,v3);
}

void LeppBisection::addVertexToMesh(Vertex *v){
	mesh->addVertex(v);
}

void LeppBisection::addTriangleToMesh(Triangle *t){
	mesh->addTriangle(t);
}

void LeppBisection::finalizeTriangle(Triangle *t){
	removeFromPending(t);
	mesh->destroyTriangle(t);
}

