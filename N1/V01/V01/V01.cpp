// V01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "SchoolYear.h"
#include "Semester.h"
#include "Course.h"
#include "Class.h"
#include "Student.h"
#include "University.h"


int main()
{
    SchoolYear* year = new SchoolYear;
    University uni;

    //uni.addClass();
    //uni.addClass();
    //year->createNewSemester();

    //Semester* s = year->getCurrentSemester();
    //s->addCourse();
    //s->addCourse();

    //saving(uni, year);

    loading(uni, year);

    cout << uni;
    cout << *year;

    Semester* sem = year->getCurrentSemester();
    cout << *sem;
    //sem->printListOfCourses();

    //Account main;
    //Semester* cursem = new Semester();
    //try {
    //    loginScreen(main);
    //    //change_passwordScreen(main);
    //}
    //catch (const char* error) {
    //    cout << "ERROR: " << error << endl;
    //    return -1;
    //}
    //if (main.getType() == 1) {
    //    staffMenu();
    //}
    //else if (main.getType() == 2) {
    //    studentMenu(main);
    //}
    return 0;
}
