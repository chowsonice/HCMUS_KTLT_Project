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
    ifstream fileacc;
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

        //check if account exists
        fileacc.open("student_account/" + newStudent->getId() + ".txt");
        if (fileacc.is_open()) {
            fileacc.close();
            continue;
        }
        fileacc.close();
        
        //creating account
        string username, password, token;
        username = newStudent->getId();
        token = newStudent->getDateOfBirth();
        for (int i = 0; i < 3; i++) {
            string token2 = token.substr(0, token.find("/"));
            password += token2;
            token.erase(0, token2.length() + 1);
        }
        
        outfile = "student_account/" + username + ".txt";

        fout.open(outfile);
        if (!fout.is_open()) {
            throw "Cannot open files to store informations. Please try again later.";
            return;
        }
        fout << password << endl;
        fout << line << endl;
        
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
    //if (!updated) {
    //    cout << "No updated scoreboard yet.\n";
    //    return;
    //}
    cout << "|" << setw(10) << "  ID  " << "|" << setw(15) << "  First name  " << "|" << setw(15) << "  Last name  " << "|" << setw(10) << " Midterm "
        << "|" << setw(10) << " Other " << "|" << setw(10) << " Final " << "|" << setw(10) << " Total " << "|" << endl;
    for (Student* s : list) {
        cout << "|" << setw(10) << s->getId() << "|" << setw(15) << s->getFirstName() << "|" << setw(15) << s->getLastName() << "|";
        s->printScoreboard(id);
    }
}

ostream& operator<<(ostream& os, Class c) {
    os << "Class " << c.className << "\n" << "Number of students: " << c.numberOfStudents << "\n";
    return os;
}
