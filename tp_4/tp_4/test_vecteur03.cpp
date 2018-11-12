// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vecteur03.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 Vecteur v1;
 Vecteur v2;

 complexe_t::stats();

 /*for (unsigned i = 0; i<v1.getTaille(); ++i) v1[i]=complexe_t(10*i,i*i);
 for (unsigned i = 0; i<v2.getTaille(); ++i) v2[i]=complexe_t(i,i+1);*/
	int i = 0;
	for (complexe_t & comp : v1){
		comp=complexe_t(10*i,i*i);
		i++;
	}
	i=0;
	for (complexe_t & comp : v2){
		comp=complexe_t(i,i+1);
		i++;
	}
	std::cout << std::endl << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	complexe_t::stats();

	Vecteur v3 = v1;

	std::cout << std::endl << "v3 = " << v3 << std::endl;
	complexe_t::stats();

	Vecteur v4;

	v4=v1+v2;

	std::cout << std::endl << "v4 = " << v4 << std::endl;
	complexe_t::stats();

	Vecteur v5;

	v5=v1*v2;

	std::cout << std::endl << "v5 = " << v5 << std::endl;
	complexe_t::stats();

	std::deque<complexe_t> liste;

	for (complexe_t & comp : v5){
		liste.push_back(comp);
	}

	std::cout << std::endl << "liste = v5" << std::endl;
	complexe_t::stats();

	//std::sort(liste.begin(),liste.end(),ComparateurComplexe());
	
	std::sort(liste.begin(),liste.end(), [] (complexe_t c1, complexe_t c2) { return c1.reel<c2.reel | c1.imaginaire < c2.imaginaire;});

	std::cout << std::endl;
	
	for (complexe_t comp : liste){
		std::cout << comp<< " ";
	}
	
	std::cout << std::endl;
	complexe_t::stats();
}

// Fin //-------------------------------------------------------------------------------------------
