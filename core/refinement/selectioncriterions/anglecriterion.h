#ifndef ANGLECRITERION_H_
#define ANGLECRITERION_H_

#include "subsetidcriterion.h"
#include "../../geom/mesh.h"
#include <QtCore/QMap>

/*!
 * Criterio de seleccion basado en el tamaño de los angulos
 */
class AngleCriterion : public SubSetIdCriterion
{
protected:
	/*!
	 * Funcion auxiliar que retorna la distancia
	 */
	float maximumDistanceTo60Degrees(Triangle *t);
public:
	/*!
	 * Constructor del criterio
	 */
	AngleCriterion(float topDistance, Mesh *m);
	/*!
	 * Destructor
	 */
	virtual ~AngleCriterion(){};
};

#endif /*ANGLECRITERION_H_*/
