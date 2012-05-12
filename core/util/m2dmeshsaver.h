#ifndef M2DMESHSAVER_H_
#define M2DMESHSAVER_H_

#include "meshsaver.h"

/*!
 * Clase que implementa el guardado de mallas en archivos M2D
 */
class M2DMeshSaver : MeshSaver
{
public:
	/*!
	 * Este metodo guarda la malla en el archivo indicado
	 */
	virtual void save(Mesh *m, const char* filename);
};

#endif /*M2DMESHSAVER_H_*/
