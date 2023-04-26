#pragma once
#include "Node.h"
#include "Class.h"
using namespace std;

struct University {
	LinkedList<Class*> listOfClasses;
public:
	~University();
	Student* findStudent(string id);
	Class* findClass(string id);
	void printListOfClasses();
	void addClass();
	void exportToFile();
	void importFromFile();
	friend ostream& operator<<(ostream& os, const University& s);
};



