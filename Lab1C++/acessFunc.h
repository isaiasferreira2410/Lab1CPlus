// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2


#ifndef ACCESSFUNC_H
#define ACCESSFUNC_H
#include "student.h"
#include <iostream>
#include <string>
using namespace std;
class Func{
	public:
		void registers(string, Student&);
		void show(Student&);
		void consult(string, Student&, int);
		void list(string, Student&);
		void listRemove(string, Student&);
		void update(string, Student&, int);
		void delet(string, Student&, int);
};
#endif
