#include "SchoolYear.h"

SchoolYear::SchoolYear(int start, int end) 
{
    _start = start;
    _end = end;
    curSem = nullptr;
}

ostream& operator<<(ostream& os, SchoolYear sy) {
    os << sy._start << " - " << sy._end;
    return os;
}
void SchoolYear::importFromFile(University &uni) {
    ifstream fin("info/SchoolYear_info.txt");
    int n = 0;
    if (fin.eof()) return;
    fin >> _start >> _end;
    fin >> n;
    fin.ignore(1000, '\n');
    for (int i = 0; i < n; i++) {
        Semester* s = new Semester();
        curSem = s;
        fin >> *s;
        for (Course* c : s->listOfCourses) {
            c->importStudentsFromCSV(uni);
        }
        semesters.push_back(s);
    }
}
void SchoolYear::exportToFile() {
    ofstream fout("info/SchoolYear_info.txt");
    fout << _start << " " << _end << endl;
    fout << semesters.size() << endl;
    for (Semester* s : semesters) {
        fout << *s << endl;
    }
}