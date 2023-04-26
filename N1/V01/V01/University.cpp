#include "University.h"

University::~University() {
	listOfClasses.clear();
}

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

Class* University::findClass(string id) {
	for (Node<Class*> c : listOfClasses) {
		if (c.data->getClassName().compare(id) == 0) {
			return c.data;
		}
	}
	return nullptr;
}

void University::printListOfClasses() {
	Node<Class*>* cur = listOfClasses.head;
	while (cur != nullptr) {
		cout << cur->data->getClassName() << endl;
		cur = cur->next;
	}
}

void University::addClass()
{

	string buffer;
	cout << "Enter class name: ";
	getline(cin, buffer);
	Class* newclass = new Class(buffer);
	cout << "Importing students...\n";
	newclass->importStudentsFromCSV();
	listOfClasses.push_back(newclass);
}

void University::exportToFile() {
	ofstream fout("info/University_info.txt");
	fout << listOfClasses.size() << endl;
	for (Class* i : listOfClasses) {
		fout << i->getClassName() << endl;
	}
}

void University::importFromFile() {
	int n;
	ifstream fin("info/University_info.txt");
	if (!fin.is_open()) {
		cout << "Cannot load University's information.\n";
		return;
	}
	if (fin.eof()) {
		throw "Univerity has no information";
		return;
	}
	fin >> n;
	fin.ignore(1000, '\n');
	for (int i = 0; i < n; i++) {
		string cname;
		getline(fin, cname);
		Class* c = new Class(cname);
		c->importStudentsFromCSV();
		//c->printListOfStudents();
		listOfClasses.push_back(c);
	}
	fin.close();
}

ostream& operator<<(ostream& os, const University& u) 
{
	for (Class* c : u.listOfClasses) {
		if (c != nullptr) cout << *c << endl;
	}
	return os;
}
