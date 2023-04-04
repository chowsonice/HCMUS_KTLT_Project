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

void Student::importStudentListFromCSV(const string& csvFileName, const string& accountFileName) {
    ifstream csvFile(csvFileName);
    if (!csvFile.is_open()) {
        cerr << "Error: Could not open " << csvFileName << endl;
        return;
    }
    ofstream accountFile(accountFileName);
    if (!accountFile.is_open()) {
        cerr << "Error: Could not create " << accountFileName << endl;
        return;
    }
    string line;
    getline(csvFile, line);
    int count = 0;
    while (getline(csvFile, line)) {
        istringstream iss(line);
        string no, studentID, firstName, lastName, gender, dob, socialID;
        getline(iss, no, ',');
        getline(iss, studentID, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        getline(iss, gender, ',');
        getline(iss, dob, ',');
        getline(iss, socialID, ',');
        Student* student = new Student;
        student->studentID = studentID;
        student->dateOfBirth = dob;

        string username = studentID;
        string password = dob;
        password.erase(remove(password.begin(), password.end(), '/'), password.end());
        accountFile << username << " " << password << endl;
        count++;
    }
    csvFile.close();
    accountFile.close();
    cout << "Imported " << count << " students from " << csvFileName << " to " << accountFileName << endl;
}
