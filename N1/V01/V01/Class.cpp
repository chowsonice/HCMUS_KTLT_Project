#include "Class.h"
#include <cstring>

Class::Class() {
    numberOfStudents = 0;
    className = nullptr;
}

void Class::setClassName(const char* name) {
    strcpy_s(className, 50, name);
}

char* Class::getClassName() const {
    return className;
}

int Class::getNumberOfStudents() {
    return numberOfStudents;
}

void Class::importStudentsFromCSV(const char* filenameInfoStu) {
    ifstream file(filenameInfoStu);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }

    string line;
    getline(file, line, '\n');

    numberOfStudents = 0;

    while (getline(file, line)) {
        numberOfStudents++;
        char* buffer = new char[line.length() + 1];
        strcpy_s(buffer, line.length() + 1, line.c_str());
        Student *newStudent = new Student;
        newStudent->readStudentFromCSVLine(buffer);
        list.push_back(newStudent);

        delete[] buffer;
    }
    file.close();
}

//void Class::addStudent(char* name) {
//    StudentNode* newNode = new StudentNode;
//    strcpy_s(newNode->name, 50, name);
//    newNode->next = nullptr;
//
//    if (listOfStudents == nullptr) {
//        listOfStudents = newNode;
//    }
//    else {
//        StudentNode* currNode = listOfStudents;
//        while (currNode->next != nullptr) {
//            currNode = currNode->next;
//        }
//        currNode->next = newNode;
//    }
//
//    numberOfStudents++;
//}

//void Class::printListOfClasses() {
//    cout << "Class Name: " << className << endl;
//    cout << "Number of Students: " << numberOfStudents << endl;
//    cout << "List of Students: ";
//    if (list.head == nullptr) {
//        cout << "None" << endl;
//    }
//    else {
//        printListOfStudents();
//    }
//}

void Class::printListOfStudents() 
{
    for (Student* s : list) {
        cout << *s << "\n";
    }
}
