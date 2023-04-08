#include "Class.h"
#include <cstring>

Class::Class(string nameOfClass, LinkedList<Student*> listData(), int numOfStudents) {
    className = nameOfClass;
    list = listData();
    numberOfStudents = numOfStudents;
}

void Class::setClassName(const string name) {
    className = name;
}

string Class::getClassName() const {
    return className;
}

int Class::getNumberOfStudents() {
    return numberOfStudents;
}

void Class::importStudentsFromCSV() {
    string filenameInfoStu = "csv_file/" + className + "_info.csv";
    ifstream file(filenameInfoStu);
    ofstream facc;
    facc.open("Account.txt", fstream::app);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    string line;
    getline(file, line, '\n');
    numberOfStudents = 0;
    while (getline(file, line)) {
        numberOfStudents++;

        //adding students
        Student *newStudent = new Student;
        newStudent->readStudentFromCSVLine(line);
        list.push_back(newStudent);

        //creating account
        string username, password;
        for (int i = 0; i < 6; i++) {
            string token = line.substr(0, line.find(","));
            switch (i) {
            case 1:
                username = token;
                break;
            case 5:
                for (int i = 0; i < 3; i++) {
                    string token2 = token.substr(0, token.find("/"));
                    password += token2;
                    token.erase(0, token2.length() + 1);
                }
                break;
            }
            line.erase(0, token.length() + 1);
        }
        facc << username << " " << password << endl;
    }
    file.close();
    facc.close();
}


void Class::exportStudentsToCSV() {
    string filenameInfoStu = "csv_file/" + className + "_info.csv";
    ofstream file(filenameInfoStu);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    string line, buffer;
    
}


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

//void Class::printListOfStudents() 
//{
//    for (Student* s : list) {
//        cout << *s << "\n";
//    }
//}

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
