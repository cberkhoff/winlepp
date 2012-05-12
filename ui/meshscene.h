#ifndef GRAPHICSCENE_H_
#define GRAPHICSCENE_H_

#include <QtGui/QGraphicsScene>
#include <QtCore/QList>
#include "../core/geom/mesh.h"
#include "../core/refinement/selectioncriterions/selectioncriterion.h"

class AdapterTriangleItem;

/*!
 * Objeto que desctibe la interfaz donde se muestra los triangulos graficos (AdapterTriangleItem's)
 */
class MeshScene : public QGraphicsScene
{
	Q_OBJECT
signals:
	/*!
	 * Señal que es emitida cuando cambia la seleccion de triangulos
	 */
	void selectionChanged();
protected:
	/*!
	 * Lista interna con los IDs de los triangulos seleccionados
	 */
	QList<int> selectedTriangles;
public:
	/*!
	 * Constructor
	 */
	MeshScene(QObject *parent = 0);
	/*!
	 * Destructor, destruye los AdapterTriangleItem's asociados
	 */
	virtual ~MeshScene();
	/*!
	 * Crea una escena grafica con los triangulos que se le entrega
	 */
	void createScene(Mesh *m);
	/*!
	 * Obtiene un QList con los ID´s de los triangulos seleccionados
	 */
	QList<int> getSelectedTriangles();
	/*!
	 * Añade un triangulo a la lista de triangulos seleccionados
	 */
	void addSelectedTriangleId(int triangleId);
	/*!
	 * Remueve un triangulo de la lista de triangulos seleccionados
	 */
	void removeSelectedTriangleId(int triangleId);
	/*!
	 * Deselecciona todos los AdapterTriangleItem's
	 */
	void unselectAll();
	/*!
	 * Selecciona los triangulos que pasen el criterio de seleccion
	 */
	void selectUsingCriterion(SelectionCriterion *sc);
};

#endif /*GRAPHICSCENE_H_*/
