#include "compfunc.h"

template <class F, class G>
compfunc<F,G>::compfunc() : f_() , g_() {
}

template <class F, class G>
compfunc<F,G>::compfunc(const F& f, const G& g) : f_(f) , g_(g) {
}

template <class F, class G>
compfunc<F, G>::~compfunc() {
}

template <class F, class G>
int compfunc<F, G>::operator[](const int& x) const {
	int tmp = g_[x] ;
	return f_[tmp] ;
}

template <class F, class G>
void compfunc<F, G>::print(ostream& os) {
	os << endl ;
}