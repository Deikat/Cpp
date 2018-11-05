#ifndef __VALEUR_HPP__
#define __VALEUR_HPP__


class Valeur{
	
	private:
		double _valeur;
		
	public:
		Valeur(double v=0);
		double getNombre() const;
		void setNombre(double v);
	
};


#endif

