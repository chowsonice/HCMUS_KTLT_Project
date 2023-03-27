#include "Scoreboard.h"
Scoreboard::Scoreboard(const char* courseId, const char* studentId, int semester, const char* schoolYear, float totalMark, float finalMark, float midtermMark, float otherMark) {
	this->courseId = new char[strlen(courseId) + 1];
	strcpy_s(this->courseId, strlen(courseId) + 1, courseId);

	this->studentId = new char[strlen(studentId) + 1];
	strcpy_s(this->studentId, strlen(studentId) + 1, studentId);

	this->semester = semester;

	this->schoolYear = new char[strlen(schoolYear) + 1];
	strcpy_s(this->schoolYear, strlen(schoolYear) + 1, schoolYear);
	
	this->totalMark = totalMark;
	this->finalMark = finalMark;
	this->midtermMark = midtermMark;
	this->otherMark = otherMark;
}
Scoreboard::~Scoreboard() {
	delete[] courseId;
	delete[] studentId;
	delete[] schoolYear;
}
const char* Scoreboard::getCourseId() const { 
	return courseId; 
}
const char* Scoreboard::getStudentId() const {
	return studentId; 
}
int Scoreboard::getSemester() const {
	return semester; 
}
const char* Scoreboard::getSchoolYear() const {
	return schoolYear; 
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
void Scoreboard::setCourseId(const char* courseId) {
	if (this->courseId != nullptr)
		delete[] this->courseId;
	this->courseId = new char[strlen(courseId) + 1];
	strcpy_s(this->courseId, strlen(courseId) + 1, courseId);
}
void Scoreboard::setStudentId(const char* studentId) {
	if (this->studentId != nullptr)
		delete[] this->studentId;
	this->studentId = new char[strlen(studentId) + 1];
	strcpy_s(this->studentId, strlen(studentId) + 1, studentId);
}
void Scoreboard::setSemester(int semester) {
	this->semester = semester; 
}
void Scoreboard::setSchoolYear(const char* schoolYear)
{
	if (this->schoolYear != nullptr)
		delete[] this->schoolYear;
	this->schoolYear = new char[strlen(schoolYear) + 1];
	strcpy_s(this->schoolYear, strlen(schoolYear) + 1, schoolYear);
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
	os << "Course ID: " << s.courseId << endl
		<< "Student ID: " << s.studentId << endl
		<< "Semester: " << s.semester << endl
		<< "School Year: " << s.schoolYear << endl
		<< "Total Mark: " << s.totalMark << endl
		<< "Final Mark: " << s.finalMark << endl
		<< "Midterm Mark: " << s.midtermMark << endl
		<< "Other Mark: " << s.otherMark << endl;

	return os;
}