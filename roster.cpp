#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

void Roster::parse(string studentData) {
	int rhs = studentData.find(","); // find the comma
	string sID = studentData.substr(0, rhs); // starting at 0 count over to the rhs value

	int lhs = rhs + 1; // lhs is the char count past the ','
	rhs = studentData.find(",", lhs);// find the next ',' after the previous substring
	string fName = studentData.substr(lhs, rhs - lhs);// the first char of the string begins at lhs, then the end char is rhs - lhs from the 0 char of the studentData string 

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string eAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int A = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dCourse1 = stoi(studentData.substr(lhs, rhs - lhs)); // stoi() takes the string argument and returns an int value

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	DegreeProgram dProgram = SOFTWARE;//have to initialize first as a default so it can run automatically then run through if/else statements
	if (studentData.at(lhs) == 'S') {
		if (studentData.at(lhs + 1) == 'E') {
			dProgram = SECURITY;
		}
		else {
			dProgram = SOFTWARE;
		}
	}
	else {
		dProgram = NETWORK;
	}


	add(sID, fName, lName, eAddress, A, dCourse1, dCourse2, dCourse3, dProgram);

}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int parsedDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; // create an array for the 'new Student' object
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parsedDays, degreeProgram);// theis will creaate the overload constructor
}

void Roster::printAll() {///prints list of all student data from the table by calling the print() method in student.h
	
	for (int i = 0; i <= Roster::lastIndex; i++) { //lastIndex is no longer -1 because the parse/add function must be run before the print or remove functions
		cout << classRosterArray[i]->GetStudentID() << '\t';
		cout << "First Name: " << classRosterArray[i]->GetFirstName() << '\t';
		cout << "Last Name: " << classRosterArray[i]->GetLastName() << '\t';
		cout << "Email: " << classRosterArray[i]->GetEmailAddress() << '\t';
		cout << "Age: " << classRosterArray[i]->GetAge() << '\t';
		cout << "daysInCourse: {" << classRosterArray[i]->GetNumDays()[0] << ',';
		cout << classRosterArray[i]->GetNumDays()[1] << ',';
		cout << classRosterArray[i]->GetNumDays()[2] << "}" << '\t';
		cout << "Degree Program: " << degreeProgramString[classRosterArray[i]->GetDegreeProgram()] << endl;
	}
	
}
void Roster::printAverageDaysInCourse(string studentID) {//prints average number days in the course
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->GetStudentID() == studentID) {
			cout << "Student ID: " << classRosterArray[i]->GetStudentID() << ", averages  ";
			cout << (classRosterArray[i]->GetNumDays()[0] + classRosterArray[i]->GetNumDays()[1] + classRosterArray[i]->GetNumDays()[2]) / 3;
			cout << " days in a course.";
		}
	}
	cout << endl;
}
void Roster::printInvalidEmails() {//prints emails that don't have '@' or '.' or prints if emal has a ' '
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string eAddress = (classRosterArray[i]->GetEmailAddress());
		if (eAddress.find(' ') != string::npos) {
			cout << classRosterArray[i]->GetEmailAddress() << " - no spaces allowed." << endl;
		}
		else if (eAddress.find('@') == string::npos) {
			cout << classRosterArray[i]->GetEmailAddress() << " - missing an @ symbol." << endl;
		}
		else if (eAddress.find('.') == string::npos) {
			cout << classRosterArray[i]->GetEmailAddress() << " - missing a period." << endl;
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) { // prints student info by enumeration type
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}
void Roster::remove(string studentID) {// find student by ID and remove
	int x = 0;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex-1];
			this->classRosterArray[lastIndex - 1] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
		else {
			x++;				//FIXME
		}
		
	}
	if (x == 4) {
		cout << "Student with ID: " << studentID << " was not found." << endl;
	}

}

//Deconstructor - good practice
Roster::~Roster() {
	for (int i = 0; i < Roster::lastIndex; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}