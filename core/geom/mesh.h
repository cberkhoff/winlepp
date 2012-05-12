#ifndef MESH_H
#define MESH_H

#include <QtCore/QMap>
#include <QtCore/QMutex>
#include "triangle.h"
#include <iostream>
#include <string>

/*!
 * Clase que almacena los arreglos de vertices y triangulos. Provee ademas logicas
 * basicas para asegurar la integridad de la malla
 */
class Mesh
{
	/*!
	 * Imprime la malla en el output stream
	 */
friend std::ostream& operator<< (std::ostream& out, const Mesh& m);
protected:
	/*!
	 * invariante a revisar
	 */
	bool invariante() const;
	/*!
	 * Almaceno la ID mas alta de los triangulo
	 */
	int TrianglesHighestId;
	/*!
	 * Almaceno la ID mas alta de los vectores
	 */
	int VertexsHighestId;
	/*!
	 * Mapa ID,Triangulo con los triangulos
	 */
	QMap<int,Triangle*> triangles;
	/*!
	 * Mapa ID, Vertice con los vertices
	 */
	QMap<int,Vertex*> vertexs;
	/*!
	 * Mutex para trabajo con memoria compartida
	 */
	mutable QMutex mutex;
public:
	/*!
	 * Constructor basico que inicia la malla vacia
	 */
	Mesh();
	/*!
	 * Destructor que destruye todos los vertices y triangulos
	 */
	virtual ~Mesh();
	/*!
	 * Obtiene la Id del triangulo mas alta presente en la malla
	 */
	int getTrianglesHighestId() const;
	/*!
	 * Obtiene la Id de vertice mas alta presente en la malla.
	 */
	int getVertexsHighestId() const;
	/*!
	 * Obtiene el triangulo i
	 */
	Triangle * getTriangle(int index);
	/*!
	 * Obtiene el vertice i de la malla
	 */
	Vertex* getVertex(int index);
	/*!
	 * Establece el triangulo i de la malla
	 */
	void setTriangle(int index, Triangle *t);
	/*!
	 * Establece el vertice i de la malla
	 */
	void setVertex(int index,Vertex *v);
	/*!
	 * Representacion como string de la malla
	 */
	std::string toString() const;
	/*!
	 * Añade un triangulo al final
	 */
	void addTriangle(Triangle *t);
	/*!
	 * Añade un vertice al final
	 */
	void addVertex(Vertex *v);
	/*!
	 * Destruye el triangulo especificado de la malla
	 */
	void destroyTriangle(Triangle *t);
	/*!
	 * Pregunta si el triangulo existe en la malla
	 */
	bool hasTriangle(Triangle *t);
	/*!
	 * Obtiene el mapa de triangulos
	 */
	QMap<int,Triangle *> * getTriangles();
	/*!
	 * Obtiene el mapa de vertices
	 */
	QMap<int,Vertex *> * getVertexs();
};

#endif // MESH_H
