#include "angle.h"
#include <sstream>

Angle::Angle(){
	alfa = 0;
}

Angle::Angle(float alfa){
	this->alfa = alfa;
	normalize();
}

Angle::Angle(const Angle& a){
	this->alfa = a.getInRadians();
}

Angle::~Angle(){}

float Angle::getInRadians() const{
	return alfa;
}

void Angle::setInRadians(float a){
	alfa = a;
	normalize();
}

float Angle::getInDegrees() const{
	return (alfa*180)/PI;
}

void Angle::setInDegrees(float a){
	alfa = (a*PI)/180;
	normalize();
}

const Angle Angle::operator+(const Angle &a) const{
	return Angle(this->alfa+a.getInRadians());
}

const Angle Angle::operator-(const Angle &a) const{
	return Angle(this->alfa-a.getInRadians());
}

const Angle Angle::operator*(float f) const{
	return Angle(this->alfa*f);
}

bool Angle::operator>(const Angle &a) const{
	return this->alfa>a.getInRadians();
}

bool Angle::operator<(const Angle &a) const{
	return this->alfa<a.getInRadians();
}
std::string Angle::toString() const {
	std::stringstream ss;
	ss.precision(0);
	ss << std::fixed << getInDegrees() <<"°";
	return ss.str();
}
void Angle::normalize(){
	while(alfa<0){
		alfa+=2*PI;
	}
	while(alfa>=2*PI){
		alfa-=2*PI;
	}
}
std::ostream& operator<<(std::ostream& out, const Angle& a){
	out << a.toString();
	return out;
}
