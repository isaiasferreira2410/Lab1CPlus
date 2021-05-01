// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "acessFunc.h"
#include "student.h"
using namespace std;

//= new File();
void Func:: registers(string nameFile, Student& student){
    fstream file(nameFile,ios::app);
    //student.state = true;
    if(file){
         file.write((char*)&student,sizeof(Student));
         cout << endl << "Student Successfully Registred!!" <<endl;
    }
    else
        cout << "Recording file"<<endl;
    file.close();
}

void Func :: show(Student& student){
    cout << endl;
    cout <<"Student Number: "<<student.getNumber()<<endl;
    cout <<"Full Name: "<<student.getFirstName()<<" " <<student.getLastName()<<endl;
    cout <<"Age: "<<student.getAge()<<endl;
    cout <<"Gender: "<<student.getGender()<<endl;
    cout <<"Course: "<<student.getCourse()<<endl;
    cout <<"Group: "<<student.getGroup()<<endl;
    cout <<"Year of course: "<<student.getYear()<<endl;
}

void Func :: list(string nameFile, Student& student){
    fstream file (nameFile,ios::in);
    cout <<setw(5)<<"|=================================================|"<<endl;
    cout <<setw(5)<<"|===============> General Listing <===============|"<<endl;
    cout <<setw(5)<<"|===============> Data of all Student <===========|"<<endl;
    cout <<setw(5)<<"|=================================================|"<<endl;
    file.seekg(0);
    if(file){
        do{
            file.read((char*)&student,sizeof(Student));
            if(file.eof() == 0 && student.state == true)
                this->show(student);
        }while(file.eof()==0);
        file.close();
    }
}

void Func:: consult(string nameFile, Student& student, int numStudent){
    fstream file (nameFile,ios::in);
    int keepOn;
        file.seekg(0);
        if(file){
            do{
                file.read((char*)&student,sizeof(Student));
                if(numStudent == student.numberStudent && student.state == true){
                    cout <<setw(5)<<"|==============================================|"<<endl;
                    cout <<setw(5)<<"|===============> Student Data <===============|"<<endl;
                    cout <<setw(5)<<"|==============================================|"<<endl;
                    this->show(student);
                }
            }while(file.eof() == 0 && numStudent != student.numberStudent);
            if(numStudent != student.numberStudent || student.state == false) {cout << endl<<"Student not found!!"<<endl; }
        }else{
            cout <<"Erro de Leitura"<<endl;
            abort();
        }
        file.close();
}

void Func:: update(string nameFile, Student& student, int numStudent){
   fstream file(nameFile,ios:: in | ios:: out);
   int answer;
   if(file){
        file.seekg(((numStudent - 1) * sizeof(Student)),ios::cur);
        file.read((char*)&student,sizeof(Student));
        if(numStudent == student.numberStudent && student.state == true){
            this->show(student);
            cout <<setw(5)<<"Do you want to update the information shown above? (YES = 1 / NO = 0): ";
            cin >> answer;
            if(answer == 1){
                file.seekg((-1 * sizeof(Student)),ios::cur);
                file.write((char*)&student,sizeof(Student));
                if(!file.good())
                    cout <<endl<<setw(5)<<"Student information updated successfully!!"<<endl;
                else
                    cout <<endl<<setw(5)<<"Recording Error!!"<<endl;
            }
        }
        else{
            cout <<endl<<setw(5)<<"Invalid student number!!!"<<endl;
            cout <<"Press </Enter> to continue...";
            system ("pause");
        }
    }
    else{
            cout <<"Erro de Leitura!"<<endl;
            abort();
        }
    file.close();
}

void Func:: listRemove(string nameFile, Student& student){
    fstream file (nameFile,ios::in);
    cout <<endl;
    cout <<setw(5)<<"|=================================================|"<<endl;
    cout <<setw(5)<<"|===============> General Listing  <==============|"<<endl;
    cout <<setw(5)<<"|===============> Students Removed <==============|"<<endl;
    cout <<setw(5)<<"|=================================================|"<<endl;
    file.seekg(0);
    if(file){
        do{
            file.read((char*)&student,sizeof(Student));
            if(file.eof() == 0 && student.state == false)
                this -> show(student);
        }while(file.eof() == 0);
        file.close();
    }
    else{
        cout <<"Error de Leitura!"<<endl;
        abort();
    }
}

void Func:: delet(string nameFile, Student& student, int numStudent){
    fstream file (nameFile,ios::in | ios :: out);
    int answer;
    if(file){
        file.seekg(((numStudent - 1) * sizeof(Student)),ios::cur);
        file.read((char*)&student,sizeof(Student));
        if(numStudent == student.numberStudent && student.state == true){
            this -> show(student);
            cout <<setw(5)<<"Do you want to delete the data shown above? (YES = 1 / NO = 0): "; cin >> answer;
            if(answer == 1){
                student.state = false;
                file.seekg((-1 * sizeof(Student)),ios::cur);
                file.write((char*)&student,sizeof(Student));
                if(file.good())
                    cout <<endl<<"Successfully removed!!"<<endl;
                else
                    cout <<endl<<"Error while removing!!"<<endl;
            }
        }
        else{
            cout <<endl<<"Invalid Student number!!!"<<endl;
        }
    }
    else{
        cout <<"Error de Leitura!"<<endl;
        abort();
    }
    file.close();
}
