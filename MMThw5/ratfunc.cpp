#include "ratfunc.h"

ratfunc::ratfunc() : N_() , D_(1) {
}

ratfunc::ratfunc(const polynom& n , const polynom& d) : N_(n) , D_(d) {
}

ratfunc::~ratfunc() {
}

int ratfunc::operator[](const int& x) const {
	return (N_[x] / D_[x]) ;
}

ratfunc& ratfunc::Derivative() const {
	ratfunc result(N_.Derivative() * D_ - N_ * D_.Derivative() , D_ * D_) ;
	return result ;
}

ratfunc& ratfunc::operator=(const ratfunc& r) {
	N_ = r.N_ ;
	D_ = r.D_ ;
}

ratfunc& ratfunc::operator+(const ratfunc& r) const {
	polynom Ntor = N_ * r.D_ + r.N_ * D_ ;
	polynom Dtor = D_ * r.D_ ;
	ratfunc result(Ntor , Dtor) ;
	return result ;
}

ratfunc& ratfunc::operator*(const ratfunc& r) const {
	polynom Ntor = N_ * r.N_ ;
	polynom Dtor = D_ * r.D_ ;
	ratfunc result(Ntor , Dtor) ;
	return result ;
}

ratfunc& ratfunc::operator/(const ratfunc& r) const {
	polynom Ntor = N_ * r.D_;
	polynom Dtor = D_ * r.N_;
	ratfunc result(Ntor, Dtor);
	return result;
}

void ratfunc::print(ostream& os) const {
	ratfunc d = Derivative() ;
	os << "(" ;
	N_.printcoefs(os) ;
	os << ")/(" ;
	D_.printcoefs(os) ;
	os <<")" << endl ;
	os << "(";
	d.N_.printcoefs(os) ;
	os << ")/(";
	d.D_.printcoefs(os) ;
	os << ")" << endl ;
	
}

