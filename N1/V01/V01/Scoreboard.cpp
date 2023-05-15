#include "Scoreboard.h"
#include <iomanip>

//Scoreboard::Scoreboard(string courseId, string courseName, float midtermMark, float otherMark, float finalMark, float totalMark) {
//	this->courseId = courseId;
//	this->courseName = courseName;
//	this->totalMark = totalMark;
//	this->finalMark = finalMark;
//	this->midtermMark = midtermMark;
//	this->otherMark = otherMark;
//}

Scoreboard::~Scoreboard() {}

const string Scoreboard::getCourseId() const { 
	return courseId; 
}

float Scoreboard::getTotalMark() const {
	return totalMark; 
}

float Scoreboard::getFinalMark() const {
	return finalMark; 
}

float Scoreboard::getMidtermMark() const {
	return midtermMark; 
}

float Scoreboard::getOtherMark() const {
	return otherMark; 
}
int Scoreboard::getSemester() const
{
	return semester;
}
int Scoreboard::getSchoolYear() const
{
	return year;
}
void Scoreboard::setCourseId(string courseId) {
	this->courseId = courseId;
}

void Scoreboard::setCourseName(string name) {
	courseName = name;
}

void Scoreboard::setCourseTime(string courseTime) {
	time = courseTime;
}

void Scoreboard::setTotalMark(float totalMark) {
	this->totalMark = totalMark; 
}

void Scoreboard::setFinalMark(float finalMark) {
	this->finalMark = finalMark; 
}

void Scoreboard::setMidtermMark(float midtermMark) {
	this->midtermMark = midtermMark; 
}

void Scoreboard::setOtherMark(float otherMark) {
	this->otherMark = otherMark; 
}

void Scoreboard::setSemester(int s, int y) {
	semester = s;
	year = y;
}

void Scoreboard::printInfo() {
	cout << "---------------------------\n";
	cout << "Name: " << courseName << endl;
	cout << "Course ID: " << courseId << endl;
	cout << "Time: " << time << endl;
}

void Scoreboard::updateScoreboard(string line) {
	stringstream ss(line); char c;
	if (!(ss >> midtermMark) || (midtermMark < -1 || midtermMark > 10)) throw "Invalid grade!";
	ss >> c;
	if (!(ss >> otherMark) || (otherMark < -1 || otherMark > 10)) throw "Invalid grade!";
	ss >> c;
	if (!(ss >> finalMark) || (finalMark < -1 || finalMark > 10)) throw "Invalid grade!";
	ss >> c;
	if (!(ss >> totalMark) || (totalMark < -1 || totalMark > 10)) throw "Invalid grade!";
	//if (midtermMark == -1 || finalMark == -1 || otherMark == -1 || totalMark == -1) return;
	updated = true;
}

void Scoreboard::updateScoreboard() {
	float score = -1;
	cout << "Enter midterm mark, if unchange enter -1: ";
	if (!(cin >> score) || (score < -1 || score > 10)) throw "Invalid grade!";
	else {
		if (score != -1) midtermMark = score;
	}
	cout << "Enter other mark, if unchange enter -1: ";
	if (!(cin >> score) || (score < -1 || score > 10)) throw "Invalid grade!";
	else {
		if (score != -1) otherMark = score;
	}
	cout << "Enter final mark, if unchange enter -1: ";
	if (!(cin >> score) || (score < -1 || score > 10)) throw "Invalid grade!";
	else {
		if (score != -1) finalMark = score;
	}
	cout << "Enter total mark, if unchange enter -1: ";
	if (!(cin >> score) || (score < -1 || score > 10)) throw "Invalid grade!";
	else {
		if (score != -1) totalMark = score;
	}
	updated = true;
}

bool Scoreboard::checkUpdated() {
	return updated;
}

ostream& operator<<(ostream& os, const Scoreboard& s){
	os << s.courseId << "," << s.courseName << "," << s.time << "," << s.midtermMark << "," << s.otherMark << "," << s.finalMark << "," << s.totalMark << endl;
	return os;
}

string Scoreboard::getCourseID() {
	return courseId;
}

void Scoreboard::print() {
	cout << setw(10) << ((midtermMark < 0) ? "" : to_string(midtermMark)) << "|";
	cout << setw(10) << ((otherMark < 0) ? "" : to_string(otherMark)) << "|";
	cout << setw(10) << ((finalMark < 0) ? "" : to_string(finalMark)) << "|";
	cout << setw(10) << ((totalMark < 0) ? "" : to_string(totalMark)) << "|";
}