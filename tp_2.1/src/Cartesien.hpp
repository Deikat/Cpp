#ifndef __CARTESIEN__HPP__
#define __CARTESIEN__HPP__

#include "point.hpp"
#include <sstream>
#include <cmath>

class Polaire;

class Cartesien : public Point{
	private :
		double _x;
		double _y;

	public :
		Cartesien(Polaire p);
		Cartesien(double x=0, double y=0);
		double getX() const;
		double getY() const;
		void setX(double xi);
		void setY(double yi);
		void afficher(std::ostream & flux) const;
		void convertir(Polaire &p) const;
		void convertir(Cartesien &c)const;
};


#endif
