#include "adaptertriangleitem.h"
#include "meshscene.h"
#include <iostream>
#include <QtGui>

AdapterTriangleItem::AdapterTriangleItem(Triangle * _triangle,MeshScene *_p) : QGraphicsPolygonItem()
{
	triangle = _triangle;
	parent = _p;
	QPolygonF myPolygon;
	myPolygon << QPointF(triangle->getVertex(0)->getX(),triangle->getVertex(0)->getY());
	myPolygon << QPointF(triangle->getVertex(1)->getX(),triangle->getVertex(1)->getY());
	myPolygon << QPointF(triangle->getVertex(2)->getX(),triangle->getVertex(2)->getY());
	myPolygon << QPointF(triangle->getVertex(0)->getX(),triangle->getVertex(0)->getY());
	setPolygon(myPolygon);
	selected = false;
	ColorSelected = QColor(112, 171, 107, 255);
	ColorUnselected = QColor(204, 204, 204, 255);
	setBrush(QBrush(ColorUnselected));
	setToolTip(QString("Triangulo ")+QString::number(triangle->getId()));
}

void AdapterTriangleItem::setSelected(){
	setBrush(QBrush(ColorSelected));
	selected = true;
	parent->addSelectedTriangleId(triangle->getId());
}

void AdapterTriangleItem::setUnselected(){
	setBrush(QBrush(ColorUnselected));
	selected = false;
	parent->removeSelectedTriangleId(triangle->getId());
}

void AdapterTriangleItem::mousePressEvent(QGraphicsSceneMouseEvent *e){
	if(isSelected()){
		setUnselected();
	}else{
		setSelected();
	}
}

bool AdapterTriangleItem::isSelected(){
	return selected;
}
