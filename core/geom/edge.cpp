#include "edge.h"
#include <sstream>
#include <QtGlobal>

Edge::Edge(){
	Q_ASSERT(0);
}

Edge::Edge(Vertex* _v1, Vertex* _v2){
	Q_ASSERT(_v1!=0&&_v2!=0);
	v[0] = _v1;
	v[1] = _v2;
	Q_ASSERT(invariante());
}

const Point2F Edge::midPoint() const{
	return ((*v[1]-*v[0])*0.5)+*v[0];
}

Vertex* Edge::getVertex(int i) const{
	Q_ASSERT(i<2&&i>-1);
	return v[i];
}

bool Edge::sameVertexsId(Edge *e) const{
	return (getVertex(0)->getId()==e->getVertex(0)->getId()&&getVertex(1)->getId()==e->getVertex(1)->getId())
		   ||(getVertex(1)->getId()==e->getVertex(0)->getId()&&getVertex(0)->getId()==e->getVertex(1)->getId());
}

float Edge::size() const{
	return v[0]->distance(*v[1]);
}

std::string Edge::toString() const{
	std::stringstream ss;
	ss << "E" <<"\t" << v[0]->toString() << "\t" << v[1]->toString();
	return ss.str();
}

bool Edge::hasVertex(Vertex *v1) const{
	return v[0]==v1||v[1]==v1;
}

bool Edge::hasVertexId(Vertex *v1) const{
	return v[0]->getId()==v1->getId()||v[1]->getId()==v1->getId();
}

bool Edge::invariante() const {
	if(v[0]==0||v[1]==0)
		return false;
	if(v[0]==v[1]||v[0]->getId()==v[1]->getId())
		return false;
	return true;
}

std::ostream& operator<< (std::ostream& out, const Edge& a){
	out << a.toString();
	return out;
}
