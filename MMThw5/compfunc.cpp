#include "compfunc.h"

compfunc::compfunc() : f_(NULL) , g_(NULL) {
}

compfunc::compfunc(func& f, func& g) : f_(&f) , g_(&g) {
}

compfunc::~compfunc() {
}

int compfunc::operator[](const int& x) const {
	int tmp = (*g_)[x];
	return (*f_)[tmp];
}

void compfunc::print(ostream& os) const {
	os << endl;
}