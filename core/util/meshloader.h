#ifndef MESHLOADER_H_
#define MESHLOADER_H_

#include "../geom/mesh.h"

/*!
 * Clase que define la interfaz que utilizan todos los Cargadores de Mallas
 */
class MeshLoader{
public:
	/*!
	 * Definicion del metodo que debe ser implementado para cargar mallas de un formato
	 * especifico
	 * \param filename Direccion del archivo del cual se debe cargar la malla
	 */
	virtual Mesh * load(const char* filename) = 0;
};

#endif /*MESHLOADER_H_*/
