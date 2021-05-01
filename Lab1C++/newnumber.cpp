// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2

#include <iostream>
#include <fstream>
#include "newnumber.h"
using namespace std;
int NewNumber :: newNumber(string fileName, int sizeClass){
    long sizeFile;
    fstream file(fileName,ios::in);

    file.seekg(0,ios::end);
    sizeFile = file.tellg();
    file.close();

    return (sizeFile / sizeClass) + 1;
}

