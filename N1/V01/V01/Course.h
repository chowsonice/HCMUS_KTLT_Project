#include "Node.h"

class Course
{
	char CourseId[6];
	char* name;
	char* classId;
	char* teacherName;
	int noCredits;
	int maxNoStudents = 50;
	char dayOfTheWeek[4];
	/*Semester sem;*/
	Node<Student>* listOfStudents = nullptr;
public:
	bool importStudents();
};

