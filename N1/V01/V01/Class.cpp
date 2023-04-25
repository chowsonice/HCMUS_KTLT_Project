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

Student* Class::findStudent(string id) {
    for (Node<Student*> s : list) {
        if (s.data->getId().compare(id) == 0) {
            return s.data;
        }
    }
    return nullptr;
}

void Class::importStudentsFromCSV() {
    string filenameInfoStu = "csv_file/" + className + "_info.csv";
    string outfile;

    ifstream file(filenameInfoStu);
    ofstream fout;

    if (!file.is_open()) {
        cout << "Cannot open file to import student's info." << endl;
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
        string username, password, temp = line;
        for (int i = 0; i < 7; i++) {
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
        outfile = "student_account/" + username + ".txt";

        fout.open(outfile);
        if (!fout.is_open()) {
            throw "Cannot open files to store informations. Please try again later.";
            return;
        }
        fout << password << endl;
        fout << temp << endl;
        
        fout.close();
    }
    file.close();
}

void Class::exportStudentsToCSV() {
    stringstream ss;
    string filenameInfoStu = "output_file/" + className + "_info.csv";
    ofstream file(filenameInfoStu);
    if (!file.is_open()) {
        cout << "Cannot open file to export students' information." << endl;
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

ostream& operator<<(ostream& os, Class c) {
    os << "Class " << c.className << "\n" << "Number of students: " << c.numberOfStudents << "\n";
    return os;
}
