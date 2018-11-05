#include "Valeur.hpp"


Valeur::Valeur(double v){
	_valeur = v;
}


double Valeur::getNombre() const{
	return _valeur;
}

void Valeur::setNombre(double v){
	_valeur = v;
}
