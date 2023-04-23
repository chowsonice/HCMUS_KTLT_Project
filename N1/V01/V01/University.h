#pragma once
#include "Node.h"
#include "Class.h"
using namespace std;

struct University {
	LinkedList<Class*> listOfClasses;
public:
	~University() {
		listOfClasses.clear();
	}
	Student* findStudent(string id);
	Class* findClass(string id) {
		for (Node<Class*> c : listOfClasses) {
			if (c.data->getClassName().compare(id) == 0) {
				return c.data;
			}
		}
	}
	void printListOfClasses();
	void addClass();
	void exportToFile();
	void importFromFile();
	friend ostream& operator<<(ostream& os, const University& s);
};



