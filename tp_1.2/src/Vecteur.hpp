#ifndef __VECTEUR__HPP__
#define __VECTEUR__HPP__

#include <iostream>

class Vecteur{
	private:
		int * values;
		int taille;	
	public:
		Vecteur();
		Vecteur(int t);
		int getTaille();
		int * getValues();
		Vecteur( Vecteur & v);
		~Vecteur();
		void operator=(Vecteur & v);
		const int & operator[](int x);
		Vecteur operator[](int x);
		
		/*class Iterateur{
			private:
				Vecteur * vecteur;
				int * value;
			public:
				Iterateur();
				Iterateur begin();
				Iterateur end();
				Iterateur & operator++();
				Iterateur operator++(int i);
				int operator*();
				bool operator==(const Iterateur &)
		}*/
};
/*std::ostream & operator<<(std::ostream &flux, const Vecteur & v);
Vecteur operator+(const Vecteur &v1, const Vecteur & v2);
Vecteur operator*(const Vecteur &v1, const Vecteur & v2);*/

#endif
