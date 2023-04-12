#pragma once
#include <iostream>
#include <conio.h>
#include "Account.h"
#include "Student.h"
using namespace std;

void loginScreen(Account& main);
void staffMenu();
void studentMenu(Student*& s);
void profile(Student*& s);