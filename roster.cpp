#include "degree.h"
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <string>
using namespace std;



Roster::Roster()  //The Empty Constructor sets to default values
{
     this->capacity = 0;
     this->lastIndex = -1;  // Means empty
     this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) //The Constructor that sets max capacity for roster
{
     this->capacity = capacity;
     this->lastIndex = -1;
     this->classRosterArray = new Student * [capacity];
}

Student * Roster::GetStudentAt(int lastIndex)
{
     return classRosterArray[lastIndex];
}

// parse studentData and add each student to Roster.
void Roster::parseThenAdd(string row)
 {
     Degree degreeProgram;
     
     //read student ID in row studentData[i]
     int rhs = row.find(",");
     string studentIDTemp = row.substr(0, rhs);

     //read firstName
     int lhs = rhs + 1;
     rhs = row.find(",", lhs);
     string firstNameTemp = row.substr(lhs, rhs - lhs);

     //read lastName
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     string lastNameTemp = row.substr(lhs, rhs - lhs);

     //read emailAddress
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     string emailAddressTemp = row.substr(lhs, rhs - lhs);

     //read age
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     int ageTemp = std::stoi(row.substr(lhs, rhs - lhs));  // convert string to int using std::stoi( str )

     //read course days 1 value
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     int courseDays1Temp = std::stoi(row.substr(lhs, rhs - lhs));  // convert string to int using std::stoi( str )

     //read course days 2 value
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     int courseDays2Temp = std::stoi(row.substr(lhs, rhs - lhs));  // convert string to int using std::stoi( str )

     //read course days 3 value
     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     int courseDays3Temp = std::stoi(row.substr(lhs, rhs - lhs));  // convert string to int using std::stoi( str )

     lhs = rhs + 1;
     rhs = row.find(",", lhs);
     string degreeProgramTemp = row.substr(lhs, rhs - lhs);

     if (degreeProgramTemp == "SECURITY")
     {
         degreeProgram = SECURITY;
     }
     else if (degreeProgramTemp == "NETWORK") {
         degreeProgram = NETWORK;
     }
     else if (degreeProgramTemp == "SOFTWARE") {
         degreeProgram = SOFTWARE;
     }
     else
     {
         cerr << "INVALID DEGREE PROGRAM!"  << endl << "EXITING NOW!"  << endl;
         exit(-1);
     }

     //add the students to the roster, objects for each student class will be created in ADD method
     add(studentIDTemp, firstNameTemp, lastNameTemp, emailAddressTemp, ageTemp, courseDays1Temp, courseDays2Temp, courseDays3Temp, degreeProgram);
}

// Sets the instance variables from Student and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

     lastIndex++;

     if (degreeProgram == SECURITY ) {
          int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
          classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
     }
     if (degreeProgram == NETWORK) {
          int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
          classRosterArray[lastIndex] =  new NetworkStudent(studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
     }
     if (degreeProgram == SOFTWARE) {
          int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
          classRosterArray[lastIndex] =  new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, courseDaysArray, degreeProgram);
     }
}

// Prints a complete tab-separated list of student data
void Roster::printAll() {
     for (int i = 0; i <= this->lastIndex; i++) {
          (this->classRosterArray)[i]->print();
     }
}

//Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string id)
{
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "\t" << "ERROR: Student with ID: " << id << " not found" << endl;
            break;
        }
        else if (id == classRosterArray[i]->GetStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "\t" << "Student removed" << endl;
        }
    }

}

// Verifies student email addresses and displays all invalid email addresses to the user.
// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
    for (int i = 0; i < lastIndex; i++) {
        string tempEmail = classRosterArray[i]->GetEmailAddress();
        if ((tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) || (tempEmail.find(" ") != string::npos)) {
            cout << "\t" << tempEmail << endl;
        }
    }
}

// Prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
     int average = 0;
     for (int i = 0; i <= lastIndex; ++i) {
         string tempID = classRosterArray[i]->GetStudentID();
          if (tempID == studentID) {
              average = ((classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1] + classRosterArray[i]->GetDaysInCourse()[2]) / 3);
              cout << "\t" << "Student ID " << studentID << " average is: " << average << endl;
          }
     }
}

// Prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(int degreeProgram) {
     for (int i = 0; i <= lastIndex; i++) {
          if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
     }
}

// Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster() {
}


int main()
{
    int numStudents = 5;
    
    string studentData[5] =  //Input is 5 long coma-delimited strings
    {
          "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
          "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
          "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
          "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
          "A5,Joseph,Thoma,jtho543@wgu.edu,43,50,40,30,SOFTWARE"
    };

    //Print the course title, the programming language used, your WGU student ID, and your name.
    cout << "Course:  Scripting and Programming - Applications – C867" << endl;
    cout << "Programming language: C++" << endl;
    cout << "Student ID: #000725894" << endl;
    cout << "Name:  Joseph Thoma" << endl << endl;

    // Makes the roster
    Roster * classRoster = new Roster(numStudents);
    cout << "Parsing Data and adding students: ";
    for (int i = 0; i < numStudents; i++)
    {
          classRoster->parseThenAdd(studentData[i]);  // Parse each line, Turn them into Students and add them to the roster.
    }
    cout << "DONE!" << endl <<endl;
    
    // Prints a complete tab-separated list of student data
    cout << "Student Data: " << endl;
    classRoster->printAll();
    cout << endl << endl;
    
    // Verifies student email addresses and displays all invalid email addresses to the user.
    cout << "Checking for invalid emails: " << endl;
    classRoster->printInvalidEmails();
    cout << endl << endl;

    // Prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    cout << "Average days in course per student:" << endl;
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;

    // Prints out student information for a degree program specified by an enumerated type.
    cout << endl;
    cout << "Printing out student information based on specified degree program:  SOFTWARE" << endl << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    //Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
    cout << endl << endl;
    cout << "Removing Student ID A3:" << endl;
    classRoster->remove("A3");
    classRoster->remove("A3");  // Remove same student twice to check error condition

    //Implement the destructor to release the memory that was allocated dynamically in Roster.
    cout << endl << endl;
    cout << "The desctructor has been called." << endl << endl;
    classRoster->~Roster();

    return 0;
}

