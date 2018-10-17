#ifndef __POLAIRE__HPP__
#define __POLAIRE__HPP__

#include "point.hpp"
#include <sstream>
#include <cmath>

class Cartesien;

class Polaire : public Point{
	private :
		double _a;
		double _d;

	public :
		Polaire(Cartesien c);
		Polaire(double a=0, double d=0);
		double getAngle() const;
		double getDistance() const;
		void setAngle(double ai);
		void setDistance(double di);
		void afficher(std::ostream & flux) const;
		void convertir(Cartesien &c)const;
		void convertir(Polaire &c)const;
};


#endif
