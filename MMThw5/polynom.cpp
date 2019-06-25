#include "polynom.h"

polynom::polynom(int n, int* coefs) : n_(n), coefs_(new int[n + 1]) {
	for (int i = 0; i <= n; i++) {
		coefs_[i] = coefs[i];
	}
}

polynom::polynom(const polynom& p) : n_(p.n_), coefs_(p.coefs_) {}

polynom::polynom(const int a0) : n_(0), coefs_(new int[1]) {
	coefs_[0] = a0;
}

polynom::~polynom() {
	delete[] coefs_;
}

int polynom::operator[](const int& x) const {
	int sum = 0;
	int e = 1;
	for (int i = 0; i <= n_; i++) {
		sum += e*coefs_[i];
		e *= x;
	}
	return sum;
}

polynom& polynom::operator=(const polynom& p) {
	if (this->coefs_ == p.coefs_) {
		return *this;
	}
	n_ = p.n_;
	delete[] coefs_;
	coefs_ = new int[n_+1];
	for (int i = 0; i <= n_; i++) {
		coefs_[i] = p.coefs_[i];
	}
	return *this;
}

polynom polynom::operator+(const polynom& p) const {
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

polynom polynom::operator-(const polynom& p) const {
	int n = p.n_;
	int* coefs = new int[n + 1];
	for (int i = 0; i < p.n_; i++) {
		coefs[i] = -p.coefs_[i];
	}
	polynom q(n, coefs);
	delete[] coefs;
	return (*this + q);
}

polynom polynom::operator*(const polynom& p) const {
	int n = n_ + p.n_;
	int* coefs = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		coefs[i] = 0;
	}
	for (int i = 0; i <= n_; i++) {
		for (int j = 0; j <= p.n_; j++) {
			coefs[i + j] = coefs[i + j] + coefs_[i] + p.coefs_[j];
		}
	}
	polynom result(n, coefs);
	delete[] coefs;
	return result;
}
polynom polynom::Derivative() const {
	if (n_ == 0) {
		return polynom();
	}
	int n = n_ - 1;
	int* coefs = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		coefs[i] = coefs_[i + 1] * (i + 1);
	}
	polynom result(n, coefs);
	delete[] coefs;
	return result;
}

polynom polynom::Integral() const {
	int n = n_ + 1;
	int* coefs = new int[n + 1];
	coefs[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		coefs[i] = coefs_[i - 1] / i;
	}
	polynom result(n, coefs);
	delete[] coefs;
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
	printcoefs(os);
	os << endl << "Derivative: ";
	polynom d = Derivative();
	d.printcoefs(os);
	os << endl << "Integral: ";
	polynom i = Integral();
	i.printcoefs(os);
	os << "+Constant" << endl;
}
