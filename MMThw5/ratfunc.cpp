#include "ratfunc.h"

ratfunc::ratfunc() : N_() , D_(1) {
}

ratfunc::ratfunc(const polynom& p) : N_(p), D_(1) {
}

ratfunc::ratfunc(const polynom& d , const polynom& n) : N_(n) , D_(d) {
}

ratfunc::ratfunc(const ratfunc& r) : N_(r.N_), D_(r.D_) {
}

ratfunc::~ratfunc() {
}

int ratfunc::operator[](const int& x) const {
	int d = D_[x];
	int n = N_[x];
	if (d == 0) throw mathexception("divide by zero");
	return (n / d);
}

ratfunc ratfunc::Derivative() const {
	polynom dN = N_.Derivative();
	polynom dD = D_.Derivative();
	polynom Ntor = (dN * D_) - (N_ * dD);
	polynom Dtor = D_ * D_;
	ratfunc result(Dtor, Ntor);
	return result;
}

ratfunc& ratfunc::operator=(const ratfunc& r) {
	N_ = r.N_;
	D_ = r.D_;
	return *this;
}

ratfunc ratfunc::operator+(const ratfunc& r) const {
	polynom Ntor = (N_ * r.D_) + (r.N_ * D_);
	polynom Dtor = D_ * r.D_;
	ratfunc result(Dtor, Ntor);
	return result;
}

ratfunc ratfunc::operator-(const ratfunc& r) const {
	polynom Ntor = (N_ * r.D_) - (r.N_ * D_);
	polynom Dtor = D_ * r.D_;
	ratfunc result(Dtor, Ntor);
	return result;
}

ratfunc ratfunc::operator*(const ratfunc& r) const {
	polynom Ntor = N_ * r.N_;
	polynom Dtor = D_ * r.D_;
	ratfunc result(Dtor, Ntor);
	return result;
}

ratfunc ratfunc::operator/(const ratfunc& r) const {
	polynom Ntor = N_ * r.D_;
	polynom Dtor = D_ * r.N_;
	ratfunc result(Dtor, Ntor);
	return result;
}

void ratfunc::printRF(ostream& os) const {
	os << "(";
	N_.printcoefs(os);
	os << ")/(";
	D_.printcoefs(os);
	os << ")" << endl;
}

void ratfunc::print(ostream& os) const {
	printRF(os);
	ratfunc d = Derivative();
	os << "Derivative: ";
	d.printRF(os);
}
