#include "Nuage.hpp"
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

Nuage::Nuage(){
	values = std::vector<Point *>();	
}

size_t Nuage::size() const{
	return values.size();
}


void Nuage::ajouter(Point &p){
	values.push_back(&p);
}


Nuage::const_iterator Nuage::begin(){
	return values.begin();
}

Nuage::const_iterator Nuage::end(){
	return values.end();
}

Cartesien barycentre(Nuage & n){
	Cartesien c;
	float sommeX = 0, sommeY=0;
	for( Nuage::const_iterator it = n.begin(); it != n.end();it++){
		(*it)->convertir(c);
		sommeX += c.getX();
		sommeY += c.getY();
	}
	c.setX(sommeX / n.size());
	c.setY(sommeY / n.size());
	return c;
}

Cartesien BarycentreCartesien::operator()(Nuage & n){
	return barycentre(n);
}

Polaire BarycentrePolaire::operator()(Nuage & n){
	Polaire p;
	barycentre(n).convertir(p);
	return p;
}