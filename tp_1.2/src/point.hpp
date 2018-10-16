#ifndef __POINT__HPP__
#define __POINT__HPP__

#include <sstream>
class Cartesien;
class Polaire;

class Point{
	public :
		virtual void afficher(std::ostream &) const =0;
		virtual void convertir(Cartesien &c) const=0;
		virtual void convertir(Polaire &p) const=0;
		
};

std::ostream & operator<<(std::ostream &flux, const Point & p);

#endif

