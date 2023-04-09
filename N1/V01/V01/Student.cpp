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


