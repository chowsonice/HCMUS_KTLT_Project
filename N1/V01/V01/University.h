#pragma once
#include <list>
#include "Class.h"
using namespace std;

struct University {
	list<Class*> listOfClasses;
public:
	Student* findStudent(string id);
	void addClass();
	void printListOfClasses();
};



