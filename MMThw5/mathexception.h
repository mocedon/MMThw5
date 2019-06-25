#ifndef _MATH_EXCEPTION
#define _MATH_EXCEPTION

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdexcept>
#include <cstring>

using std::exception;

class mathexception : public exception {
public:
	mathexception(const char* expt);
	~mathexception();
	const char* what() const throw();
protected:
	char* warning_;
};

#endif