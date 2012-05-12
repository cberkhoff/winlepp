#ifndef SELECTALLCRITERION_H_
#define SELECTALLCRITERION_H_

#include "selectioncriterion.h"

/*!
 * Criterio de seleccion simple que acepta todos los triangulos
 */
class SelectAllCriterion : public SelectionCriterion
{
public:
	/*!
	 * Este metodo retorna verdadero apra todos los triangulos, añadiendolos todos a la
	 * cola de procesamiento
	 */
	inline virtual bool isSelected(Triangle *t){ return true; };
};

#endif /*SELECTALLCRITERION_H_*/
