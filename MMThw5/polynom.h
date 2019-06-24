#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using std::vector ;


class polynom : public func {
 public:
	 polynom() ;
	 polynom(int n , int* coefs);
	 polynom(const polynom& p);
	 polynom(const int n) ;
	 ~polynom();
	 int operator[](const int& x) const;
	 polynom& operator=(const polynom& p) ;
	 polynom& operator+(const polynom& p) const;
	 polynom& operator-(const polynom& p) const;
	 polynom& operator*(const polynom& p) const;
	 polynom& Derivative() const;
	 polynom& Integral() const;
	 void printcoefs(ostream&) const;
protected:
  int n_; //order of the polynom
  int* coefs_; //coefficients
  void print(ostream& os) const;
};

#endif
 
