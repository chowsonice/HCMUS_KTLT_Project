// V01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SchoolYear.h"
//#include "Semester.h"
#include "Course.h"
#include "Class.h"
#include "Student.h"
int main()
{
    SchoolYear curSchoolYear;
    cout << curSchoolYear << endl;
    curSchoolYear.createNewSemester();
    Semester *curSem = curSchoolYear.getCurrentSemester();
    Class class21CLC01;
    class21CLC01.importStudentsFromCSV("csv_file/21CLC01_info.csv");
    class21CLC01.printListOfStudents();
    curSem->addCourse();
    cout << *curSem << endl;

    return 0;
}
