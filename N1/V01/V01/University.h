#pragma once
#include <list>
#include "Class.h"
using namespace std;

struct University {
	list<Class*> listOfClasses;
public:
	Student* findStudent(string id) {
		for (Class *c : listOfClasses) {
			Student *s = c->findStudent(id);
			if (s != nullptr) return s;
		}
	}
	void addClass() {
		string buffer;
		cout << "Enter class name: ";
		cin >> buffer;
		Class* newclass = new Class(buffer);
		cout << "Importing students...\n";
		newclass->importStudentsFromCSV();
		listOfClasses.push_back(newclass);
	}
	void printListOfClasses() {
		for (Class* c : listOfClasses) cout << *c << "\n";
	}
};



