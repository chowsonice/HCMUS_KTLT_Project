#include "Class.h"
#include <cstring>

//Class::Class(char* nameOfClass, LinkedList<Student> listData, int numOfStudents) {
//    className = new char[strlen(nameOfClass) + 1];
//    strcpy_s(className, strlen(nameOfClass) + 1, nameOfClass);
//    list = LinkedList<Student>(listData);
//    numberOfStudents = numOfStudents;
//}

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
//void Class::printScoreboardOfClasses() {
//    cout << "Class Name: " << className << endl;
//    if (list.head == nullptr) {
//        cout << "None" << endl;
//    }
//    else {
//        for (int i = 0; i < list.size(); i++) {
//            Student::PrintScoreboard(list)
//        }
//    }
//}

//void Class::printScoreboardOfClasses()
//{
//    Node<Student>* curr = list.head;
//    while (curr != nullptr) {
//        cout << "Student ID: " << curr->data.getId() << endl;
//        curr->data.PrintScoreboard();
//        curr = curr->next;
//    }
//}
