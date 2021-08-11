#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;

//enumeration that gives a # for each degree
enum DegreeProgram
{
	SECURITY, NETWORK, SOFTWARE
};

//Needs to be in the same order as the enum will translate the enumeration into corresponding string
static const std::string degreeProgramString[] = { 
	"SECURITY", "NETWORK", "SOFTWARE" 
};