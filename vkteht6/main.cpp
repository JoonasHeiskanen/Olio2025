#include <iostream>
#include <vector>
#include "student.h"
#include <algorithm>

using namespace std;

int main ()
{

    int selection =0;
    vector<Student>studentList;
    int age;
    string name;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:

            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout << "Give student age: " << endl;
            cin >> age;
            cout << "Give student name: " << endl;
            cin >> name;
            studentList.push_back(Student(age, name));
            break;

        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for (auto student : studentList){
                cout << "Student name: " << student.getName();
                cout << " age: " << student.getAge() << endl;
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getName() < b.getName();
            });
            cout << "Printing the students data: " << endl;
            for (auto student : studentList){
                student.printStudentinfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b) {
                return a.getAge() > b.getAge();
            });
            for (auto student : studentList){
                student.printStudentinfo();
            }
            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout << "Give student to be found name: " << endl;
            cin >> name;
            auto it = find_if(studentList.begin(), studentList.end(), [name](Student& toBeFound) {
                return name == toBeFound.getName();
            });
            if (it != studentList.end()){
                cout << "Student found! " << it->getName() << endl;
            }
            else{
                cout << "Student not found" << endl;
            }
        }
            break;

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }while(selection < 5);

    return 0;
}
