#include "Histogramme.hpp"

Histogramme::Histogramme<typename T>(double binf, double bsup, int nb){
	_nb_classes = nb;
	_borneInf = binf;
	_borneSup = bsup;
	
	//_classes = std::vector<Classe>();
	_classes = std::set<Classe>();
	for( int i=0; i<_nb_classes; ++i){
		Classe c(_borneInf + 2*(i),_borneInf + 2*(i+1));
		//_classes.push_back(c);
		_classes.insert(c);
	}
}

Histogramme::classes_t & Histogramme::getClasses(){
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

/* on ne peut pas parcourrir un set car on casserait son ordre, il faut retirer l'elt le modifier puis de remettre dans le set
*/
void Histogramme::ajouter(Echantillon e){
	for(int i=0; i<(int)e.getTaille();++i){
		Histogramme::classes_t::const_iterator it = _classes.begin();
		while(it->getBorneSup() <=e.getValeur(i).getNombre())
			it ++;
		Classe c = *it;
		_classes.erase(it);
		c.ajouter();
		_classes.insert(c);
		/*int j=0;
		while(_classes[j].getBorneSup()<=e.getValeur(i).getNombre())
			j++;
		_classes[j].ajouter();*/
	}
}

bool operator<(const Classe & c1, const Classe & c2){
	return c1.getBorneInf() < c2.getBorneInf();
}
