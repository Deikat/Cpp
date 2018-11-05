#ifndef __CLASSE_HPP__
#define __CLASSE_HPP__

#include <cstddef>
#include <iostream>

class Classe{
	private :
		double _borneInf;
		double _borneSup;
		size_t _quantite;

	public:
		Classe(double binf, double bsup);
		double getBorneInf() const;
		double getBorneSup() const;
		size_t getQuantite() const;
		void setBorneInf(double binf);
		void setBorneSup(double bsup);
		void setQuantite(size_t q);
		void ajouter();
		void afficher() const;
};
#endif