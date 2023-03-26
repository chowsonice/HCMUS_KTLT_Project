#pragma once
#include <iostream>

using namespace std;
class Scoreboard
{
private:
	char* courseId;
	char* studentId;
	int semester;
	char* schoolYear;
	float totalMark;
	float finalMark;
	float midtermMark;
	float otherMark;
public:
	Scoreboard() : courseId(nullptr), studentId(nullptr), semester(0), schoolYear(nullptr), totalMark(0), finalMark(0), midtermMark(0), otherMark(0) {}
	Scoreboard(const char* courseId, const char* studentId, int semester, const char* schoolYear, float totalMark, float finalMark, float midtermMark, float otherMark);
	Scoreboard(const Scoreboard& s) : Scoreboard(s.courseId, s.studentId, s.semester, s.schoolYear, s.totalMark, s.finalMark, s.midtermMark, s.otherMark) {}

	~Scoreboard();

	const char* getCourseId() const;
	const char* getStudentId() const;
	int getSemester() const;
	const char* getSchoolYear() const;
	float getTotalMark() const;
	float getFinalMark() const;
	float getMidtermMark() const;
	float getOtherMark() const;

	void setCourseId(const char* courseId);
	void setStudentId(const char* studentId);
	void setSemester(int semester);
	void setSchoolYear(const char* schoolYear);
	void setTotalMark(float totalMark);
	void setFinalMark(float finalMark);
	void setMidtermMark(float midtermMark);
	void setOtherMark(float otherMark);

	friend ostream& operator<<(ostream& os, const Scoreboard& s);


};

