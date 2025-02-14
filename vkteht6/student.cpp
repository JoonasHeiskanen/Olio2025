#include "student.h"



Student::Student(int a, string n)
{
    age = a;
    name = n;
}



void Student::setAge(int a)
{
    age = a;
}



void Student::setName(string n)
{
    name = n;
}



string Student::getName()
{
    return name;
}



int Student::getAge()
{
    return age;
}



void Student::printStudentinfo()
{

    cout << "Student name: " << getName() << " age: " << getAge() << endl;
}
