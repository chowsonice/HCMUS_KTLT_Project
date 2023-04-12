#include "University.h"

Student* University::findStudent(string id)
{
	Node<Class*>* node = listOfClasses.head;
	while (node != nullptr)
	{
		Student* s = node->data->findStudent(id);
		if (s != nullptr) return s;
		node = node->next;
	}
	return nullptr;
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

ostream& operator<<(ostream& os, const University& u) 
{
	Node<Class*>* node = u.listOfClasses.head;
	while (node != nullptr)
	{
		os << node << endl;
		node = node->next;
	}
	return os;
}
