#ifndef LEPPBISECTIONTHREAD_H_
#define LEPPBISECTIONTHREAD_H_

#include "leppbisectiontemplate.h"
#include "../../util/trianglepool.h"
#include "../../util/vertexpool.h"
#include "concurrentleppbisection.h"
#include <QtCore/QMutex>
#include <QtCore/QRunnable>

#include<QtCore/QSet>

#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QTextStream>

class ConcurrentLeppBisection;

class LeppBisectionThread : public LeppBisectionTemplate, public QRunnable
{
public:
	/*TrianglePool *tp;
	VertexPool *vp;*/
	LeppBisectionThread(ConcurrentLeppBisection *clb, Mesh *mesh, int expectedSize,int id);//, QString log_filename);
	virtual ~LeppBisectionThread();
	void run();
	int _id;
protected:
	//enum {DID_NOTHING=0,T_REFINED=1,T_U_REFINED=2};

	Mesh *_mesh;
	ConcurrentLeppBisection *_clb;
	//QFile _log_file;

	QSet<Triangle*> locks;

	//void writeLog(QString message);
	bool tryProcessTriangle(Triangle *t, int length);

	bool trylockNeighbors(Triangle* t);
	bool trylockTriangle(Triangle *t);
	void unlockAll();
	void removeFromLockCount(Triangle *t);

	/*!
	 * Define la forma en que se obtendra un nuevo vertice. A futuro se ocupara un pozo de vertices
	 */
	Vertex * fetchNewVertex(int id, Point2F p);
	/*!
	 * Define la forma en que se obtendra un nuevo triangulo. A futuro se ocupara un pozo de
	 * triangulos
	 */
	Triangle * fetchNewTriangle(int id,Vertex *v1, Vertex *v2, Vertex *v2);
	/*!
	 * Define la forma en que se se agregaran vertices al mesh. A futuro y dependiendo de la
	 * efectividad de la medida se podria primero agregar el vertice a una malla auxiliar y
	 * luego pasar masivamente a la malla definitiva
	 */
	void addVertexToMesh(Vertex *);
	/*!
	 * Define la forma en que se se agregaran triangulos al mesh. A futuro y dependiendo de la
	 * efectividad de la medida se podria primero agregar el triangulo a una malla auxiliar y
	 * luego pasar masivamente a la malla definitiva
	 */
	void addTriangleToMesh(Triangle *);
	/*!
	 * Realiza ultima operaciones de eliminacion sobre el triangulo. Lo elimina de la malla
	 * (seccion crítica) y luego lo elimina de la lista de trabajo
	 */
	void finalizeTriangle(Triangle *);
};

#endif /*LEPPBISECTIONTHREAD_H_*/
