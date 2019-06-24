#include "polynom.h"

polynom::polynom() : n_(0), coefs_(NULL) {
}

polynom::polynom(int n, int* coefs) : n_(n), coefs_(new int[n + 1]) {
	if (coefs == NULL) {
	 	for (int i = 0; i <= n; i++) {
			coefs_[i] = 0;
		}
	}
	else {
		for (int i = 0; i <= n; i++) {
			coefs_[i] = coefs[i];
		}
	}
}

polynom::polynom(const polynom& p) : polynom(p.n_,p.coefs_) {}


polynom::polynom(const int n) : n_(1), coefs_(new int) {
	*coefs_ = n;
}

polynom::~polynom() {
	delete[] coefs_;
}

int polynom::operator[](const int& x) const {
	int sum = 0;
	for (int i = 0; i <= n_; i++) {
		int e = coefs_[i];
		for (int j = 0; j < i; j++) {
			e *= x;
		}
		sum += e;
	}
	return sum;
}

polynom& polynom::operator=(const polynom& p) {
	n_ = p.n_ ;
	delete[] coefs_ ;
	coefs_ = new int[n_+1]  ;
	for (int i = 0; i <= n_; i++) {
		coefs_[i] = p.coefs_[i] ;
	}


}

polynom& polynom::operator+(const polynom& p) const {
	int n = p.n_;
	if (n_ > n)
	{
		n = n_;
	}
	int* coefs = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		if (i <= n_ && i <= p.n_) {
			coefs[i] = coefs_[i] + p.coefs_[i];
		}
		else if (i > n_) {
			coefs[i] = p.coefs_[i];
		}
		else {
			coefs[i] = coefs_[i];
		}
	}
	polynom result(n, coefs);
	delete[] coefs;
	return result;
}

polynom& polynom::operator-(const polynom& p) const {
	int n = p.n_;
	int* coefs = new int[n + 1];
	for (int i = 0; i < p.n_; i++) {
		coefs[i] = -p.coefs_[i];
	}
	polynom q(n, coefs);
	delete[] coefs;
	return (*this + q);
}

polynom& polynom::operator*(const polynom& p) const {
	int n = n_ + p.n_;
	int* coefs = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		coefs[i] = 0;
	}
	for (int i = 0; i <= n_; i++) {
		for (int j = 0; j <= p.n_; j++) {
			coefs[i + j] = coefs[i + j] coefs_[i] + p.coefs_[j];
		}
	}
	polynom result(n, coefs);
	delete[] coefs;
	return result;
}

polynom& polynom::Derivative() const {
	int n = n_ - 1;
	int* coefs = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		coefs[i] = (i + 1)*coefs_[i + 1];
	}
	polynom result(n, coefs);
	delete[] coefs;
	return result;
}

polynom& polynom::Integral() const {
	int n = n_ + 1;
	int* coefs = new int[n + 1];
	coefs[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		coefs[i] = coefs_[i - 1] / i;
	}
	polynom result(n, coefs);
	delete[] coefs_;
	return result;
}

void polynom::printcoefs(ostream& os) const {
	int allZero = 1;
	for (auto i = n_; i >= 0; i--) {
		if (coefs_[i] > 0) {
			allZero = 0;
			if (i != n_) {
				os << "+";
			}
			if (coefs_[i] != 1 || i == 0) {
				os << coefs_[i];
			}
			if (i > 0) {
				os << "x";
				if (i > 1)
					os << "^" << i;
			}
		}
		else if (coefs_[i] < 0) {
			allZero = 0;
			if (coefs_[i] != -1 || i == 0) {
				os << coefs_[i];
			}
			else
				os << "-";
			if (i > 0) {
				os << "x";
				if (i > 1)
					os << "^" << i;
			}
		}
		else if (i == 0 && allZero == 1) { //coefs_[i]==0
			os << "0";
			continue;
		}
	}
}

void polynom::print(ostream& os) const {
	polynom d = Derivative() ;
	polynom i = Integral() ;
	printcoefs(os) ;
	os << endl << "Derivative: " ;
	d.printcoefs(os);
	os << endl << "Integral: " ;
	i.printcoefs(os) ;
	os << "+Constant" << endl ;
}
