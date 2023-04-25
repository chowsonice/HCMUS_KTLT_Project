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
	void setCourseName(string name);
	void setCourseTime(string courseTime);
	void setTotalMark(float totalMark);
	void setFinalMark(float finalMark);
	void setMidtermMark(float midtermMark);
	void setOtherMark(float otherMark);

	void printInfo();
	void updateScoreboard(string line);

	bool checkUpdated();
	friend ostream& operator<<(ostream& os, const Scoreboard& s);
	string getCourseID();
	void print();

};

