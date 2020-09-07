#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
using std::string;

class Student {  //This class represents the Students
public:  // Visible everywhere in the application
    const static int daysInCourseArraySize = 3;

protected:  //visible to derived classes
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysInCourseArraySize];  //Number of days in course will be an array size of 3
    Degree degreeProgram;  // Vitural method for Degree Program
    
public:  //Visible everywhere in the application
    Student(); //The Empty Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]); // The Full Constructor
        
        // Accessors (Getters)
        string GetStudentID();
        string GetFirstName();
        string GetLastName();
        string GetEmailAddress();
        int GetAge();
        int* GetDaysInCourse();
        virtual Degree GetDegreeProgram() = 0;  // Virtual method
    
        // Mutators (Setters)
        void SetStudentId(string studentID);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmailAddress(string emailAddress);
        void SetAge(int age);
        void SetDaysInCourse(int daysInCourse []);
        
        virtual void print() = 0;
        
        // Deconstructor
        ~Student();
};

