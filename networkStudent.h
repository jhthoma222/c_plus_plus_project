#pragma once
#include <string>
#include "student.h"

class NetworkStudent : public Student // NetworkStudent is a type of Student, so it inherits from Student class
{
public:
     NetworkStudent();  //The Empty Constructor
     NetworkStudent(  //The Full Constructor
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse[],
        Degree degreeProgram
    );

    //Virtual Methods - Creating the NewtworkStudent Objects
     Degree GetDegreeProgram();
     void print();

     //The Destructor
     ~NetworkStudent();
};
