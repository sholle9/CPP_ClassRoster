
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// this will change values by using functions of mutators from student.h that is why the "void"
void Student::SetStudentID(string newID) {
	this->studentID = newID;				//use the 'this' when talking about a field inside an object
}
void Student::SetFirstName(string newFirst) {
	this->firstName = newFirst;
}
void Student::SetLastName(string newLast) {
	this->lastName = newLast;
}
void Student::SetEmailAddress(string newEmail) {
	this->emailAddress = newEmail;
}
void Student::SetAge(int newAge) {
	this->age = newAge;
}
void Student::SetNumDays(int newDays[]) {
	for(int i = 0; i < numDaysArraySize; i++) this->numDays[i] = newDays[i]; //sets each day individually
}
void Student::SetDegreeProgram(DegreeProgram newDegree) {
	this->degreeProgram = newDegree;
}

// this will return a value therefore needs int or string and return function
string Student::GetStudentID() const {
	return this->studentID;
}
string Student::GetFirstName() const {
	return this->firstName;
}
string Student::GetLastName() const {
	return this->lastName;
}
string Student::GetEmailAddress() const {
	return this->emailAddress;
}
int Student::GetAge() const {
	return this->age;
}
int* Student::GetNumDays(){
	return this->numDays;//not anarray here 'this->' make a pointer so no '[]'
}
DegreeProgram Student::GetDegreeProgram() const {
	return this->degreeProgram;
}

//Constructor Default if we had no imput each category would be represented
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;//the object is the class of enum SOFTWARE
}

//Non-Default Constructor when we have input for each category
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram) { 
	this->studentID = studentID;//field is equated to parameter
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; i++)this->numDays[i] = numDays[i];
	this->degreeProgram = degreeProgram;
}

//Deconstructor - doesn't do anything for this program, just good practice
Student::~Student(){}

void Student::print(){
	cout << this->GetStudentID() << '\t';
	cout << "First Name: " << this->GetFirstName() << '\t';
	cout << "Last Name: " << this->GetLastName() << '\t';
	cout << "Email: " << this->GetEmailAddress() << '\t';
	cout << "Age: " << this->GetAge() << '\t';
	cout << "daysInCourse: {" << this->GetNumDays()[0] << ',';
	cout << this->GetNumDays()[1] << ',';
	cout << this->GetNumDays()[2] << "}" << '\t';
	cout << "Degree Program: " << degreeProgramString[this->GetDegreeProgram()] << endl; //the string 'degreeProgramString' takes the enum(or number) into the array and prints the corresponding string
}