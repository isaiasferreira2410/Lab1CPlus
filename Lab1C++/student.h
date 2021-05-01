// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;
class Student{
	private:
		int numberStudent;
		char firstName[100];
    char lastName[100];
		int age;
		char gender[10];
		char group[10];
		char course[30];
		int year_course;
		bool state;
  public:
    void auxiliar(int, const char*,const char*, int,const char*, const char*, const char*, int);
    void aux(const char*, const char*, int,const char*, const char*, const char*, int);
    void setNumber(int);
    int getNumber();
    void setFirstName(const char*);
    char* getFirstName();
    void setLastName(const char*);
    char* getLastName();
    void setAge(int);
    int getAge();
    void setGender(const char*);
    char* getGender();
    void setGroup(const char*);
    char* getGroup();
    void setCourse(const char*);
    char* getCourse();
    void setYear(int);
    int getYear();
    void setState(bool);
    friend class Func;
    friend class NewNumber;
};
#endif
