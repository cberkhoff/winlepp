#include "vertex.h"
#include <QtGlobal>
#include <sstream>

Vertex::Vertex():Point2F(){
	Q_ASSERT(0);
}

Vertex::Vertex(int _id,const Point2F &p) : Point2F(p){
	id = _id;
}

Vertex::Vertex(int _id, float x, float y)
:Point2F(x,y){
	id = _id;
}

std::string Vertex::toString() const{
	std::stringstream ss;
	ss << "V_" << id << " " << Point2F::toString();
	return ss.str();
}

int Vertex::getId() const{
	return id;
}

void Vertex::setId(int _id){
	id = _id;
}

std::ostream& operator<< (std::ostream& out, const Vertex& v){
	out << v.toString();
	return out;
}
