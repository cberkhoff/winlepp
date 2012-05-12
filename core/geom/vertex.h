#ifndef VERTEX_H
#define VERTEX_H

#include "point2f.h"
#include <iostream>
#include <string>

/*!
 * Extension de vertice que añade un ID. Es tratado distinto ya que punto es un concepto topografico
 * y los vertices son usados normalmente para la identificación de puntos de inflexión de una
 * poligonal, centro de curvas, principio de curvas y/o tangentes y demás puntos geométricos que
 * definen una poligonal.
 */
class Vertex : public Point2F
{
/*!
 * Imprime el vertice de la siguiente forma V_<ID> Point2F
 */
friend std::ostream& operator<< (std::ostream& out, const Vertex& v);
protected:
//TODO: poner un identificador unsigned long long
/*!
 * identificador del vertice
 */
	int id;
/*!
 * Constructor prohibido, los vertices debe tener un indicador
 */
	Vertex();
public:
/*!
 * Constructor general
 * \param _id identificador
 * \param x coordenada X del punto
 * \param y coordenada Y del punto
 */
	Vertex(int _id, float x, float y);
/*!
 * Constructor que recibe punto
 * \param _id identificador
 * \param p Punto para construir por copia
 */
	Vertex(int _id, const Point2F &p);
/*!
 * Devuelve la representacion en string del vertice
 */
	std::string toString() const;
/*!
 * Obtiene el ID del vertice
 */
	int getId() const;
/*!
 * Establece el ID del vertice
 */
	void setId(int _id);
};

#endif // VERTEX_H
