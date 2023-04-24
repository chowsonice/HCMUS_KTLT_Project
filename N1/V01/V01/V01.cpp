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

    LinkedList<SchoolYear*> years;
    University uni;

    loading(uni, years);

    Account main;
    try {
        loginScreen(main);
        //change_passwordScreen(main);
    }
    catch (const char* error) {
        cout << "ERROR: " << error << endl;
        return -1;
    }
    if (main.getType() == 1) {
        staffMenu(uni, years);
    }
    else if (main.getType() == 2) {
        studentMenu(main);
    }
    return 0;
}
