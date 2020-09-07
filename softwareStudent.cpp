#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student() // This Empty Constructor sets the Degree Program to SOFTWARE
{
     degreeProgram = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeProgram)
     : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)   //The Full Constructor
{
     degreeProgram = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeProgram()
{
     return SOFTWARE;
}

void SoftwareStudent::print()
{
     this->Student::print();
     cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
     Student::~Student(); //Super Deconstructor
}
