#include "mesh.h"
#include <QtGlobal>
#include <sstream>
#include <QtCore/QSet>
#include <QtCore/QMutexLocker>

Mesh::Mesh(){
	TrianglesHighestId = -1;
	VertexsHighestId = -1;
	Q_ASSERT(invariante());
}

Mesh::~Mesh(){
	QMap<int,Triangle*>::iterator triangle_it;
	for(triangle_it=triangles.begin();triangle_it!=triangles.end();triangle_it++){
		Triangle *t = triangle_it.value();
		delete t;
	}
	QMap<int,Vertex*>::iterator vertex_it;
	for(vertex_it=vertexs.begin();vertex_it!=vertexs.end();vertex_it++){
		Vertex *v = vertex_it.value();
		delete v;
	}
}

Triangle * Mesh::getTriangle(int index){
	if(index==0)
		return 0;
	QMutexLocker locker(&mutex);
	Q_ASSERT(triangles.count(index)>0);
	return triangles[index];
}

Vertex * Mesh::getVertex(int index){
	QMutexLocker locker(&mutex);
	if(index==0)
		return 0;
	Q_ASSERT(vertexs.count(index)>0);
	return vertexs[index];
}

void Mesh::setTriangle(int index, Triangle *t){
	QMutexLocker locker(&mutex);
	triangles.insert(index,t);
	if(t->getId()>TrianglesHighestId)
		TrianglesHighestId = t->getId();
	Q_ASSERT(invariante());
}

void Mesh::setVertex(int index, Vertex *v){
	QMutexLocker locker(&mutex);
	vertexs.insert(index,v);
	if(v->getId()>VertexsHighestId)
		VertexsHighestId = v->getId();
	Q_ASSERT(invariante());
}

void Mesh::addTriangle(Triangle *t){
	QMutexLocker locker(&mutex);
	int id = ++TrianglesHighestId;
	if(t->getId()==-1)
		t->setId(id);
	triangles.insert(id,t);
	Q_ASSERT(invariante());
}

void Mesh::addVertex(Vertex *v){
	QMutexLocker locker(&mutex);
	int id = ++VertexsHighestId;
	if(v->getId()==-1)
		v->setId(id);
	vertexs.insert(++VertexsHighestId,v);
	Q_ASSERT(invariante());
}

std::string Mesh::toString() const{
	QMutexLocker locker(&mutex);
	std::stringstream ss;
	QMap<int,Triangle*>::const_iterator tIterator;
	for(tIterator = triangles.begin(); tIterator != triangles.end(); tIterator++){
		Triangle *t = tIterator.value();
		ss << (*t) << std::endl;
	}
	return ss.str();
}

bool Mesh::invariante() const {
	/*//chequeo que los id's de los triangulos sean unicos
	QSet<int> id_triangle_set;
	//set<int>::iterator it_id_set;
	QMap<int,Triangle*>::const_iterator tIterator;
	for(tIterator = triangles.begin(); tIterator != triangles.end(); tIterator++){
		Triangle *t = tIterator.value();
		if(t==0)
			return false;
		//si es que esta en el conjunto
		if((id_triangle_set.find(t->getId()))!=id_triangle_set.end()){
			//esta mal
			return false;
		} else {
			id_triangle_set.insert(t->getId());
		}
	}

	//chequeo que los id's de los vertices sean unicos
	QSet<int> id_vertexs_set;
	//set<int>::iterator it_id_set;
	QMap<int,Vertex*>::const_iterator vIterator;
	for(vIterator = vertexs.begin(); vIterator != vertexs.end(); vIterator++){
		Vertex *v = vIterator.value();
		if(v==0)
			return false;
		//si es que esta en el conjunto
		if((id_vertexs_set.find(v->getId()))!=id_vertexs_set.end()){
			//esta mal
			return false;
		} else {
			id_vertexs_set.insert(v->getId());
		}
	}*/
	return true;
}

void Mesh::destroyTriangle(Triangle *t){
	QMutexLocker locker(&mutex);
	/*QMap<int,Triangle*>::iterator it = triangles.find(i);
	Triangle *t = it.value();
	triangles.erase(it);*/
	int n = triangles.remove(t->getId());
	Q_ASSERT(n==1);

	delete t;
	Q_ASSERT(invariante());
}

int Mesh::getTrianglesHighestId() const{
	QMutexLocker locker(&mutex);
	return TrianglesHighestId;
}

int Mesh::getVertexsHighestId() const{
	QMutexLocker locker(&mutex);
	return VertexsHighestId;
}

bool Mesh::hasTriangle(Triangle *t){
	QMutexLocker locker(&mutex);
	return triangles.count(t->getId())>0;
}

QMap<int,Triangle *> * Mesh::getTriangles(){
	QMutexLocker locker(&mutex);
	return &triangles;
}

QMap<int,Vertex *> * Mesh::getVertexs(){
	QMutexLocker locker(&mutex);
	return &vertexs;
}

std::ostream& operator<< (std::ostream& out, const Mesh& m){
	out << m.toString() << "\n\n" << std::endl;
	return out;
}
