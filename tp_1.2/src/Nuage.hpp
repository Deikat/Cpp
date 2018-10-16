#ifndef __NUAGE__HPP__
#define __NUAGE__HPP__

#include <vector>
#include <cstddef>
class Point;
class Cartesien;
class Polaire;

class Nuage{
	private :
		std::vector<Point *> values;
	public :
		Nuage();
		size_t	size() const;
		void ajouter(Point &p);
		typedef std::vector<Point*>::const_iterator const_iterator;
		const_iterator begin();
		const_iterator end();
	
};
Cartesien barycentre(Nuage & n);
struct BarycentreCartesien{
	Cartesien operator()(Nuage & n);
};

struct BarycentrePolaire{
	Polaire operator()(Nuage & n);
};

#endif
