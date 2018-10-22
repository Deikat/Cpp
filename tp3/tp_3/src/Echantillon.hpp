#ifndef __ECHANTILLON_HPP__
#define __ECHANTILLON_HPP__

#include <vector>
#include "Valeur.hpp"
#include <cstddef>
#include <algorithm>


class Echantillon{
	private:
		std::vector<Valeur> _valeurs;
		
	public:
		typedef std::vector<Valeur>::const_iterator const_iterator;
		Echantillon();
		size_t getTaille() const;
		void ajouter(double v);
		Valeur getMinimum() const;
		Valeur getMaximum() const;
		Valeur getValeur(int i) const;
	
};


#endif
