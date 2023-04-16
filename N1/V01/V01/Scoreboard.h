#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Scoreboard
{
private:
	bool updated = false;
	string courseId;
	string courseName;
	string time;
	float totalMark;
	float finalMark;
	float midtermMark;
	float otherMark;
public:
	Scoreboard() : courseId(""), totalMark(-1), finalMark(-1), midtermMark(-1), otherMark(-1) {}
	Scoreboard(string courseId, string courseName, string courseTime) : courseId(courseId), courseName(courseName), time(courseTime), totalMark(-1), finalMark(-1), midtermMark(-1), otherMark(-1) {}
	//Scoreboard(string courseId, string courseName, float midtermMark, float otherMark, float finalMark, float totalMark);
	//Scoreboard(const Scoreboard& sb) : Scoreboard(sb.courseId, sb.courseName, sb.midtermMark, sb.otherMark, sb.finalMark, sb.totalMark) {}
	~Scoreboard();

	const string getCourseId() const;
	float getTotalMark() const;
	float getFinalMark() const;
	float getMidtermMark() const;
	float getOtherMark() const;

	void setCourseId(const string courseId);
	void setCourseName(string name) {
		courseName = name;
	}
	void setCourseTime(string courseTime) {
		time = courseTime;
	}
	void setTotalMark(float totalMark);
	void setFinalMark(float finalMark);
	void setMidtermMark(float midtermMark);
	void setOtherMark(float otherMark);

	void printInfo() {
		cout << "---------------------------\n";
		cout << "Name: " << courseName << endl;
		cout << "Course ID: " << courseId << endl;
		cout << "Time: " << time << endl;
	}
	void updateScoreboard(string line) {
		stringstream ss(line); char c;
		if (!(ss >> midtermMark) || (midtermMark < -1 || midtermMark > 10)) throw "Invalid grade!";
		ss >> c;
		if (!(ss >> otherMark) || (otherMark < -1 || otherMark > 10)) throw "Invalid grade!";
		ss >> c;
		if (!(ss >> finalMark) || (finalMark < -1 || finalMark > 10)) throw "Invalid grade!";
		ss >> c;
		if (!(ss >> totalMark) || (totalMark < -1 || totalMark > 10)) throw "Invalid grade!";
		if (midtermMark == -1 || finalMark == -1 || otherMark == -1 || totalMark == -1) return;
		updated = true;
	}

	bool checkUpdated() {
		return updated;
	}
	friend ostream& operator<<(ostream& os, const Scoreboard& s);
	string getCourseID() {
		return courseId;
	}
	void print();

};

