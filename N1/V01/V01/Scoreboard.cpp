#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    int No;
    string id;
    string firstName;
    string lastName;
    char gender;
    string dob;
    string courseID;
    int midTerm;
    int lab;
    int endTerm;
    double final;
};

int main() {
    ifstream file("scoreboard.csv");
    vector<Student> students;
    string line;

    getline(file, line);

    while (getline(file, line)) {
        Student student;
        stringstream ss(line);
        string item;

        getline(ss, item, ',');
        cout << "No: " << item << endl;
        student.No = stoi(item);

        getline(ss, item, ',');
        cout << "ID: " << item << endl;
        student.id = item;

        getline(ss, item, ',');
        cout << "First Name: " << item << endl;
        student.firstName = item;

        getline(ss, item, ',');
        cout << "Last Name: " << item << endl;
        student.lastName = item;

        getline(ss, item, ',');
        cout << "Gender: " << item << endl;
        student.gender = item[0];

        getline(ss, item, ',');
        cout << "DOB: " << item << endl;
        student.dob = item;

        getline(ss, item, ',');
        cout << "Course ID: " << item << endl;
        student.courseID = item;

        getline(ss, item, ',');
        cout << "Midterm: " << item << endl;
        student.midTerm = stoi(item);

        getline(ss, item, ',');
        cout << "Lab: " << item << endl;
        student.lab = stoi(item);

        getline(ss, item, ',');
        cout << "Endterm: " << item << endl;
        student.endTerm = stoi(item);

        getline(ss, item, ',');
        cout << "Final: " << item << endl;
        student.final = stod(item);

        students.push_back(student);
    }

    for (const auto& student : students) {
        cout << "No: " << student.No << endl;
        cout << "ID: " << student.id << endl;
        cout << "First Name: " << student.firstName << endl;
        cout << "Last Name: " << student.lastName << endl;
        cout << "Gender: " << student.gender << endl;
        cout << "DOB: " << student.dob << endl;
        cout << "Course ID: " << student.courseID << endl;
        cout << "Midterm: " << student.midTerm << endl;
        cout << "Lab: " << student.lab << endl;
        cout << "Endterm: " << student.endTerm << endl;
        cout << "Final: " << student.final << endl;
        cout << endl;
    }

    file.close();
    return 0;
}