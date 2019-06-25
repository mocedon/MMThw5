#ifndef _RATFUNC
#define _RATFUNC

#include "func.h"
#include "polynom.h"

using namespace std ;

class ratfunc : public func {
public:
	ratfunc();
	ratfunc(const polynom& p);
	ratfunc(const polynom& n, const polynom& d);
	ratfunc(const ratfunc& r);
	~ratfunc();
	int operator[](const int& x) const;
	ratfunc& Derivative() const;
	ratfunc& operator=(const ratfunc& r);
	ratfunc& operator+(const ratfunc& r) const;
	ratfunc& operator-(const ratfunc& r) const;
	ratfunc& operator*(const ratfunc& r) const;
	ratfunc& operator/(const ratfunc& r) const;
protected:
	polynom N_;
	polynom D_;
	void print(ostream& os) const;

};

#endif