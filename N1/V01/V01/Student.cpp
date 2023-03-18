#include "Student.h"

Student::Student(int no, const char* id, const char* firstName, const char* lastName, char gender, const char* dateOfBirth, const char* socialID){
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

//const Scoreboard& Student::getScoreboard() const {
//    return scoreboard;
//}