#include "Semester.h"

Semester::Semester(int number, LinkedList<Course*> listOfCourses)
{
    this->number = number;
    this->listOfCourses = LinkedList<Course*>(listOfCourses);
    year1 = 0;
    year2 = 0;
}
Semester::~Semester()
{}

void Semester::setYear(int y1, int y2) {
    year1 = y1;
    year2 = y2;
}

void Semester::addCourse(University& uni) {
    Course* course = new Course();
    course->input();
    course->setSemester(number, year1, year2);
    if (!course->importStudentsFromCSV(number, year1, uni)) {
        cout << "No list of students for this course available.\nPlease check again.\n";
        return;
    }
    listOfCourses.push_back(course);
}

void Semester::printListOfCourses() {
    for (Node<Course*> c : listOfCourses) cout << c.data->getClassId() << " - " << c.data->getCourseId() << endl;
}
void Semester::printInfoOfCourses() {
    for (Node<Course*> c : listOfCourses) c.data->viewCourseInfo() ;
}
Course* Semester::findCourse(string courseId, string classId) {
    for (Course* c : listOfCourses) {
        if (c->getCourseId() == courseId && c->getClassId() == classId) return c;
    }
    return nullptr;
}
void Semester::deleteCourse(string courseID, string classID) {
    int i = 1;
    for (Course* c : listOfCourses) {
        if (c->getCourseId() == courseID && c->getClassId() == classID) {
            listOfCourses.pop(i);
            return;
        }
        i++;
    }
}

ostream& operator<<(ostream& os, const Semester& s) {
    //cout << "Term ";
    os << s.number << "\n";
    //cout << "Total number of courses: ";
    os << s.listOfCourses.size() << endl;
    for (Course* c : s.listOfCourses) {
        os << *c << endl;
    }
    return os;
}

istream& operator>>(istream& is, Semester& s){
    is >> s.number;
    int n;
    is >> n;
    is.ignore(1000, '\n');
    for (int i = 0; i < n; i++) {
        Course* c = new Course();
        is >> *c;
        s.listOfCourses.push_back(c);
    }
    return is;
}

