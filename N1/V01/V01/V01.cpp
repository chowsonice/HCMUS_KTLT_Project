// V01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SchoolYear.h"
//#include "Semester.h"
#include "Course.h"
#include "Class.h"
#include "Student.h"
#include "Account.h"
#include "University.h"
int main()
{
    cout << "Creating school year...\n";
    SchoolYear curSchoolYear;
    cout << "-----School year-----\n";
    cout << curSchoolYear << endl;
    University uni;
    uni.addClass();
    uni.addClass();
    Class* class21CLC01 = uni.listOfClasses.front();
    cout << "-----List of students in class 21CLC01-----\n";
    class21CLC01->printListOfStudents();
    cout << "\nCreating new semester...\n";
    curSchoolYear.createNewSemester();
    Semester* curSem = curSchoolYear.getCurrentSemester();

    cout << "Adding course 1...\n";
    curSem->addCourse();
    cout << "Adding course 2...\n";
    curSem->addCourse();
    cout << "\n-----This semester-----\n";
    cout << *curSem << endl;

    cout << "\nImporting list of students from file...\n";
    curSem->listOfCourses.front()->importStudentsFromCSV("csv_file/21CLC01_CSC10001.csv", uni);
    
    cout << "\n-----List of students in course CSC001-----\n";
    curSem->listOfCourses.front()->printListOfStudents();

    Student* news = new Student;
    news->readStudentFromCSVLine("1,SV5012,Hung,Truong,M,03/12/2003,214521");
    cout << "\n-----Adding student to the class-----\n";
    curSem->listOfCourses.front()->addStudent(news);
    news->printStudentInfo();

    cout << "\n-----Updated list of students in course CSC001-----\n";
    curSem->listOfCourses.front()->printListOfStudents();
    
    // !!! need to fix remove students, for ease of use arguments should be student id
    curSem->listOfCourses.front()->removeStudent(news);

    cout << "\n-----Updated list of students in course CSC001-----\n";
    curSem->listOfCourses.front()->printListOfStudents();

    string username, password;
    cout << "\n-----STUDENT LOGIN-----\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    Student* s;
    if (checkLogin(username, password)) {
        s = class21CLC01->findStudent(username);
    }
    else return 0;

    cout << "\n-----List of courses-----\n";
    s->printScoreboard();

    cout << "\n-----List of classes-----\n";
    s->printScoreboard();

    return 0;
}
