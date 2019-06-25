#ifndef _COMP_F
#define _COMP_F

#include "func.h"
#include "polynom.h"
#include "ratfunc.h"

using namespace std ;

class compfunc : public func {
public:
	compfunc();
	compfunc(func& f, func& g);
	~compfunc();
	int operator[](const int& x) const;
protected:
	func* f_;
	func* g_;
	void print(ostream& os) const;

};


#endif