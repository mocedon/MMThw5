#ifndef _RATFUNC
#define _RATFUNC

#include "func.h"
#include "polynom.h"
#include "mathexception.h"

using namespace std ;

class ratfunc : public func {
public:
	ratfunc();
	ratfunc(const polynom& p);
	ratfunc(const polynom& d, const polynom& n);
	ratfunc(const ratfunc& r);
	~ratfunc();
	int operator[](const int& x) const;
	ratfunc Derivative() const;
	ratfunc& operator=(const ratfunc& r);
	ratfunc operator+(const ratfunc& r) const;
	ratfunc operator-(const ratfunc& r) const;
	ratfunc operator*(const ratfunc& r) const;
	ratfunc operator/(const ratfunc& r) const;
protected:
	polynom N_;
	polynom D_;
	void printRF(ostream& os) const;
	void print(ostream& os) const;
};

#endif