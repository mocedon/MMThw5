#ifndef _MATH_EXCEPTION
#define _MATH_EXCEPTION

#include <stdexcept>
#include <string>

using std::exception;

class mathexception : public exception {
public:
	mathexception(const char* warning);
	~mathexception();
	const char* what() const throw;
protected:
	char* warning_;
};

#endif