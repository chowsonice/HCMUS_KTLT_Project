#pragma once
#include "Class.h"
#include "SchoolYear.h"
using namespace std;

struct University {
	LinkedList<Class*> listOfClasses;
	LinkedList<SchoolYear*> years;
public:
	Student* findStudent(string id);
	Class* findClass(string id) {
		for (Node<Class*> c : listOfClasses) {
			if (c.data->getClassName().compare(id) == 0) {
				return c.data;
			}
		}
	}
	void addClass();
	friend ostream& operator<<(ostream& os, const University& s);
};



