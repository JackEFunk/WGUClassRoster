#define student_h
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	~Student();

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	void setStudentId(string newID);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmailAddress(string newEmail);
	void setAge(int newAge);
	void setDays(int days[]);
	void setDegreeTypes(DegreeProgram dp);

	void printData();
};