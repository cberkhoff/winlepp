#include "triangle.h"
#include <QtGlobal>
#include <sstream>
#include <cmath>
#include <QtCore/QMutexLocker>

#include <iostream>
#include <QtDebug>
#include <QtCore/QThread>

Triangle::Triangle(){
	Q_ASSERT(0);
}

Triangle::Triangle(int _id, Vertex *v1, Vertex *v2, Vertex *v3){
	id = _id;
	vertexs[0] = v1;
	vertexs[1] = v2;
	vertexs[2] = v3;
	neighbors[0] = neighbors[1] = neighbors[2] = 0;
	Q_ASSERT(invariante());
}

Triangle::Triangle(const Triangle &t){
	id = t.getId();
	vertexs[0] = t.getVertex(0);
	vertexs[1] = t.getVertex(1);
	vertexs[2] = t.getVertex(2);
	neighbors[0] = t.getNeighbor(0);
	neighbors[1] = t.getNeighbor(1);
	neighbors[2] = t.getNeighbor(2);
	Q_ASSERT(invariante());
}

int Triangle::longestEdgeIndex() const{
	int max_index = 2;
	float max_distance_squared = vertexs[0]->distanceSquare(*vertexs[1]);
	for(int vertex_i=1;vertex_i<3;vertex_i++){
		int edge_i = (vertex_i+2)%3;
		int vertex_i_next = (vertex_i+1)%3;
		if(max_distance_squared < vertexs[vertex_i]->distanceSquare(*vertexs[vertex_i_next])){
			max_index = edge_i;
			max_distance_squared = vertexs[vertex_i]->distanceSquare(*vertexs[vertex_i_next]);
		}
	}

	return max_index;
}

int Triangle::getId() const{
	return id;
}

void Triangle::setId(int _id) {
	id = _id;
	Q_ASSERT(invariante());
}

Edge Triangle::getEdge(int i) const{
	Q_ASSERT(i<3&&i>-1);
	return Edge(vertexs[(i+1)%3],vertexs[(i+2)%3]);
}

Vertex* Triangle::getVertex(int i) const{
	Q_ASSERT(i<3&&i>-1);
	return vertexs[i];
}

void Triangle::setVertex(int i,Vertex *v){
	Q_ASSERT(i<3&&i>-1);
	vertexs[i] = v;
	Q_ASSERT(invariante());
}

bool Triangle::hasEdge(const Edge *e) const{
	int num_vertexs = 0;
	for(int j=0;j<2;j++)
		for(int i=0;i<3;i++)
			if(vertexs[i]->getId()==e->getVertex(j)->getId())
				num_vertexs++;
	return num_vertexs==2;
}

bool Triangle::invariante() const{
	/*//vertices no nulos
	for(int i=0;i<3;i++){
		if(vertexs[i]==0)
			return false;
	}
	for (int i=0;i<3;i++){
		for(int j=0;j<i;j++){
			if(vertexs[i]->getId()==vertexs[j]->getId())
				return false;
			if(vertexs[i]==vertexs[j])
				return false;
		}
	}
	//si vecino no nulo
	for(int i=0;i<3;i++){
		if(neighbors[i]!=0){
			//revisa que este bien ordenado y conectado
			//el vecino i esta opuesto al vertice i
			//compruebo aristas
			Edge e = Edge(vertexs[(i+1)%3],vertexs[(i+2)%3]);
			if(!neighbors[i]->hasEdge(&e))
				return false;
			//reviso que no esten duplicados
			for(int j=0;j<i;j++){
				if(neighbors[j]!=0){
					if(neighbors[i]==neighbors[j])
						return false;
					if(neighbors[i]->getId()==neighbors[j]->getId())
						return false;
				}
			}
		}
	}*/
	return true;
}

std::string Triangle::toString() const {
	std::stringstream ss;
	ss << "T_" << id << "\n";
	for(int i=0;i<3;i++){
		Edge e = getEdge(i);
		ss << e.toString() << "\t N: ";
		if(neighbors[i]!=0){
			ss << "T_" << getNeighbor(i)->getId();
		} else {
			ss << "NULL";
		}
		ss << "\n";
	}
	return ss.str();
}

void Triangle::setNeighbors(Triangle *t1, Triangle *t2, Triangle *t3){
	neighbors[0] = t1;
	neighbors[1] = t2;
	neighbors[2] = t3;
	Q_ASSERT(invariante());
}

Triangle * Triangle::getNeighbor(int edge_index) const {
	Q_ASSERT(edge_index<3&&edge_index>-1);
	return neighbors[edge_index];
}

void Triangle::setNeighbor(int index, Triangle *n){
	Q_ASSERT(index>-1&&index<3);
	neighbors[index]=n;
	Q_ASSERT(invariante());
}

void Triangle::replaceNeighbor(Triangle *objective,Triangle *replacement){
	Q_ASSERT(objective!=0);
	Q_ASSERT(objective!=replacement);
	for(int k=0;k<3;k++){
		if(neighbors[k]!=0){
			if(objective->getId()==neighbors[k]->getId()){
				neighbors[k] = replacement;
				Q_ASSERT(invariante());
				return;
			}
		}
	}
	Q_ASSERT(false);
}

Triangle * Triangle::getNeighborOposedToVertex(Vertex *v) const{
	int index = -1;
	for(int i=0;i<3;i++){
		if(v->getId()==vertexs[i]->getId())
			index = i;
	}
	Q_ASSERT(index!=-1);
	return neighbors[index];
}

Angle Triangle::getAngle(int i) const{
	Q_ASSERT(i>-1&&i<3);
	float a = vertexs[i]->distance(*vertexs[(i+1)%3]);
	float b = vertexs[i]->distance(*vertexs[(i+2)%3]);
	float c = vertexs[(i+2)%3]->distance(*vertexs[(i+1)%3]);
	Q_ASSERT(a>=0&&b>=0&&c>=0);
	return Angle(acos((a*a+b*b-c*c)/(2*a*b)));
}

QMutex * Triangle::getMutex(){
	return &mutex;
}

/*Triangle *Triangle::getLockedNeighbor(int edge_index){
	while(true){
		//std::cout <<  QThread::currentThread() << " Triangle::getLockedNeighbor() obteniendo lock interno del triangulo T="<< id << std::endl;
		internalMutex.lock();
		Triangle *u = neighbors[edge_index];
		if(u!=0){
			if(u->getMutex()->tryLock()){
				//si estoy aca entonces pude tomar el lock del vecino
				//std::cout <<  QThread::currentThread() << " Triangle::getLockedNeighbor() tome lock triangulo vecino U=" << u->getId()  << std::endl;
				internalMutex.unlock();
				return u;
			} else {
				//no pude tomar el lock y espero hasta que alguien cambie los vecinos
				//std::cout <<  QThread::currentThread() << " Triangle::getLockedNeighbor() esperando a que suelten vecinos del triangulo T="<< id << std::endl;
				neighborChanged.wait(&internalMutex);
				//std::cout <<  QThread::currentThread() << " Triangle::getLockedNeighbor() vecino soltado, continuo. T="<< id << std::endl;
				internalMutex.unlock();
			}
		} else {
			//std::cout <<  QThread::currentThread() << " Triangle::getLockedNeighbor() vecino nulo, no hay mutex que tomar. T=" << id << std::endl;
			internalMutex.unlock();
			return u;
		}
	}
}*/

/*Triangle *Triangle::tryToGetNeighbor(int edge_index, bool *couldAcquire, QTextStream &log){
	//log <<  QThread::currentThread() << " Triangle::tryToGetNeighbor() obteniendo lock interno del triangulo (T="<< id << ")\n";
	//log.flush();
	internalMutex.lock();
	Triangle *u = neighbors[edge_index];
	if(u!=0){
		if(u->getMutex()->tryLock()){
			//log <<  QThread::currentThread() << " Triangle::tryToGetNeighbor() tome lock triangulo vecino (T="<< id << ",U=" << u->getId()  << ")\n";
			//log.flush();
			//si estoy aca entonces pude tomar el lock del vecino
			*couldAcquire = true;
			internalMutex.unlock();
			return u;
		} else {
			//no pude tomar el lock y espero hasta que alguien cambie los vecinos
			//log <<  QThread::currentThread() << " Triangle::tryToGetNeighbor() no pude tomar vecino (T="<< id << ")\n";
			//log.flush();
			*couldAcquire = false;
			internalMutex.unlock();
			return 0;
		}
	} else {
		//log <<  QThread::currentThread() << " Triangle::tryToGetNeighbor() no tengo vecino (T="<< id << ")\n";
		//log.flush();
		*couldAcquire = true;
		internalMutex.unlock();
		return u;
	}
}*/

std::ostream& operator<< (std::ostream& out, const Triangle& t){
	out << t.toString();
	return out;
}
