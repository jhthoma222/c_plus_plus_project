#pragma once
#include <string>
#include "student.h"


class SecurityStudent : public Student // SecurityStudent is a type of Student, so it inherits from Student class
{
public:
     SecurityStudent();  //The Empty Constructor
     SecurityStudent(  //The Full Constructor
         string studentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse[],
         Degree degreeProgram
     );

     //Virtual Methods - Creating the SecurityStudent Objects
     Degree GetDegreeProgram();
     void print();

     // The Destructor
     ~SecurityStudent();
};
