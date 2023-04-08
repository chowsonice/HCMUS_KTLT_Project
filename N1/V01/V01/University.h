#pragma once
#include "Class.h"
#include "Node.h"
using namespace std;

struct University {
	LinkedList<Class*> listOfClasses;
public:
	Student* findStudent(string id);
	void addClass();
	friend ostream& operator<<(ostream& os, const University& s);
};



