#include "Classe.hpp"

Classe::Classe(double binf, double bsup){
	_borneInf = binf;
	_borneSup = bsup;
	_quantite = size_t(0);
}

double Classe::getBorneInf() const{
	return _borneInf;
}

double Classe::getBorneSup() const{
	return _borneSup;
}

size_t Classe::getQuantite() const{
	return _quantite;
}

void Classe::setBorneInf(double binf){
	_borneInf = binf;
}

void Classe::setBorneSup(double bsup){
	_borneSup = bsup;
}

void Classe::setQuantite(size_t q){
	_quantite = q;
}

void Classe::ajouter(){
	_quantite ++;
}

void Classe::afficher() const{
	std::cout << "binf: "<<_borneInf << " bsup: "<< _borneSup<<" qte: " <<_quantite <<std::endl;
}