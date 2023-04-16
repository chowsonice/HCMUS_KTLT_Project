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
void Scoreboard::setCourseId(string courseId) {
	this->courseId = courseId;
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

ostream& operator<<(ostream& os, const Scoreboard& s){
	os << s.courseId << "," << s.courseName << "," << s.time << "," << s.midtermMark << "," << s.otherMark << "," << s.finalMark << "," << s.totalMark << endl;
	return os;
}

void Scoreboard::print() {
	cout << setw(10) << max(midtermMark, float(0)) << "| ";
	cout << setw(10) << max(otherMark,float(0)) << "| ";
	cout << setw(10) << max(finalMark, float(0)) << "| ";
	cout << setw(10) << max(totalMark, float(0)) << "| ";
	cout << endl;
}