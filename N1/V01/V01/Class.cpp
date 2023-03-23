#include "Class.h"
#include <cstring>

Class::Class() {
    list = nullptr;
    numberOfStudents = 0;
    strcpy_s(className, 50, "none");
}

void Class::setClassName(const char* name) {
    strcpy_s(className, 50, name);
}

char* Class::getClassName() const {
    return className;
}
void Class::importStudentsFromCSV(const char* filenameInfoStu) {
    ifstream file(filenameInfoStu);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }

    string line;

    getline(file, line);
    int numberOfStudents = stoi(line);

    int index = 0;
    while (getline(file, line)) {
        char* buffer = new char[line.length() + 1];
        strcpy_s(buffer, line.length() + 1, line.c_str());
        
        LinkedList<Student> listOfStudents;
        Student newStudent;
        newStudent.readStudentFromCSVLine(buffer);
        listOfStudents.add(newStudent);

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

int Class::getNumberOfStudents() {
    return numberOfStudents;
}

void Class::printClass() {
    cout << "Class Name: " << className << endl;
    cout << "Number of Students: " << numberOfStudents << endl;
    //cout << "List of Students: ";

    //if (list.head == nullptr) {
    //    cout << "None" << endl;
    //}
    //else {
    //    Node<Student>* currNode = list.head;
    //    while (currNode != nullptr) {
    //        cout << currNode->name << " ";
    //        currNode = currNode->next;
    //    }
    //    cout << endl;
    //}
}

void Class::printListOfStudents() 
{
    cout << this->list << endl;
}
