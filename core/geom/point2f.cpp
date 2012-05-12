#include "point2f.h"
#include <cmath>
#include <sstream>

Point2F::Point2F()
{
	x=0;
	y=0;
}

Point2F::Point2F(float _x,float _y){
	x = _x;
	y = _y;

}

Point2F::Point2F(const Point2F& p){
	x = p.getX();
	y = p.getY();
}

float Point2F::getX() const{
	return x;
}

float Point2F::getY() const{
	return y;
}

void Point2F::setX(float _x){
	x = _x;
}

void Point2F::setY(float _y){
	y = _y;
}

const Point2F Point2F::operator+(const Point2F &p) const{
	return Point2F(x+p.getX(),y+p.getY());
}

const Point2F Point2F::operator-(const Point2F &p) const {
	return Point2F(x-p.getX(),y-p.getY());
}

const Point2F Point2F::operator*(const float &f) const {
	return Point2F(x*f,y*f);
}

float Point2F::distanceSquare(const Point2F &p) const {
	float diff_x = x-p.getX();
	float diff_y = y-p.getY();
	return diff_x*diff_x+diff_y*diff_y;
}

float Point2F::distance(const Point2F &p) const {
	return sqrtf(distanceSquare(p));
}

std::string Point2F::toString() const{
	std::stringstream ss;
	ss.precision(0);
	//ss.fixed(true);
	ss << std::fixed << "(" << getX() << "," << getY() <<")";
	return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Point2F& p){
	out << p.toString();
	return out;
}
