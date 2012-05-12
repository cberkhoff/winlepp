#include "refinementalgorithm.h"
#include <QtCore/QMap>

RefinementAlgorithm::RefinementAlgorithm(Mesh *m){
	mesh = m;
	done = 0;
}

RefinementAlgorithm::RefinementAlgorithm(Mesh *m,SelectionCriterion *c)
{
	mesh = m;
	QMap<int,Triangle *>::iterator mesh_it;
	for(mesh_it = m->getTriangles()->begin();mesh_it != m->getTriangles()->end();mesh_it++){
		Triangle *t = mesh_it.value();
		if(c->isSelected(t)){
			work_set.insert(t,true);
		}
	}
	total = work_set.size();
	done = 0;
}

RefinementAlgorithm::~RefinementAlgorithm()
{
}

void RefinementAlgorithm::run(){
	processMesh();
}

void RefinementAlgorithm::removeFromPending(Triangle *t){
	if(work_set.contains(t)){
		work_set[t] = false;
		done++;
	}
}
