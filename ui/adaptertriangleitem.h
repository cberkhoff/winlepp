#ifndef ADAPTERTRIANGLEITEM_H_
#define ADAPTERTRIANGLEITEM_H_

#include <QtGui/QGraphicsPolygonItem>
#include <QtGui/QGraphicsSceneMouseEvent>
#include "../core/geom/triangle.h"

class MeshScene;

/*!
 * Adaptador que une un objeto triangulo y un QGraphicsPolygonItem de la biblioteca QT.
 * Esta clase esta muy acoplada a MeshScene. Para enteneder mejor el funcionamiento de esta
 * es imperativo leer tambien MeshScene
 */
class AdapterTriangleItem : public QGraphicsPolygonItem
{
public:
	/*!
	 * Triangulo asociado
	 */
	Triangle *triangle;
	/*!
	 * Puntero a la escena que tiene este objeto
	 */
	MeshScene *parent;
	/*!
	 * Constructor basico
	 * \param _triangle triangulo a direccionar
	 * \param _p Meshscene que contendra a este triangulo
	 */
	AdapterTriangleItem(Triangle * _triangle, MeshScene * _p);
	/*!
	 * Devuelve si el triangulo esta seleccionado
	 */
	bool isSelected();
	/*!
	 * Selecciona el triangulo
	 */
	void setSelected();
	/*!
	 * Desselecciona el triangulo
	 */
	void setUnselected();
protected:
	/*!
	 * Color cuando el triangulo no esta seleccionado
	 */
	QColor ColorUnselected;
	/*!
	 * Colo cuando el triangulo esta seleccionado
	 */
	QColor ColorSelected;
	/*!
	 * Variable interna que indica el estado de seleccion del triangulo
	 */
	bool selected;
	/*!
	 * Evento capturado para cambiar el estado del triangulo. Overloadeado
	 */
	virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif /*ADAPTERTRIANGLEITEM_H_*/
