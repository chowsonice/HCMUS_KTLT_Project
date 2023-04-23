#pragma once
#include <iostream>
#include <conio.h>
#include "Account.h"
#include "Student.h"
#include "University.h"
#include "Semester.h"
#include "SchoolYear.h"
using namespace std;

void loginScreen(Account& main);
void change_passwordScreen(Account& main);
void staffMenu();
void studentMenu(Account& main);
void profile(Student*& s);
void studentScoreboard(Student* s);
void menuNewSemesterInStaff(Semester* semNew);
void loading(University& u, SchoolYear*& y);
void saving(University& u, SchoolYear*& y);