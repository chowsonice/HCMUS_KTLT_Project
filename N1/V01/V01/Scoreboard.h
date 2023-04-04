#pragma once
#include <iostream>

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

	friend ostream& operator<<(ostream& os, const Scoreboard& s);


};

