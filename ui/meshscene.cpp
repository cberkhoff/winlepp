#include "meshscene.h"
#include <QtGlobal>
#include "adaptertriangleitem.h"

MeshScene::MeshScene(QObject *parent) : QGraphicsScene(parent){
}

MeshScene::~MeshScene(){
	QList<QGraphicsItem *> atis = items();
	QList<QGraphicsItem *>::iterator gi_i;
	for(gi_i = atis.begin(); gi_i != atis.end(); gi_i++){
		AdapterTriangleItem * ati = (AdapterTriangleItem *)*gi_i;
		delete ati;
	}
}

void MeshScene::createScene(Mesh *m){
	QMap<int,Triangle*>::iterator tIterator;
	for(tIterator = m->getTriangles()->begin(); tIterator != m->getTriangles()->end(); tIterator++){
		Triangle *t = tIterator.value();
		AdapterTriangleItem *ati = new AdapterTriangleItem(t,this);
		addItem(ati);
	}
}

QList<int> MeshScene::getSelectedTriangles(){
	return selectedTriangles;
}

void MeshScene::addSelectedTriangleId(int triangleId){
	selectedTriangles.push_back(triangleId);
}

void MeshScene::removeSelectedTriangleId(int triangleId){
	int pos = selectedTriangles.indexOf(triangleId);
	Q_ASSERT(pos!=-1);
	selectedTriangles.removeAt(pos);
}

void MeshScene::unselectAll(){
	QList<QGraphicsItem *> atis = items();
	QList<QGraphicsItem *>::iterator gi_i;
	for(gi_i = atis.begin(); gi_i != atis.end(); gi_i++){
		AdapterTriangleItem * ati = (AdapterTriangleItem *)*gi_i;
		if(ati->isSelected())
			ati->setUnselected();
	}
}

void MeshScene::selectUsingCriterion(SelectionCriterion *sc){
	QList<QGraphicsItem *> atis = items();
	QList<QGraphicsItem *>::iterator gi_i;
	for(gi_i = atis.begin(); gi_i != atis.end(); gi_i++){
		AdapterTriangleItem * ati = (AdapterTriangleItem *)*gi_i;
		if(sc->isSelected(ati->triangle))
			if(!ati->isSelected())
				ati->setSelected();
	}
}
