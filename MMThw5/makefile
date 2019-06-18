#This makefile was generated automatically by MakeMake

#Definitions

CC=g++
CXXFLAGS=-g -Wall -std=c++11
CCLINK=g++
LIBS=
OBJS=ratfunc.o polynom.o mathexception.o main.o func.o compfunc.o 
RM=rm -f
Target=WolfraMamat

$(Target): $(OBJS)
	  $(CCLINK) -o $(Target) $(OBJS) $(LIBS)

#Dependencies

compfunc.o: compfunc.cpp compfunc.h func.h
func.o: func.cpp func.h
main.o: main.cpp func.h polynom.h ratfunc.h compfunc.h
mathexception.o: mathexception.cpp mathexception.h
polynom.o: polynom.cpp polynom.h func.h
ratfunc.o: ratfunc.cpp ratfunc.h polynom.h func.h mathexception.h

#Clean

clean:
	  $(RM) WolfraMamat *.o *.bak *~ "#"* core
