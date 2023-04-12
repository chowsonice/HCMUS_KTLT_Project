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
	float totalMark;
	float finalMark;
	float midtermMark;
	float otherMark;
public:
	Scoreboard() : courseId(""), totalMark(0), finalMark(0), midtermMark(0), otherMark(0) {}
	Scoreboard(string courseId) : courseId(courseId), totalMark(0), finalMark(0), midtermMark(0), otherMark(0) {}
	Scoreboard(string courseId, float midtermMark, float otherMark, float finalMark, float totalMark);
	Scoreboard(const Scoreboard& sb) : Scoreboard(sb.courseId, sb.midtermMark, sb.otherMark, sb.finalMark, sb.totalMark) {}
	~Scoreboard();

	const string getCourseId() const;
	float getTotalMark() const;
	float getFinalMark() const;
	float getMidtermMark() const;
	float getOtherMark() const;

	void setCourseId(const string courseId);
	void setTotalMark(float totalMark);
	void setFinalMark(float finalMark);
	void setMidtermMark(float midtermMark);
	void setOtherMark(float otherMark);

	bool updateScoreboard(string line) {
		stringstream ss;
		if (updated) {
			cout << "Scoreboard of "<< courseId << " has already had values.\n Cannot update scoreboard!\n";
			return false;
		}
		else {
			ss << line;
			if (!(ss >> midtermMark) || (midtermMark < 0 || midtermMark > 10)) throw "Invalid input!";
			if (!(ss >> finalMark) || (finalMark < 0 || finalMark > 10)) throw "Invalid input!";
			if (!(ss >> otherMark) || (otherMark < 0 || otherMark > 10)) throw "Invalid input!";
			if (!(ss >> totalMark) || (totalMark < 0 || totalMark > 10)) throw "Invalid input!";
			updated = true;
		}
		return true;
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

