#ifndef __HISTOGRAMME_HPP__
#define __HISTOGRAMME_HPP__

#include <vector>
#include "Classe.hpp"
#include "Echantillon.hpp"
#include <iostream>

class Histogramme{
	public:
		using classes_t = std::vector<Classe>;
		Histogramme(double binf, double bsup, int nb);
		typedef classes_t::const_iterator const_iterator;
		classes_t getClasses() const;
		void afficher();
		void ajouter(Echantillon e);

	private:
		classes_t _classes;
		double _borneInf;
		double _borneSup;
		int _nb_classes;
};
#endif