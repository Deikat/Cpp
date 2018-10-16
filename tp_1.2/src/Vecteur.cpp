#include "Vecteur.hpp"

int Vecteur::getTaille(){
	return taille;
}

int * Vecteur::getValues(){
	return values;
}

Vecteur::Vecteur(){
	taille = 10;
	values = new int [taille]();
}

Vecteur::Vecteur(int t){
	if(t>=0)
		taille=t;
	else
		taille = 10;
	values = new int [taille]();
}
Vecteur::Vecteur( Vecteur & v){
	values = new int [taille]();
	taille = v.getTaille();
	for(int i=0; i<taille;++i)
		values[i] = v.getValues()[i];	
}
	
Vecteur::~Vecteur(){
	if(values != NULL)
		delete [] values;
}

void Vecteur::operator=(Vecteur & v){
	taille = v.getTaille();
	delete [] values;
	values = new int [taille]();
	for(int i=0; i<taille;++i)
		values[i] = v.getValues()[i];
}

const int & operator[](int x){
	if(i<taille && i>=0)
		return &values[x];
	else
		return 0;
}

Vecteurr operator[](int x){
	if(i<taille && i>=0)
		values[i] = x;
}
		


/*

				
Iterateur();
Iterateur begin();
Iterateur end();
Iterateur & operator++();
Iterateur operator++(int i);
int operator*();
bool operator==(const Iterateur &)




std::ostream & operator<<(std::ostream &flux, const Vecteur & v);
Vecteur operator+(const Vecteur &v1, const Vecteur & v2);
Vecteur operator*(const Vecteur &v1, const Vecteur & v2);*/
