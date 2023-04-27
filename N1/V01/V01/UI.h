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
void changePassword(Account& main);
void staffMenu(University& uni, LinkedList<SchoolYear*>& years);
void studentMenu(Account& main);
void profile(Account& acc, Student*& s);
void studentScoreboard(Student* s);
void menuNewSemesterInStaff(University& uni, Semester*& cursem);
void loading(University& u, LinkedList<SchoolYear*>& y);
void saving(University& u, LinkedList<SchoolYear*>& y);
Semester* createNewSemester(LinkedList<SchoolYear*> years, SchoolYear*& curyear);
void printStudentsInClass(University& uni);
void printStudentsInCourse(Semester* semester);
void viewScoreboardOfClass(University& uni);
void updateStudentResult(Course* course, string courseID);
