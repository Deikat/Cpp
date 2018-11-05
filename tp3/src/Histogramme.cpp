#include "Histogramme.hpp"

Histogramme::Histogramme(double binf, double bsup, int nb){
	_nb_classes = nb;
	_borneInf = binf;
	_borneSup = bsup;

	for( int i=0; i<_nb_classes; ++i){
		Classe c(_borneInf + 2*(i),_borneInf + 2*(i+1));
		_classes.push_back(c);
	}
}

Histogramme::classes_t Histogramme::getClasses() const{
	return _classes;
}

void Histogramme::afficher(){
	Histogramme::classes_t::const_iterator it = _classes.begin();
	unsigned                         i  = 0;
	while (it!=_classes.end()) {
		std::cout << "binf: "<<it->getBorneInf() << " bsup: "<< it->getBorneSup()<<" qte: " <<it->getQuantite() <<std::endl;
	  	++it;
	  	++i;
 	}
}

void Histogramme::ajouter(Echantillon e){
	for(int i=0; i<(int)e.getTaille();++i){
		int j=0;
		while(_classes[j].getBorneSup()<=e.getValeur(i).getNombre())
			j++;
		_classes[j].ajouter();
	}
}
