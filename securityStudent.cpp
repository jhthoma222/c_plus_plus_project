#include <iostream>
#include "securityStudent.h"
using std::cout;


SecurityStudent::SecurityStudent():Student() // This Empty Constructor sets the Degree Program to SECURITY
{
     degreeProgram = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreePprogram)
     : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)   //The Full Constructor
{
     degreeProgram = SECURITY;
}

Degree SecurityStudent::GetDegreeProgram()
{
     return SECURITY;
}

void SecurityStudent::print()
{
     this->Student::print();
     cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
     Student::~Student(); //Super Deconstructor
}

