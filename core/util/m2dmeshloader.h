#ifndef M2DMESHLOADER_H_
#define M2DMESHLOADER_H_

#include "meshloader.h"
#include <QtCore/QMap>

/*!
 * Define como cargar archivos del tipo M2D
 */
class M2DMeshLoader : public MeshLoader
{
public:
	/*!
	 * Implementacion del metodo load para cargar mallas desde archivos con el formato
	 * m2d
	 */
	Mesh * load(const char* filename);
};

#endif /*M2DMESHLOADER_H_*/
