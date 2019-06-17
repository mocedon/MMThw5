#ifndef _F
#define _F
#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::vector;
using std::ostream;

class func {
public:
	func();
	int operator[](const int&x) const = 0; //calculates f(x)
	func& operator<<(const int&x); //adds (x,f(x)) to fmap_
	friend ostream& operator<<(ostream& os, const func& f) = 0;
 protected:  
  int maxVal_; //maximum of all inputs
  int minVal_; //minimum of all inputs
  map<int,int> fmap_; //holds inputs and corresponding outputs
  void plot(ostream& os) const ; //plot fmap_
};

#endif
