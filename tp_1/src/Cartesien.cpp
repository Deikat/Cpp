#include "Cartesien.hpp"
#include "Polaire.hpp"

Cartesien::Cartesien(Polaire &p){
	_x = p.getDistance()*cos(p.getAngle());
	_y = p.getDistance()*sin(p.getAngle());
}

Cartesien::Cartesien(double x, double y){
	_x = x;
	_y = y;
}

double Cartesien::getX() const{
	return _x;
}
		
double Cartesien::getY()const{
	return _y;
}

void Cartesien::setX(double xi){
	_x=xi;
}

void Cartesien::setY(double yi){
	_y=yi;
}

void Cartesien::afficher(std::ostream & flux) const{
	flux<<"(x="<<_x<<";y="<<_y<<")";
}

void Cartesien::convertir(Polaire &p) const{
	p.setDistance(sqrt(_x*_x + _y*_y));
	p.setAngle(atan2(_x,_y)*180/M_PI);
}

void Cartesien::convertir(Cartesien &c)const{}
