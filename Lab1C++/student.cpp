// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;
void Student :: auxiliar(int number, const char *fn, const char *ln,int idade, const char *genero, const char *curso, const char *grupo, int ano){
    setNumber(number);
    setFirstName(fn);
    setLastName(ln);
    setAge(idade);
    setGender(genero);
    setGroup(grupo);
    setCourse(curso);
    setYear(ano);
}
void Student :: aux(const char *fn, const char *ln, int idade, const char *genero, const char *curso, const char *grupo, int ano){
    setFirstName(fn);
    setLastName(ln);
    setAge(idade);
    setGender(genero);
    setGroup(grupo);
    setCourse(curso);
    setYear(ano);
}
void Student :: setNumber(int num){ numberStudent = num; }
int Student :: getNumber() {return numberStudent; }
void Student :: setFirstName(const char *fname){ strcpy(firstName,fname); }
char* Student::getFirstName(){ return firstName; }

void Student :: setLastName(const char *lname){ strcpy(lastName,lname); }
char* Student :: getLastName(){ return lastName; }

void Student :: setAge(int idad){ age = idad; }
int Student :: getAge(){ return age; }

void Student :: setGender(const char *sexo){ strcpy(gender,sexo); }
char* Student :: getGender(){ return gender; }

void Student :: setCourse(const char *curs){ strcpy(course,curs); }
char* Student :: getCourse(){ return course; }

void Student :: setGroup(const char *grup){ strcpy(group,grup); }
char* Student :: getGroup(){ return group; }

void Student :: setYear(int year){ year_course = year; }
int Student :: getYear(){ return year_course; }

void Student :: setState(bool y){ state = y;}


