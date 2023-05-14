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
    bool exitProgram = false;
    while (!exitProgram) {
        try {
            loginScreen(main);
        }
        catch (const char* error) {
            cout << "ERROR: " << error << endl;
            continue;
        }

        if (main.getType() == 1) {
            staffMenu(uni, years);
        }
        else if (main.getType() == 2) {
            studentMenu(main);
        }
        saving(uni, years);
        int choice;
        cout << "Do you want to login again?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cin >> choice;
        system("cls");

        if (choice == 2) {
            exitProgram = true;
        }
    }

    return 0;
}

