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
    facc.open("student_account/StudentAccount.txt", fstream::app);
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
    stringstream ss;
    string filenameInfoStu = "output_file/" + className + "_info.csv";
    ofstream file(filenameInfoStu);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    file << "No,id,firstName,lastName,gender,dob,socialID\n";
    string line;
    for (Node<Student*> s : list) {
        ss << *s.data;
        ss >> line;
        file << line << "\n";
    }
    file.close();
}

void Class::printListOfStudents() {
    for (Node<Student*> s : list) {
        cout << *s.data << "\n";
    }
}

void Class::printScoreboardOfClass(string id)
{
    if (!updated) {
        cout << "No updated scoreboard yet.\n";
        return;
    }
    for (Node<Student*> cur : list) {
        cout << "Student ID: " << cur.data->getId() << endl;
        Scoreboard *s = cur.data->findScoreboard(id);
        if (s == nullptr) cout << "00 00 00 00\n";
        else s->print();
    }
}
