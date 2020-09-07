#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student // SoftwareStudent is a type of Student, so it inherits from Student class
{
public:
     SoftwareStudent();  //The Empty Constructor
     SoftwareStudent(  // The Full Constructor
         string studentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse[],
         Degree degreeProgram);

    //Virtual Methods - Creating the SoftwareStudent Objects
     Degree GetDegreeProgram();
     void print();

     //destructor
     ~SoftwareStudent();
};
