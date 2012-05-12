#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include <iostream>
#include <string>

/*!
 * Clase que representa una arista. Tiene un identificador y 2 puntos
 */
class Edge
{
/*!
 * Imprime la arista en el output stream
 */
friend std::ostream& operator<< (std::ostream& out, const Edge& a);
protected:
	/*!
	 * Arreglo con los punteros a los dos vertices
	 */
	Vertex* v[2];
	/*!
	 * Constructor prohibido, debe tener al menos un identificador definido
	 */
	Edge();
public:
	/*!
	 * Constructor General
	 * \param _v1 Primer vertice
	 * \param _v2 Segundo vertice
	 */
	Edge(Vertex* _v1, Vertex* _v2);
	/*!
	 * Devuelve un nuevo punto que es el que se encuentra en el centro geometrico de la arista
	 */
	const Point2F midPoint() const;
	/*!
	 * Obtiene el vertice 1 (>+1&<2)
	 */
	Vertex* getVertex(int i) const;
	/*!
	 * Revisa si la arista tiene el Vertice fijandose en el puntero
	 */
	bool hasVertex(Vertex *v1) const;
	/*!
	 * Revisa si la arista tiene el Vertice fijandose en los indentificadores
	 */
	bool hasVertexId(Vertex *v1) const;
	/*!
	 * Comprueba equivalencia entre aristas fijandose en los identificadores de los vertices
	 */
	bool sameVertexsId(Edge *e) const;
	/*!
	 * devuelve un float con el largo de la arista
	 */
	float size() const;
	/*!
	 * Chequea el invariante de la arista
	 */
	bool invariante() const;
	/*!
	 * Devuelve la representacionde string de la arista
	 */
	std::string toString() const;
};

#endif // EDGE_H
