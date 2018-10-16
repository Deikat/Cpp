#include "Polaire.hpp"
#include "Cartesien.hpp"

Polaire::Polaire(Cartesien c){
	_a = atan2(c.getY(),c.getX())*180/M_PI;
	_d = sqrt(c.getX()*c.getX() + c.getY()*c.getY());
}
Polaire::Polaire(double a, double d){
	_a = a;
	_d = d;
}

double Polaire::getAngle() const{
	return _a;
}
		
double Polaire::getDistance()const{
	return _d;
}

void Polaire::setAngle(double ai){
	_a=ai;
}

void Polaire::setDistance(double di){
	_d=di;
}

void Polaire::afficher(std::ostream & flux) const{
	flux<<"(a="<<_a<<";d="<<_d<<")";
}

void Polaire::convertir(Cartesien &c) const{
	c.setX(_d*cos(_a*M_PI/180));
	c.setY(_d*sin(_a*M_PI/180));
}

void Polaire::convertir(Polaire &p)const{
	p.setDistance(_d);
	p.setAngle(_a);
}
