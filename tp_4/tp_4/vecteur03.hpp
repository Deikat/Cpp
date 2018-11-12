// Gardien //---------------------------------------------------------------------------------------
#ifndef _VECTEUR03_HPP_
#define _VECTEUR03_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <complexe.hpp>
#include <stdexcept>
#include <iterator>

// Classe  V e c t e u r //-------------------------------------------------------------------------
class Vecteur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  unsigned     taille_;
  complexe_t * tableau_;

 public :
	typedef complexe_t * const_iterator;
	const_iterator begin() {return tableau_;}
	const_iterator end() {return tableau_ + taille_-1;}

 //---------------------------------------------------------------------------------------Accesseurs
 public:
  unsigned getTaille(void) const { return taille_; }

  complexe_t & operator[](unsigned i) {
   if (i<taille_) return tableau_[i];
   throw std::out_of_range("");
  }

  const complexe_t & operator[](unsigned i) const {
   if (i<taille_) return tableau_[i];
   throw std::out_of_range("");
  }

 public:
  //-----------------------------------------------------------------------------Constructeur defaut
  explicit Vecteur(unsigned t = 10) : taille_(t),tableau_(new complexe_t[taille_]) {}

  //------------------------------------------------------------------------------Constructeur copie
  Vecteur(const Vecteur & v) : taille_(v.taille_),tableau_(new complexe_t[taille_]) {
   for (unsigned i = 0; i<taille_; ++i) tableau_[i]=v[i];
  }

	Vecteur(Vecteur && v) : taille_(v.taille_){
		complexe_t * tmp_tab = tableau_;
		tableau_ = v.begin();
		v.tableau_ = tmp_tab;
		
		unsigned tmp_taille = taille_;
		v.taille_ = tmp_taille;
	}
		
	
  //-------------------------------------------------------------------------------------Destructeur
  ~Vecteur(void) { if (tableau_) delete [] tableau_; }

  //-------------------------------------------------------------------------------Affectation copie
   Vecteur & operator=(const Vecteur &v) {
   if (this!=&v) {
    if (taille_!=v.taille_) throw std::length_error("");
    for (unsigned i = 0; i<v.taille_; ++i) tableau_[i]=v[i];
   }

   return *this;
  }
  
  Vecteur & operator=(Vecteur &&v) {
   if (this!=&v) {
	    complexe_t * tmp_tab = tableau_;
		tableau_ = v.begin();
		v.tableau_ = tmp_tab;
		
		unsigned tmp_taille = taille_;
		taille_ = v.taille_;
		v.taille_ = tmp_taille;
   }

   return *this;
  }
};

// Surcharge operateurs //--------------------------------------------------------------------------

//----------------------------------------------------------------------------------------operator<<
inline std::ostream & operator<<(std::ostream & flux,const Vecteur & v) {
 for (unsigned i = 0; i<v.getTaille(); ++i) flux << v[i] << " ";
 return flux;
}

//-----------------------------------------------------------------------------------------operator+
inline Vecteur operator+(const Vecteur & v1,const Vecteur & v2) {
 Vecteur v;

 for (unsigned i = 0; i<v1.getTaille(); ++i) v[i]=v1[i]+v2[i];

 return v;
}

//-----------------------------------------------------------------------------------------operator*
inline Vecteur operator*(const Vecteur & v1,const Vecteur & v2) {
 Vecteur v;

 for (unsigned i = 0; i<v1.getTaille(); ++i) v[i]=v1[i]*v2[i];

 return v;
}

// Fin //-------------------------------------------------------------------------------------------
#endif
