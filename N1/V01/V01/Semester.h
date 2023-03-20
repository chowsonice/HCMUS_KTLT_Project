#include "SchoolYear.h"
#include "Course.h"
using namespace std;

class Semester
{
    private:
        SchoolYear _schoolYear;
        int _number;
        Course* _listOfCourses;
    public:
        Semester(SchoolYear schoolYear, int number, Course* listOfCourses);
        ~Semester();
};