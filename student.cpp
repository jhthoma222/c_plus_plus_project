#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;
using std::cout;

Student::Student() { //The Empty Constructor - Set to default values
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]) { //The Full Constructor
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}

// Getters
string Student::GetStudentID() {
        return studentID;
    }
string Student::GetFirstName() {
        return firstName;
    }
string Student::GetLastName() {
        return lastName;
    }
string Student::GetEmailAddress() {
        return emailAddress;
    }
int Student::GetAge() {
        return age;
    }
int * Student::GetDaysInCourse() {
        return daysInCourse;
    }

// Setters
void Student::SetStudentId(string studentID) {
        this->studentID = studentID;
    }
void Student::SetFirstName(string firstName) {
        this->firstName = firstName;
    }
void Student::SetLastName(string lastName) {
        this->lastName = lastName;
    }
void Student::SetEmailAddress(string emailAddress) {
        this->emailAddress = emailAddress;
    }
void Student::SetAge(int age) {
    this->age = age;
    }
void Student::SetDaysInCourse(int daysInCourse[]) {
        for (int i = 0; i < daysInCourseArraySize; i++){
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::print() {
        cout << "\t" << "First Name: " << firstName << "\t";
        cout << "Last Name: " << lastName << "\t";
        cout << "Email Address: " << emailAddress << "\t";
        cout << "Age: " << age << "\t";
        cout << "Days In Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "\t";
        cout << "Degree Program: ";
}

// THe Deconstructor
Student::~Student() {}
