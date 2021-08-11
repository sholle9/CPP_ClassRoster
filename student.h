#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	//The array of days will have to have a set number of entries for the array to be properly accesses each time
	const static int numDaysArraySize = 3;

private:
	//nothing can touch except the object
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[numDaysArraySize];
	DegreeProgram degreeProgram;//the enum type from degree.h

public:

	//Accessors will not change values
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	int* GetNumDays(); //array name and pointer similar. array name is constant so pointer is needed    //Get function of array is not const so no 'const'
	DegreeProgram GetDegreeProgram() const;

	//Mutators will change values
	void SetStudentID(string newID);
	void SetFirstName(string newFirst);
	void SetLastName(string newLast);
	void SetEmailAddress(string newEmail);
	void SetAge(int newAge);
	void SetNumDays(int newDays[]);
	void SetDegreeProgram(DegreeProgram newDegree);
	
	void print();//displays specific student data using 'this'

	//Constructors
	Student();//default constructor

	//overload constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[],
		DegreeProgram degreeProgram);// constructor with info needed

	//Deconstructor
	~Student();

	

};
