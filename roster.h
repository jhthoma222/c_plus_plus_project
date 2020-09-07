
#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"



class Roster // Roster stores the collection of Students
{
private:
     int lastIndex;  // Index of last student in roster, also affects how many entries are in roster
     int capacity;  // The max size of the roster
     Student** classRosterArray;  // classRosterArray is an array of points to students, indicated by **
public:
     Roster();  // The Empty constructor creates a roster and initializes default values
     Roster(int capacity);  //This constructor creates roster, initializes default values, and sets max size.

     Student* GetStudentAt(int index);
     void parseThenAdd(string datarow);  // Parses the strings, creates the Student objects, and adds them to roster.
     void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
          int daysInCourse2, int daysInCourse3, Degree degreeProgram);  //  Sets the instance variables and updates the roster.
     void printAll();  // Prints all the students in the roster using each student's print() method.
     void remove(string studentID);  // Removes students from the roster by student ID. If the student ID does not exist, the function prints student was not found.
     bool checkNumStudents(int numStudents);
     void printAverageDaysInCourse(string studentID);  // Prints a student’s average number of days in course.
     void printInvalidEmails();  // Verifies student email addresses and displays all invalid email addresses to the user.
     void printByDegreeProgram(int degreeProgram);  //Prints out students info per degree program
     
    
     ~Roster();  //Descructor destroys the roster, releasing any resources it requested dynamically
};
