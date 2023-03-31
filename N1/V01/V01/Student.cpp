#pragma once
#include "Student.h"
#include <cstring>
#include <sstream>
using namespace std;

Student::Student(int no, const char* id, const char* firstName, const char* lastName, char gender, const char* dateOfBirth, const char* socialID, const Scoreboard& scoreboard){
    this->no = no;

    this->studentID = new char[strlen(id) + 1];
    strcpy_s(this->studentID, strlen(id) + 1, id);

    this->firstName = new char[strlen(firstName) + 1];
    strcpy_s(this->firstName, strlen(firstName) + 1, firstName);

    this->lastName = new char[strlen(lastName) + 1];
    strcpy_s(this->lastName, strlen(lastName) + 1, lastName);

    this->gender = gender;

    this->dateOfBirth = new char[strlen(dateOfBirth) + 1];
    strcpy_s(this->dateOfBirth, strlen(dateOfBirth) + 1, dateOfBirth);

    this->socialID = new char[strlen(socialID) + 1];
    strcpy_s(this->socialID, strlen(socialID) + 1, socialID);

    this->scoreboard = scoreboard;
}
Student::~Student() {
    delete[] studentID;
    delete[] firstName;
    delete[] lastName;
    delete[] dateOfBirth;
    delete[] socialID;
}

int Student::getNo() const {
    return no;
}

const char* Student::getId() const {
    return studentID;
}

const char* Student::getFirstName() const {
    return firstName;
}

const char* Student::getLastName() const {
    return lastName;
}

char Student::getGender() const {
    return gender;
}

const char* Student::getDateOfBirth() const {
    return dateOfBirth;
}

const char* Student::getSocialID() const {
    return socialID;
}

const Scoreboard& Student::getScoreboard() const {
    return scoreboard;
}

void Student::setNo(int no)
{
    this->no = no;
}

void Student::setId(const char* studentID)
{
    if (this->studentID != nullptr)
        delete[] this->studentID;
    this->studentID = new char[strlen(studentID) + 1];
    strcpy_s(this->studentID, strlen(studentID) + 1, studentID);
}

void Student::setFirstName(const char* firstName)
{
    if (this->firstName != nullptr)
        delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
}

void Student::setLastName(const char* lastName)
{
    if (this->lastName != nullptr)
        delete[] this->lastName;
    this->lastName = new char[strlen(lastName) + 1];
    strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
}

void Student::setGender(char gender)
{
    this->gender = gender;
}

void Student::setDateOfBirth(const char* dateOfBirth)
{
    if (this->dateOfBirth != nullptr)
        delete[] this->dateOfBirth;
    this->dateOfBirth = new char[strlen(dateOfBirth) + 1];
    strcpy_s(this->dateOfBirth, strlen(dateOfBirth) + 1, dateOfBirth);
}

void Student::setSocialID(const char* socialID)
{
    if (this->socialID != nullptr)
        delete[] this->socialID;
    this->socialID = new char[strlen(socialID) + 1];
    strcpy_s(this->socialID, strlen(socialID) + 1, socialID);
}
void Student::setScoreboard(const Scoreboard& scoreboard) {
    this->scoreboard = scoreboard;
}

ostream& operator<<(ostream& os, const Student& s) {
    if (s.no == 0) return os;
    os << to_string(s.no) << " ";
    for (int i = 0; i < strlen(s.studentID); i++) os << s.studentID[i];
    os << " ";
    for (int i = 0; i < strlen(s.firstName); i++) os << s.firstName[i];
    os << " ";
    for (int i = 0; i < strlen(s.lastName); i++) os << s.lastName[i];
    os << " ";
    os << s.gender << " ";
    for (int i = 0; i < strlen(s.dateOfBirth); i++) os << s.dateOfBirth[i];
    os << " ";
    for (int i = 0; i < strlen(s.socialID); i++) os << s.socialID[i];
    return os;
}
void Student::readStudentFromCSVLine(char* line) {
    char* buffer = nullptr, *next_token = nullptr;
    const char* delim = ",";
    int n;
    buffer = strtok_s(line, delim, &next_token);
    for (int i = 0; i < 7; i++) {
        n = strlen(buffer);
        switch (i) {
        case 0:
            no = stoi(buffer);
            break;
        case 1:
            studentID = new char[n + 1];
            strcpy_s(studentID, n + 1, buffer);
            break;
        case 2:
            firstName = new char[n + 1];
            strcpy_s(firstName, n + 1, buffer);
            break;
        case 3:
            lastName = new char[n + 1];
            strcpy_s(lastName, n + 1, buffer);
            break;
        case 4:
            gender = buffer[0];
            break;
        case 5:
            dateOfBirth = new char[n + 1];
            strcpy_s(dateOfBirth, n + 1, buffer);
            break;
        case 6:
            socialID = new char[n + 1];
            strcpy_s(socialID, n + 1, buffer);
            break;
        }
        if (i < 6) buffer = strtok_s(nullptr, delim, &next_token);
    }
}


//In process
void Student::UpdateScoreboard(Scoreboard& scoreboard) {
    char temp1[20], temp2[20], temp3[20];
    int semester;
    float totalMark, finalMark, midtermMark, otherMark;

    cout << "input new CourseID: ";
    cin >> temp1;
    scoreboard.setCourseId(temp1);

    cout << "input new StudentID: ";
    cin >> temp2;
    scoreboard.setStudentId(temp2);

    cout << "input new Semester: ";
    cin >> semester;
    scoreboard.setSemester(semester);

    cout << "input new SchoolYear: ";
    cin >> temp3;
    scoreboard.setSchoolYear(temp3);

    cout << "input new TotalMark: ";
    cin >> totalMark;
    scoreboard.setTotalMark(totalMark);

    cout << "input new FinalMark: ";
    cin >> finalMark;
    scoreboard.setFinalMark(finalMark);

    cout << "input new MidtermMark: ";
    cin >> midtermMark;
    scoreboard.setMidtermMark(midtermMark);

    cout << "input new OtherMark: ";
    cin >> otherMark;
    scoreboard.setOtherMark(otherMark);
}

void Student::PrintScoreboard() {
    cout << "Course ID: " << scoreboard.getCourseId() << endl;
    cout << "Student ID: " << scoreboard.getStudentId() << endl;
    cout << "Semester: " << scoreboard.getSemester() << endl;
    cout << "School Year: " << scoreboard.getSchoolYear() << endl;
    cout << "Mid-term: " << scoreboard.getMidtermMark() << endl;
    cout << "Final Mark: " << scoreboard.getFinalMark() << endl;
    cout << "Other Mark: " << scoreboard.getOtherMark() << endl;
    cout << "Total Mark: " << scoreboard.getTotalMark() << endl;
}

void Student::printStudentInfo() {
    ///Can thiet in student no khum?
    //cout << "Number of student: " << no << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthday: " << dateOfBirth << endl;
    cout << "Social ID: " << socialID << endl;
}