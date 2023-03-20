#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Course {
private:
    char courseId[10];
    char* courseName;
    char* className;
    char* teacherName;
    int numOfCredits;
    int maxStudents;
    string dayOfWeek;
    string session;
    string semester;
    list<string> listOfStudents;

public:
    
    Course(char* id, char* name, char* className, char* teacherName, int credits, int max = 50, string day = "M", string sess = "AM", string sem = "current");

    
    ~Course();

   
    char* getCourseId();
    char* getCourseName();
    char* getClassName();
    char* getTeacherName();
    int getNumOfCredits();
    int getMaxStudents();
    string getDayOfWeek();
    string getSession();
    string getSemester();
    list<string> getListOfStudents();
    void setCourseId(char* id);
    void setCourseName(char* name);
    void setClassName(char* className);
    void setTeacherName(char* teacherName);
    void setNumOfCredits(int credits);
    void setMaxStudents(int max);
    void setDayOfWeek(string day);
    void setSession(string sess);
    void setSemester(string sem);

    // import students from a CSV file
    void importStudentsFromCSV(char* filename);

    // print the list of students in the course
    void printListOfStudents();

    // print the course information
    void printCourseInfo();
};
