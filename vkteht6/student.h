#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(int, string);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentinfo();

private:
    string name;
    int age;
};

#endif // STUDENT_H
