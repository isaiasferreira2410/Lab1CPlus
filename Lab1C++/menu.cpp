// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "acessFunc.h"
#include "newnumber.h"
#include "student.h"
#include "menu.h"
using namespace std;

void Menu:: menu(string fileName){
    Func f;
    Student estudant;
    NewNumber num;
    int keepOn,choose,stNumber;
    int nE,idad,ano;
    char fname[100],lname[100],curso[30],grupo[15],genero[10];
    a:
    cout <<setw(5)<<"|====================================================|"<<endl;
    cout <<setw(5)<<"|===============> Student Management <===============|"<<endl;
    cout <<setw(5)<<"|===============> Main Menu          <===============|"<<endl;
    cout <<setw(5)<<"|====================================================|"<<endl;
    cout <<setw(5)<<"|===============>    Student Data    <===============|"<<endl;
    cout <<setw(5)<<"|1)====> Register                    <===============|"<<endl;
    cout <<setw(5)<<"|2)====> Consult                     <===============|"<<endl;
    cout <<setw(5)<<"|3)====> List of                     <===============|"<<endl;
    cout <<setw(5)<<"|4)====> Update                      <===============|"<<endl;
    cout <<setw(5)<<"|5)====> Remove                      <===============|"<<endl;
    cout <<setw(5)<<"|6)====> List Remove Student         <===============|"<<endl;
    cout <<setw(5)<<"|====================================================|"<<endl;
    cout <<setw(5)<<"|0)====> GET OUT(EXIT)               <===============|"<<endl;
    cout <<setw(5)<<"|====================================================|"<<endl;
    cout <<setw(5)<<"|=====> Choose an option: "; cin >> choose;
    switch(choose){
        case 1:{
            do{
                //system("pause");
                cout << endl;
                cout <<setw(5)<<"|==================================================|"<<endl;
                cout <<setw(5)<<"|===============> Register Student <===============|"<<endl;
                cout <<setw(5)<<"|==================================================|"<<endl;
                estudant.setState(true);
                nE = num.newNumber(fileName,sizeof(Student));
                setbuf(stdin,NULL);
                cout << "Enter the student's last name: "; cin.getline(lname,100);
                setbuf(stdin,NULL);
                cout << "Enter the student's first name: "; cin.getline(fname,100);
                setbuf(stdin,NULL);
                cout << "Enter the age of the student: "; cin >> idad;
                setbuf(stdin,NULL);
                cout << "Enter the gender of the student: "; cin.getline(genero,10);
                setbuf(stdin,NULL);
                cout << "Enter student course: "; cin.getline(curso,30);
                setbuf(stdin,NULL);
                cout << "Enter student group: "; cin.getline(grupo,15);
                setbuf(stdin,NULL);
                cout << "What year is the student in: "; cin >> ano;
                setbuf(stdin,NULL);
                estudant.auxiliar(nE, fname, lname, idad, genero, curso, grupo, ano);
                f.registers(fileName,estudant);
                cout <<endl<<endl<<"Consult another Student (YES = 1 / NO = 0): "; cin >> keepOn;
            }while(keepOn == 1);
            goto a;
            break;
        }
        case 2:{
            do{
                //system("cls");
                cout <<endl;
                cout <<setw(5)<<"|=================================================|"<<endl;
                cout <<setw(5)<<"|===============> Consult Student <===============|"<<endl;
                cout <<setw(5)<<"|=================================================|"<<endl;
                cout <<setw(5)<<"|>>>>Student number you want to consult: ";
                cin >> stNumber;
                f.consult(fileName,estudant,stNumber);
                cout <<endl<<endl<<"Consult another Student? (YES = 1 / NO = 0): "; cin >> keepOn;
            }while(keepOn == 1);
            goto a;
            break;
        }
        case 3:
            f.list(fileName,estudant);
            cout << endl;
            goto a;
            break;
        case 4:{
            do{
                cout <<setw(5)<<"Enter the number of student who wants to update information: "; cin >> stNumber;
                f.consult(fileName,estudant,stNumber);
                cout << endl;
                setbuf(stdin,NULL);
                cout << "Enter the student's last name: "; cin.getline(lname,100);
                setbuf(stdin,NULL);
                cout << "Enter the student's first name: "; cin.getline(fname,100);
                setbuf(stdin,NULL);
                cout << "Enter the age of the student: "; cin >> idad;
                setbuf(stdin,NULL);
                cout << "Enter the gender of the student: "; cin.getline(genero,10);
                setbuf(stdin,NULL);
                cout << "Enter student course: "; cin.getline(curso,30);
                setbuf(stdin,NULL);
                cout << "Enter student group: "; cin.getline(grupo,15);
                setbuf(stdin,NULL);
                cout << "What year is the student in: "; cin >> ano;
                setbuf(stdin,NULL);
                estudant.aux(fname,lname,idad,genero,curso,grupo,ano);
                f.update(fileName,estudant,stNumber);
                cout <<endl<<endl<<"Want to update another student's information? (YES = 1 / NO = 0): "; cin >> keepOn;
            }while(keepOn == 1);
            goto a;
            break;
        }
        case 5:{
            do{
                cout <<setw(5)<<"Enter the number of student who wants you wish to remove from the list: "; cin >> stNumber;
                f.delet(fileName,estudant,stNumber);
                cout <<endl<<endl<<"You want to remove another student? (YES = 1 / NO = 0): "; cin >> keepOn;
            }while(keepOn == 1);
            goto a;
            break;
        }
        case 6:
            f.listRemove(fileName,estudant);
            cout << endl;
            goto a;
            break;
        case 0:
            exit(0); break;
        default:
            cout <<setw(5)<<"Invalid Option!!!"<<endl; break;
    }
}
