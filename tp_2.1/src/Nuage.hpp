#ifndef __NUAGE__HPP__
#define __NUAGE__HPP__

#include "Cartesien.hpp"
#include "Polaire.hpp"
#include <vector>
#include <cstddef>

class Point;
class Cartesien;
class Polaire;

template <typename T> class Nuage{
	private :
		std::vector<T> values;
	public :
		Nuage();
		size_t	size() const;
		void ajouter(T p);
		typedef typename std::vector<T>::const_iterator const_iterator;
		const_iterator begin();
		const_iterator end();
	
};


template <typename T> Nuage<T>::Nuage(){
	values = std::vector<T>();	
}

template <typename T> size_t Nuage<T>::size() const{
	return values.size();
}


template <typename T> void Nuage<T>::ajouter(T p){
	values.push_back(p);
}


template <typename T> typename Nuage<T>::const_iterator Nuage<T>::begin(){
	return values.begin();
}

template <typename T> typename Nuage<T>::const_iterator Nuage<T>::end(){
	return values.end();
}


/*struct BarycentreCartesien{
	Cartesien operator()(Nuage & n);
};

struct BarycentrePolaire{
	Polaire operator()(Nuage & n);
};*/

template <typename T> T barycentre_v1(Nuage<T> & n){
	Cartesien c;
	float sommeX = 0, sommeY=0;
	if(n.size() != 0){
		for( typename Nuage<T>::const_iterator it = n.begin(); it != n.end();it++){
			c = Cartesien(*it);
			sommeX += c.getX();
			sommeY += c.getY();
		}
		c.setX(sommeX / n.size());
		c.setY(sommeY / n.size());
	}		
	return T(c);
}

/* pour le test 4b */
Polaire barycentre_v1(Nuage<Polaire> & n){
	Polaire p;
	float sommeAngle = 0, sommeDistance= 0;
	if(n.size() !=0){
		for(Nuage<Polaire>::const_iterator it = n.begin(); it != n.end(); ++it){
			sommeDistance += it->getDistance();
			sommeAngle += it->getAngle();
		}
		p.setAngle(sommeAngle/n.size());
		p.setDistance(sommeDistance/n.size());
	}
	return p;
}
/*Cartesien BarycentreCartesien::operator()(Nuage & n){
	return barycentre(n);
}

Polaire BarycentrePolaire::operator()(Nuage & n){
	Polaire p;
	barycentre(n).convertir(p);
	return p;
}*/

#endif
