#include "degree.h"
#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	//this is string arry of student data
	const string studentData[] =

	{ 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Stephanie,Katuzienski,sholle9@wgu.edu,27,40,50,45,SOFTWARE"
	};

	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000658549" << endl;
	cout << "Name: Stephanie Katuzienski" << endl << endl;

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << endl << endl;
	classRoster.printAll();
	cout << endl;
	
	cout << "Displaying invalid emails: " << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	
	
	for (int i = 0; i < numStudents; i++) {
		
		 if (i == 0)
			 classRoster.printAverageDaysInCourse("A1");
		 else if (i == 1)
			 classRoster.printAverageDaysInCourse("A2");
		 else if (i == 2)
			 classRoster.printAverageDaysInCourse("A3");
		 else if (i == 3)
			 classRoster.printAverageDaysInCourse("A4");
		 else
			 classRoster.printAverageDaysInCourse("A5");
		
	}
	cout << endl;
	
	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing A3" << endl << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl;

	cout << "Removing A3 Again" << endl << endl;
	classRoster.remove("A3");

	classRoster.~Roster();
	cout << "--DONE--" << endl;
}