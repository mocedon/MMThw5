#include "compfunc.h"

compfunc::compfunc() : f_(NULL) , g_(NULL) {
}

compfunc::compfunc(const func& f, const func& g) : f_(&f) , g_(&g) {
}

compfunc::~compfunc() {
}

int compfunc::operator[](const int& x) const {
	int tmp = *g_[x];
	return *f_[tmp];
}

void compfunc::print(ostream& os) {
	os << endl;
}