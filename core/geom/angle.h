#ifndef ANGLE_H_
#define ANGLE_H_

#include <iostream>
#include <string>

#define PI 3.141592653589

/*!
 * Clase auxiliar utilizada para trabajar con angulos
 */
class Angle
{
/*!
 * Imprime el valor del en grados angulo de la forma A°
 */
friend std::ostream& operator<< (std::ostream& out, const Angle& p);
protected:
	/*!
	 * Valor interno del angulo representado en radianes
	 */
	float alfa;
	/*!
	 * Se encarga de mantener el valor entre 0 y 2*PI
	 */
	void normalize();
public:
	/*!
	 * Constructor vacio de un angulo. angulo igual a cero
	 */
	Angle();
	/*!
	 * Constructor basico que recibe el angiulo en radianes
	 */
	Angle(float alfa);
	/*!
	 * Constructor por copia
	 */
	Angle(const Angle& a);
	/*!
	 * Destructor
	 */
	virtual ~Angle();
	/*!
	 * Obtiene el angulo en radianes
	 */
	float getInRadians() const;
	/*!
	 * Establece el angulo en radianes
	 */
	void setInRadians(float a);
	/*!
	 * Obtiene el angulo en grados
	 */
	float getInDegrees() const;
	/*!
	 * Establece el angulo en grados
	 */
	void setInDegrees(float a);
	/*!
	 * Operador de suma de angulos
	 */
	const Angle operator+(const Angle &a) const;
	/*!
	 * Operador de resta de angulos
	 */
	const Angle operator-(const Angle &a) const;
	/*!
	 * Operador de ponderacion de angulos
	 */
	const Angle operator*(float f) const;
	/*!
	 * Operador mayor que
	 */
	bool operator>(const Angle &a) const;
	/*!
	 * Operador menor que
	 */
	bool operator<(const Angle &a) const;
	/*!
	 * obtiene la representacion en string de un angulo
	 */
	std::string toString() const ;
};

#endif /*ANGLE_H_*/
