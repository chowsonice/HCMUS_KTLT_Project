#include "Scoreboard.h"

Scoreboard::Scoreboard(string courseId, float midtermMark, float otherMark, float finalMark, float totalMark) {
	this->courseId = courseId;
	this->totalMark = totalMark;
	this->finalMark = finalMark;
	this->midtermMark = midtermMark;
	this->otherMark = otherMark;
}

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
	os	<< "Course ID: " << s.courseId << endl;
	if (!s.updated) return os;
	os	<< "Total Mark: " << s.totalMark << endl
		<< "Final Mark: " << s.finalMark << endl
		<< "Midterm Mark: " << s.midtermMark << endl
		<< "Other Mark: " << s.otherMark << endl;
	return os;
}

void Scoreboard::print() {
	cout << (midtermMark / 10 < 1) ? "0" : "" ;
	cout << midtermMark << " ";
	cout << (otherMark / 10 < 1) ? "0" : "";
	cout << otherMark << " ";
	cout << (finalMark / 10 < 1) ? "0" : "";
	cout << finalMark << " ";
	cout << (totalMark / 10 < 1) ? "0" : "";
	cout << totalMark << " ";
	cout << endl;
}