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

void SchoolYear::createNewSemester()
{
    int n = semesters.size();
    if (n >= 3) {
        cout << "Cannot add another semester to this school year!\n Create a new one and try again.\n";
        return;
    }
    curSem = new Semester(n + 1);
    curSem->setYear(_start, _end);
    semesters.push_back(curSem);
}

Semester* SchoolYear::getCurrentSemester()
{
    return curSem;
}

int SchoolYear::getCurrentNSemester() {
    return semesters.size();
}

void importFromFile(University &uni, LinkedList<SchoolYear*>& years) {
    ifstream fin("info/SchoolYear_info.txt");
    while (!fin.eof()) {
        SchoolYear* y = new SchoolYear();
        int n = 0;
        fin >> y->_start >> y->_end;
        fin >> n;
        fin.ignore(1000, '\n');
        for (int i = 0; i < n; i++) {
            Semester* s = new Semester();
            y->curSem = s;
            fin >> *s;
            for (Course* c : s->listOfCourses) {
                c->importStudentsFromCSV(uni);
            }
            y->semesters.push_back(s);
        }
        years.push_back(y);
    }
    
}
void exportToFile(LinkedList<SchoolYear*> years){
    ofstream fout("info/SchoolYear_info.txt");
    for (SchoolYear* y : years) {
        fout << y->_start << " " << y->_end << endl;
        fout << y->semesters.size() << endl;
        for (Semester* s : y->semesters) {
            fout << *s << endl;
        }
    }
}