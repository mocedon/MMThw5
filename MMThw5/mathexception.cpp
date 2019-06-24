#include "mathexception.h"

mathexception::mathexception(const char* warning) :  warning_(new char[strlen(warning)+1]) {
	strcpy(warning_, warning);
}

mathexception::~mathexception() {
	delete[] warning_;
}

const char* mathexception::what() const throw {
	return warning_;
}