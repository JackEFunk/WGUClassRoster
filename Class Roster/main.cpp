#include "roster.h" 
using namespace std;
#include <iostream>

int main() {
    cout << "Course Title: Scripting and Programming - Applications - C867\n"
        << "Programming Language: C++\n"
        << "Student ID: 010010682\n"
        << "Name: John Funk\n" 
        << endl;

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Funk,jfunk29@wgu.edu,31,15,11,17,SOFTWARE" };

    const int numStudents = 5; 

    Roster classRoster; 

    for (int i = 0; i < numStudents; i++)
        classRoster.parse(studentData[i]); 

    cout << "Print All: " << endl;
    classRoster.printAll();  
    cout << endl;

    cout << "Print Invalid Emails: " << endl;
    classRoster.printInvalidEmails(); 
    cout << endl; 

    cout << "Average days in course:" << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(
            classRoster.classRosterArray[i]->getStudentId());
    }
    cout << endl;

    cout << "Print by Degree Program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Remove student with ID A3" << endl;
    classRoster.remove("A3");
    cout << endl;               

    cout << "Remove Student with ID A3 Again" << endl;
    classRoster.remove("A3");
    cout << endl;

    system("pause");

    return 0;
};
