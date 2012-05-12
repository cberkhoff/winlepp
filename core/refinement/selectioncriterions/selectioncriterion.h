#ifndef SELECTIONCRITERION_H_
#define SELECTIONCRITERION_H_

#include "../../geom/triangle.h"

/*!
 * Clase base que define los metodos necesarios para definir un criterio de seleccion.
 * Esta clase forma parte del patron Strategy (distintas estrategias de seleccion de
 * triangulos).
 */
class SelectionCriterion
{
public:
	/*!
	 * Metodo que sirve para preguntar si un triangulo en cuestion debe ser refinado o no
	 */
	virtual bool isSelected(Triangle *t)=0;
};

#endif /*SELECTIONCRITERION_H_*/
