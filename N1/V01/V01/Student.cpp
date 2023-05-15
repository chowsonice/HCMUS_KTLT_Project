#pragma once
#include "Student.h"

Student::~Student() {}

int Student::getNo() const {
    return no;
}
const string Student::getId() const {
    return studentID;
}
const string Student::getFirstName() const {
    return firstName;
}
const string Student::getLastName() const {
    return lastName;
}
char Student::getGender() const {
    return gender;
}
const string Student::getDateOfBirth() const {
    return dateOfBirth;
}
const string Student::getSocialID() const {
    return socialID;
}
void Student::addScoreboard(string courseInfo, string courseName, string courseTime) {
    Scoreboard* s = new Scoreboard(courseInfo, courseName, courseTime);
    list.push_back(s);
}
void Student::addScoreboard(Scoreboard* s) {
    list.push_back(s);
    updateFileData();
}
//const Scoreboard* Student::getScoreboard() const {
//    return scoreboard;
//}

void Student::setNo(int no)
{
    this->no = no;
}

void Student::setId(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setGender(char gender)
{
    this->gender = gender;
}

void Student::setDateOfBirth(string dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Student::setSocialID(string socialID)
{
    this->socialID = socialID;
}

void Student::removeScoreboard(string id) {
    for (Node<Scoreboard*> s : list) {
        if (s.data->getCourseId() == id) list.remove(s.data);
    }
}

Scoreboard* Student::findScoreboard(string courseId) {
    for (Node<Scoreboard*> c : list) {
        if (c.data->getCourseId() == courseId) {
            return c.data;
        }
    }
    return nullptr;
}

void Student::printCourseThisSem() {
    int cursem = 0, curyear = 0;
    for (auto sb : list) {
        if (sb->getSemester() > cursem && sb->getSchoolYear() > curyear) {
            cursem = sb->getSemester();
            curyear = sb->getSchoolYear();
        }
    }
    for (auto sb : list) {
        if (sb->getSemester() == cursem && sb->getSchoolYear() == curyear) {
            sb->printInfo();
        }
    }
    cout << "=============================\n";
    cout << "Press anything to return to menu\n";

}

void Student::printAllScoreboard() {
    for (auto sb : list) {
        cout << setw(10) << sb->getCourseID();
        sb->print();
    }
}

ostream& operator<<(ostream& os, const Student& s) {
    if (s.no == 0 || &s == nullptr) {
        throw "Class has no students.\n";
        os << "";
        return os;
    }
    os << to_string(s.no) << " " << s.studentID << " " << s.firstName << " " << s.lastName << " " << s.gender << " ";
    os << s.dateOfBirth << " " << s.socialID;
    return os;
}

void Student::readStudentFromCSVLine(string linetemp) {
    string line = linetemp;
    if (this == nullptr) return;
    const string delim = ",";
    for (int i = 0; i < 7; i++) {
        string token = line.substr(0, line.find(delim));
        switch (i) {
        case 0:
            no = stoi(token);
            break;
        case 1:
            studentID = token;
            break;
        case 2:
            firstName = token;
            break;
        case 3:
            lastName = token;
            break;
        case 4:
            gender = token[0];
            break;
        case 5:
            dateOfBirth = token;
            break;
        case 6:
            socialID = token;
            break;
        }
        line.erase(0, token.length() + delim.length());
    }
}

void Student::updateScoreboard(string courseId, string line) {
    for (auto i = list.begin(); i != list.end(); ++i) {
        if ((*i)->getCourseId() == courseId) {
            (*i)->updateScoreboard(line);
            break;
        } 
    }
    updateFileData();
}

void Student::printScoreboard(string courseId) {
    for (auto i : list) {
        if (i->getCourseId() == courseId) {
            i->print();
            break;
        }
    }
    cout << endl;
}

void Student::printStudentInfo() {
    cout << "Student ID: " << studentID << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << dateOfBirth << endl;
    cout << "Social ID: " << socialID << endl;
}

// readScoreboard tach ra, chinh va gop lai thanh updateScoreboard nha

Student* readStudentFromFile(string studentID)
{
    string fileName = "student_account/" + studentID + ".txt";
    ifstream file(fileName);

    if (!file) {
        cerr << "Can not open Student data\n";
        return nullptr;
    }
    string line;
    Student* student = new Student();

    file.ignore(1000, '\n');
    getline(file, line);
    student->readStudentFromCSVLine(line);

    string buffer, temp; 
    size_t len = 0; // Change int len to size_t
    int num = 0;

    file >> num;
    file.ignore(1000, '\n');

    for (int i = 0; i < num; i++) {
        getline(file, line);
        len = 0;
        Scoreboard* sb = new Scoreboard();
        stringstream ss(line);

        getline(ss, temp, ',');
        len += temp.length();
        sb->setCourseId(temp);

        getline(ss, temp, ',');
        len += temp.length();
        sb->setCourseName(temp);

        getline(ss, temp, ',');
        len += temp.length();
        sb->setCourseTime(temp);

        line.erase(0, len + 3);
        cout << line << endl;
        sb->updateScoreboard(line);

        student->addScoreboard(sb);
    }

    file.close();
    return student;
}

void Student::updateFileData() {
    string source = "student_account/" + studentID + ".txt";
    
    ifstream fin(source);
    ofstream fout;

    if (!fin.is_open()) {
        cout << "Cannot find files to update to update. Please try again later." << endl;
        return;
    }

    string password;
    getline(fin, password);
    fin.close();

    fout.open(source);
    fout << password << endl;
    fout << no << "," << studentID << "," << firstName << "," << lastName << "," << gender << "," << dateOfBirth << "," << socialID << endl;

    fout << list.size() << endl;
    for (Scoreboard* c : list) {
        fout << *c << endl;
    }
    fout.close();
}