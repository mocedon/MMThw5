#include "mathexception.h"

mathexception::mathexception(const char* expt) :  warning_(new char[strlen(expt)+1]) {
	strcpy(warning_, expt);
}

mathexception::~mathexception() {
	delete[] warning_;
}

const char* mathexception::what() const throw() {
	return warning_;
}