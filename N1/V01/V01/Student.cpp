#pragma once
#include "Student.h"
#include <cstring>
#include <sstream>
using namespace std;

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

//void Student::setNo(int no)
//{
//    this->no = no;
//}
//
//void Student::setId(const string studentID)
//{
//    if (this->studentID != nullptr)
//        delete[] this->studentID;
//    this->studentID = new char[strlen(studentID) + 1];
//    strcpy_s(this->studentID, strlen(studentID) + 1, studentID);
//}
//
//void Student::setFirstName(const string firstName)
//{
//    if (this->firstName != nullptr)
//        delete[] this->firstName;
//    this->firstName = new char[strlen(firstName) + 1];
//    strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
//}
//
//void Student::setLastName(const string lastName)
//{
//    if (this->lastName != nullptr)
//        delete[] this->lastName;
//    this->lastName = new char[strlen(lastName) + 1];
//    strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
//}
//
//void Student::setGender(char gender)
//{
//    this->gender = gender;
//}
//
//void Student::setDateOfBirth(const string dateOfBirth)
//{
//    if (this->dateOfBirth != nullptr)
//        delete[] this->dateOfBirth;
//    this->dateOfBirth = new char[strlen(dateOfBirth) + 1];
//    strcpy_s(this->dateOfBirth, strlen(dateOfBirth) + 1, dateOfBirth);
//}
//
//void Student::setSocialID(const string socialID)
//{
//    if (this->socialID != nullptr)
//        delete[] this->socialID;
//    this->socialID = new char[strlen(socialID) + 1];
//    strcpy_s(this->socialID, strlen(socialID) + 1, socialID);
//}
//void Student::setScoreboard(const Scoreboard& scoreboard) {
//    this->scoreboard = new Scoreboard(scoreboard);
//}

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
// Nay de doc CSV mot dong, giong cai readCSVline cua Student
//void Student::updateScoreboard(Scoreboard& scoreboard) {
//    char temp1[20], temp2[20], temp3[20];
//    int semester;
//    float totalMark, finalMark, midtermMark, otherMark;
//
//    cout << "input new CourseID: ";
//    cin >> temp1;
//    scoreboard.setCourseId(temp1);
//
//    cout << "input new TotalMark: ";
//    cin >> totalMark;
//    scoreboard.setTotalMark(totalMark);
//
//    cout << "input new FinalMark: ";
//    cin >> finalMark;
//    scoreboard.setFinalMark(finalMark);
//
//    cout << "input new MidtermMark: ";
//    cin >> midtermMark;
//    scoreboard.setMidtermMark(midtermMark);
//
//    cout << "input new OtherMark: ";
//    cin >> otherMark;
//    scoreboard.setOtherMark(otherMark);
//}

void Student::printScoreboard() {
    for (Scoreboard* s : list) cout << *s;
}
void Student::printStudentInfo() {
    ///Can thiet in student no khum? -> Khong !!!

    cout << "Student ID: " << studentID << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << dateOfBirth << endl;
    cout << "Social ID: " << socialID << endl;
}