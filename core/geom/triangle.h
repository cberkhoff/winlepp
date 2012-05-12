#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "edge.h"
#include "angle.h"
#include <iostream>
#include <string>
#include <QtCore/QMutex>
#include <QtCore/QWaitCondition>
#include <QtCore/QTextStream>

/*!
 * Representa un triangulo.
 * Las aristas estan opuestas a los vertices
 * los triangulos vecinos tambien
 */
class Triangle
{
	/*!
	 * Imprime el triangulo en el output stream
	 */
friend std::ostream& operator<< (std::ostream& out, const Triangle& t);
protected:
	//TODO: poner un identificador unsigned long long
	/*!
	 * Identificador por si se trabaja con memoria distribuida
	 */
	int id;
	/*!
	 * Arreglo de punteros a los vertices
	 */
	Vertex* vertexs[3];
	/*!
	 * Arreglo con punteros a los triangulos vecinos
	 */
	Triangle* neighbors[3];
	/*!
	 * Constructor Prohibido
	 */
	Triangle();
	/*!
	 * Mutex para trabajo con memoria compartida
	 */
	mutable QMutex mutex;
	/*!
	 * Mutex para trabajo con memoria compartida. Protege el arreglo de triangulos vecinos
	 */
	//mutable QMutex internalMutex;
	/*!
	 * Condicion de espera a que cambie un elemento del arreglod e vecinos
	 */
	//QWaitCondition neighborChanged;
public:
	/*!
	 * Constructor más general. Recibe todos losa rgumentos necesarios.
	 * \param _id identificador del triangulo
	 * \param v1 primer vertice
	 * \param v2 segundo vertice
	 * \param v3 tercer vertice
	 */
	Triangle(int _id, Vertex *v1, Vertex *v2, Vertex *v3);
	/*!
	 * Constructor por copia
	 */
	Triangle(const Triangle &t);
	/*!
	 * Obtiene el Id del triangulo
	 */
	int getId() const;
	/*!
	 * Establece el ID del triangulo
	 */
	void setId(int _id);
	/*!
	 * Crea una nueva arista i. i>-1 y <4. Recordar destruir la arista.
	 */
	Edge getEdge(int i) const;
	/*!
	 * Chequea que la arista exista dentro del triangulo fijandose en los ids
	 * de los vertices
	 */
	bool hasEdge(const Edge *e) const;
	/*!
	 * Obtiene el vertice i. i>-1 y <4
	 */
	Vertex* getVertex(int i) const;
	/*!
	 * Establece el vertice i. i>-1 y <4
	 */
	void setVertex(int i,Vertex *v);
	/*!
	 * Devuelve el indice de la arista mas larga.
	 */
	int longestEdgeIndex() const;
	/*!
	 * Establece los triangulos vecinos. Se espera que cada triangulo comparta una arista (y dos vertices).
	 * Los triangulos corresponden a los vertices, asi el triangulo vecino i esta opuesto al vertice i.
	 */
	void setNeighbors(Triangle *t1,Triangle *t2, Triangle *t3);
	/*!
	 * establece el vecino por la arista con indice i
	 */
	void setNeighbor(int i, Triangle *t);
	/*!
	 * Busca al vecino objective y lo reemplaza. Si no lo encuentra lanza un error
	 */
	void replaceNeighbor(Triangle *objective,Triangle *replacement);
	/*!
	 * Obtiene el Triangulo vecino por el indice de la arista edge_index.
	 */
	Triangle * getNeighbor(int edge_index) const;
	/*!
	 * Obtiene el Triangulo vecino opuesto al vertice ingresado
	 */
	Triangle * getNeighborOposedToVertex(Vertex *v) const;
	/*!
	 * Obtiene el angulo del vertice i.
	 */
	Angle getAngle(int i) const;
	/*!
	 * El invariante es:
	 * 1.-vertices no nulos
	 * 1.a.- son distintos
	 * 3.- si vecino no nulo
	 * 3.a.- revisa que este bien ordenado y conectado
	 */
	bool invariante() const;
	/*!
	 * Imprime la representacion del triangulo
	 */
	std::string toString() const;
	/*
	 * devuelve un puntero al mutex de este triangulo
	 */
	QMutex * getMutex();
	/*!
	 * Obtiene el Triangulo vecino por el indice de la arista edge_index. A diferencia de
	 * getNeighbor(int) este metodo primero intentara bloquear el acceso al triangulo vecino
	 * y modificara el estado del mutex neighborMutex() de este triangulo
	 */
	//Triangle *getLockedNeighbor(int edge_index);
	//Triangle *tryToGetNeighbor(int edge_index, bool *couldAcquire,QTextStream &log);
};

#endif // TRIANGLE_H
