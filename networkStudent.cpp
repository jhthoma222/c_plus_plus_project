#include <iostream>
#include "networkStudent.h"
using std::cout;


NetworkStudent::NetworkStudent() :Student() // This Empty Constructor sets the Degree Program to NETWORK
{
    degreeProgram = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeProgram)
     : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)  //The Full Constructor
{
     degreeProgram = NETWORK;
}

Degree NetworkStudent::GetDegreeProgram()
{
     return NETWORK;  // Now it is not virtual anymore.
}

void NetworkStudent::print()
{
     this->Student::print();  // Calls the print methond from the Student class
     cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent()
{
     Student::~Student();  //Super Deconstructor
}
