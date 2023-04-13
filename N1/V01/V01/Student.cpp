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
void Student::addScoreboard(string courseInfo) {
    Scoreboard* s = new Scoreboard(courseInfo);
    list.push_back(s);
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
ostream& operator<<(ostream& os, const Student& s) {
    if (s.no == 0) return os;
    os << to_string(s.no) << " " << s.studentID << " " << s.firstName << " " << s.lastName << " " << s.gender << " ";
    os << s.dateOfBirth << " " << s.socialID;
    return os;
}
void Student::readStudentFromCSVLine(string line) {
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
// Nay de doc CSV mot dong, giong cai readCSVline cua Student o phia tren
void Student::updateScoreboard(string courseId, string line) {
    for (auto i = list.begin(); i != list.end(); ++i) {
        if ((*i)->getCourseId().compare(courseId) == 0) {
            (*i)->updateScoreboard(line);
            return;
        } 
    }
}

void Student::printOneScoreboard(string courseId) {
    for (auto i = list.begin(); i != list.end(); ++i) {
        if ((*i)->getCourseId().compare(courseId) == 0) {
            cout << *(*i);
            return;
        }
    }
}
void Student::printStudentInfo() {
    cout << "Student ID: " << studentID << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << dateOfBirth << endl;
    cout << "Social ID: " << socialID << endl;
}


void Student::readScoreboard(string filename)
{
    string no;
    string gender;
    string noCredits;

    ifstream scorefile;
    scorefile.open(filename);
    //No, id, firstName, lastName, gender, dob, noCredits, courseID, midTerm, lab, endTerm, final
    if (scorefile.is_open())
    {
        while (scorefile)
        {
            getline(scorefile, no, ',');
            this->no = stoi(no);
            getline(scorefile, studentID, ',');
            getline(scorefile, firstName, ',');
            getline(scorefile, lastName, ',');
            getline(scorefile, gender, ',');
            this->gender = (char)gender.c_str();
            getline(scorefile, dateOfBirth, ',');
            getline(scorefile, noCredits, ',');

            Scoreboard* data = new Scoreboard();

            string courseId;
            getline(scorefile, courseId, ',');
            data->setCourseId(courseId);

            string midtermMark;
            getline(scorefile, midtermMark, ',');  
            data->setMidtermMark(stof(midtermMark));

            string otherMark;
            getline(scorefile, otherMark, ',');
            data->setOtherMark(stof(otherMark));

            string finalMark;
            getline(scorefile, finalMark, ',');
            data->setFinalMark(stof(finalMark));

            string totalMark;
            getline(scorefile, totalMark, ',');
            data->setTotalMark(stof(totalMark));

            list.push_back(data);
        }
    }
    scorefile.close();
}

Student* Student::readStudentFromFile(string studentID)
{
    string fileName = "student_data/" + studentID + ".txt";
    ifstream file(fileName);

    if (!file) {
        cerr << "Can not opent Student data\n";
        return nullptr;
    }
    string line, value;
    Student* student = new Student(studentID, "", "", ' ', "", "");
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> value;
        if (value == "Student ID") {
            iss >> value;
            student->studentID = value;
        }
        else if (value == "First name") {
            iss >> value;
            student->firstName = value;
        }
        else if (value == "Last name") {
            iss >> value;
            student->lastName = value;
        }
        else if (value == "Gender:") {
            iss >> value;
            student->gender = value[0];
        }
        else if (value == "Date of birth") {
            iss >> value;
            iss >> value;
            student->dateOfBirth = value;
        }
        else if (value == "Social ID") {
            iss >> value;
            student->socialID = value;
        }
    }
    file.close();
    return student;
}
