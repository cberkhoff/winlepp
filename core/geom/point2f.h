#ifndef POINT2F_H
#define POINT2F_H

#include <iostream>
#include <string>

/*!
 * Punto en 2D. X e Y son flotantes
 */
class Point2F
{
/*!
 * Imprime el punto de la forma (X,Y)con 2 decimales
 */
friend std::ostream& operator<< (std::ostream& out, const Point2F& p);
protected:
/*!
 * Variable protegidas con las coordenadas del punto
 */
	float x,y;
public:
/*!
 * Construye un punto con coordenadas (0,0)
 */
	Point2F();
/*!
 * Construye un punto tomando los paramentros
 * \param _x coordenada X
 * \param _y coordenada Y
 */
	Point2F(float _x,float _y);
/*!
 * Constructor por copia de otro punto
 */
	Point2F(const Point2F& p);
/*!
 * Obtiene coordenada X
 */
	float getX() const;
/*!
 * Obtiene coordenada Y
 */
	float getY() const;
/*!
 * Establece la coordenada X
 * \param _x nueva coordenada X
 */
	void setX(float _x);
/*!
 * Establece la coordenada Y
 * \param _y nueva coordenada Y
 */
	void setY(float _y);
/*!
 * Suma dos puntos de la forma estandar y devuelve el nuevo
 * \param p El otro punto
 */
	const Point2F operator+(const Point2F &p) const;
/*!
 * Resta dos puntos y devuelve la diferencia en un nuevo punto
 * \param p El otro punto
 */
	const Point2F operator-(const Point2F &p) const;
/*!
 * Pondera el punto con un flotante
 * \param f factor por el cual se pondera
 */
	const Point2F operator*(const float &f) const;
/*!
 * Devuelve el cuadrado de la distancia Euclidiana, mas rapido si solo se quiere
 * ordenar
 * \param p El otro punto
 */
	float distanceSquare(const Point2F &p) const;
/*!
 * devuelve la distancia eucliniana de 2 puntos
 * \param p El otro punto
 */
	float distance(const Point2F &p) const;
/*!
 * Devuelve la representacion como string del punto
 */
	std::string toString() const ;
};

#endif // POINT2F_H
