#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster
{
private:
	int lastIndex = -1; //used to go through the array of students  //set to -1 so that the array correctly ends at final value not 1 greater
	const static int numStudents = 5; //as in student.h an array needs a set number of entries otherwise if you need dynamic, you would use vector<int>
	Student* classRosterArray[numStudents]; //pointer to the student data in class type 'Student'

public:

	//Mutators
	void parse(string studentData);
	/*need to seperate the 3 days because with parsing it will read to a specific char ',' which each day is seperated by*/
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID); // find student by ID and remove


	void printAll();//prints list of all student data from the table by calling the print() method in student.h
	void printAverageDaysInCourse(string studentID);//prints average number days in the course
	void printInvalidEmails();//prints emails that don't have '@' or '.' or prints if emal has a ' '
	void printByDegreeProgram(DegreeProgram degreeProgram); // prints student info by enumeration type

	//Deconstructor - good practice
	~Roster();

};


