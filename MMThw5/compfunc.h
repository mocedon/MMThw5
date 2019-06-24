#ifndef _COMP_F
#define _COMP_F

#include "func.h"
#include "polynom.h"
#include "ratfunc.h"

using namespace std ;

template <class F, class G>
class compfunc : public func {
public:
	compfunc() ;
	compfunc(const F& f , const G& g) ;
	~compfunc() ;

	int operator[](const int& x) const ;

protected:
	F f_ ;
	G g_ ;
	void print(ostream& os);

};


#endif