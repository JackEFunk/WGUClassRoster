#include "roster.h"

void Roster::parse(
    string studentData) { 
    size_t rhs = studentData.find(",");
    
    string sID = studentData.substr(0, rhs); 
    
    size_t lhs = rhs + 1;

    rhs = studentData.find(",", lhs);
  
    string sFirstName = studentData.substr(lhs, rhs - lhs);
   
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sLastName = studentData.substr(lhs, rhs - lhs); 
    lhs = rhs + 1; 
    rhs = studentData.find(",", lhs);
    string sEmail = studentData.substr(lhs, rhs - lhs); 
    lhs = rhs + 1;                                     
    rhs = studentData.find(",", lhs);
    int sAge = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs)); 
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs)); 
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);

    DegreeProgram dp = SECURITY;

    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E')
        dp = SECURITY;
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O')
        dp = SOFTWARE;
    else if (studentData.at(lhs) == 'N')
        dp = NETWORK; 

    add(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse1, daysInCourse2, daysInCourse3, dp);
};

void Roster::add(
    string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
       
    classRosterArray[++endIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
};

void Roster::remove(
    string studentID) { 
    bool done = false;    
    for (int i = 0; i <= Roster::endIndex; i++) {
        if (classRosterArray[i]->getStudentId() == studentID) {
            
            done = true;               
            if (i < numStudents - 1) { 
                Student* tempStudent = classRosterArray[i]; 
                classRosterArray[i] = classRosterArray[numStudents - 1]; 
                classRosterArray[numStudents - 1] = tempStudent;
            }
            Roster::endIndex--;
        }
    }
    if (done) {
        cout << "student " << studentID << " removed." << endl << endl;
        this->printAll(); 
    }
    else {
        cout << "Error: Student " << studentID << " not found." << endl << endl; 
    }
};

void Roster::printAll() {
    for (int i = 0; i <= Roster::endIndex; i++) {
        Roster::classRosterArray[i]->printData();
    }
}

void Roster::printAverageDaysInCourse(
    string studentID) { 
    for (int i = 0; i <= Roster::endIndex; i++) {
        if (classRosterArray[i]->getStudentId() == studentID) {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3 << endl; 
        }
    }
};

void Roster::printInvalidEmails() { 
    bool invalidEmail = false;        
    for (int i = 0; i < Roster::endIndex; i++) {
        string emailAddress = (classRosterArray[i]->getEmailAddress()); 
        if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos) {
            invalidEmail = true;
            cout << classRosterArray[i]->getEmailAddress() << endl; 
        }
    }
    if (!invalidEmail)
        cout << "NONE" << endl; 
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) { 
    for (int i = 0; i <= Roster::endIndex; i++) { 
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
            classRosterArray[i]->printData(); 
    } 
};

Roster::~Roster() {};
