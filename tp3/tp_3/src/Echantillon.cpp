#include "Echantillon.hpp"

Echantillon::Echantillon(){
	_valeurs = std::vector<Valeur>();
}

size_t Echantillon::getTaille() const{
	return _valeurs.size();
}

void Echantillon::ajouter(double v){
	_valeurs.push_back(Valeur(v));
}

Valeur Echantillon::getMinimum() const{
	return std::min_element(_valeurs.begin(),_valeurs.end());
}
		
	
Valeur Echantillon::getMaximum()const{
	return std::max_element(_valeurs.begin(),_valeurs.end());
}

Valeur Echantillon::getValeur(int i)const{
	return _valeurs[i];
}
