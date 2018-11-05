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

bool CompInferieur(Valeur a, Valeur b){
	return (a.getNombre() <= b.getNombre());
}

Valeur Echantillon::getMinimum() const {
	if(_valeurs.size() !=0)
		return *std::min_element(_valeurs.begin(),_valeurs.end(),CompInferieur);
	else
		throw std::domain_error("Echantillon vide");
}
		
	
Valeur Echantillon::getMaximum() const{
	if(_valeurs.size() !=0)
		return *std::max_element(_valeurs.begin(),_valeurs.end(),CompInferieur);
	else
		throw std::domain_error("Echantillon vide");
}

Valeur Echantillon::getValeur(int i)const{
	if(i< (int) _valeurs.size())
		return _valeurs[i];
	else
		throw std::out_of_range("indice trop grand");
}
