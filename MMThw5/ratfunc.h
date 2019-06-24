#ifndef _RATFUNC
#define _RATFUNC

#include "func.h"
#include "polynom.h"

using namespace std ;

class ratfunc : public func {
public:
	ratfunc() ;
	ratfunc(const polynom& n, const polynom& d = 1) ;
	~ratfunc() ;

	int operator[](const int& x) const ;
	ratfunc& Derivative() const ;

	ratfunc& operator=(const ratfunc& r) ;
	ratfunc& operator+(const ratfunc& b) const ;
	ratfunc& operator*(const ratfunc& b) const ;
	ratfunc& operator/(const ratfunc& b) const ;

protected:
	polynom N_;
	polynom D_;
	void print(ostream& os) const ;

};

#endif