#include "Classes.h"

//Classes::Classes() {
//    listOfStudents = nullptr;
//    numberOfStudents = 0;
//    strcpy_s(className, 50, "none");
//}

void Classes::setClassName(const char* name) {
    strcpy_s(className, 50, name);
}

char* Classes::getClassName() {
    return className;
}

//void Classes::addStudent(char* name) {
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
//
//int Classes::getNumberOfStudents() {
//    return numberOfStudents;
//}
//
//void Classes::printClassInfo() {
//    cout << "Class Name: " << className << endl;
//    cout << "Number of Students: " << numberOfStudents << endl;
//    cout << "List of Students: ";
//
//    if (listOfStudents == nullptr) {
//        cout << "None" << endl;
//    }
//    else {
//        StudentNode* currNode = listOfStudents;
//        while (currNode != nullptr) {
//            cout << currNode->name << " ";
//            currNode = currNode->next;
//        }
//        cout << endl;
//    }
//}
