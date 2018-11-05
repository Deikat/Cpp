#ifndef __HISTOGRAMME_HPP__
#define __HISTOGRAMME_HPP__

#include <vector>
#include "Classe.hpp"
#include "Echantillon.hpp"
#include <iostream>
#include <set>



template <typename T = bool> class Histogramme{
	
	public:
		//using classes_t = std::vector<Classe>;
		using classes_t = std::set<Classe,T>;
		Histogramme<T>(double binf, double bsup, int nb);
		typedef typename classes_t::const_iterator const_iterator;
		classes_t & getClasses();
		void afficher();
		void ajouter(Echantillon e);

	private:
		classes_t _classes;
		double _borneInf;
		double _borneSup;
		int _nb_classes;
};

bool operator<(const Classe & c1, const Classe & c2);


#endif
