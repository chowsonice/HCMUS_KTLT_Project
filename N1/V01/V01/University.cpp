#include "University.h"

Student* University::findStudent(string id)
{
	for (Class* c : listOfClasses) {
		Student* s = c->findStudent(id);
		if (s != nullptr) return s;
	}
}

void University::addClass()
{

	string buffer;
	cout << "Enter class name: ";
	cin >> buffer;
	Class* newclass = new Class(buffer);
	cout << "Importing students...\n";
	newclass->importStudentsFromCSV();
	listOfClasses.push_back(newclass);
}

void University::printListOfClasses()
{

	for (Node<Class*> c : listOfClasses) cout << *c.data << "\n";

}
