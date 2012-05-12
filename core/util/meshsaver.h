#ifndef MESHSAVER_H_
#define MESHSAVER_H_

#include "../geom/mesh.h"

/*!
 * Clase que define la interfaz para guardar mallas en archivos de distintos formatos
 */
class MeshSaver{
public:
	/*!
	 * Firma del metodo utilizado para guardar mallas
	 * \param m Malla a guardar
	 * \param filename Nombre (y direccion) del archivo en el cual se almacenara la malla
	 */
	virtual void save(Mesh *m, const char* filename)=0;
};

#endif /*MESHSAVER_H_*/
