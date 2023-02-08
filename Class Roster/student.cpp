#include "student.h"			

Student::Student() {			
	this->studentID = "";		
	this->firstName = "";		
	this->lastName = "";		
	this->emailAddress = "";	
	this->age = 0;				
	for (int i = 0; i < daysArraySize; i++)		
		this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;	
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) {
	this->studentID = studentID;  
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() { 

}

string Student::getStudentId() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDays() {
	return this->days;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


void Student::setStudentId(string newID) {
	this->studentID = newID;
}
void Student::setFirstName(string newFirstName) {
	this->firstName = newFirstName;
}
void Student::setLastName(string newLastName) {
	this->lastName = newLastName;
}
void Student::setEmailAddress(string newEmail) {
	this->emailAddress = newEmail;
}
void Student::setAge(int newAge) {
	this->age = newAge;
}
void Student::setDays(int days[]) {
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeTypes(DegreeProgram dp) {
	this->degreeProgram = dp;
}

void Student::printData() {
	cout << this->getStudentId() << "\t";
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getEmailAddress() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getDays()[0] << ", "; 
	cout << this->getDays()[1] << ", ";
	cout << this->getDays()[2] << "\t";
	cout << degreeProgramTypes[this->getDegreeProgram()];
	cout << endl;
}
