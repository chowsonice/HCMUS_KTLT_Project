﻿#pragma warning(disable: 6031)
#include <iostream>
#include "UI.h"


void loginScreen(Account &main) {
	string usrn, pass;
	int count = 0, type = -1;
	while (count < 3) {
		cout << "Welcome to the University Management System!\n";
		cout << "===========================================\n";
		cout << "LOGIN\n";
		cout << "Username: ";
		cin >> usrn;
		cin.ignore(1000, '\n');
		cout << "Password: ";
		char c = 'a';
		while ((c = _getch()) != '\r') {
			if (pass.length() > 0 && c == '\b') {
				printf("\b \b");
				pass.erase(pass.begin() + pass.length() - 1);
			}
			else if (c != '\t' && c > 32 && c < 127) {
				cout << "*";
				pass += c;
			}
			else {
				throw "Invalid character in password";
				break;
			}
		}
		cout << endl;
		type = checkLogin(usrn, pass);
		if (type != -1) {
			cout << "Login successful. \nReturning to the main menu...\n";
			break;
		}
		else {
			cout << "Wrong username or password. You have "<< 2 - count << " more tries.\nPRESS ANYTHING TO CONTINUE\n";
			_getch();
			system("cls");
			count++;
		}
		if (count >= 3) {
			cout << "SYSTEM EXITING...\n";
			throw "Invalid login";
			return;
		}
	}
	main = Account(usrn, pass, type);
}

void change_passwordScreen(Account& main) {
	string oldPassword, newPassword;
	cout << "Change Password\n";
	cout << "-------------------------------------------\n";
	cout << "Please enter your old password: ";
	getline(cin, oldPassword);
	cout << "Please enter your new password: ";
	getline(cin, newPassword);

	/*if (main.changePassword(oldPassword, newPassword))
	{
		cout << "Password changed successfully." << endl;
	}
	else
	{
		cout << "Password change failed." << endl;
	}*/
}

void studentMenu(Account& main) {
	int choice = 1;
	Student* s = readStudentFromFile(main.getUsername());
	while (choice != 0) {
		system("cls");
		cout << "Currently, it's ___" << endl;
		cout << "=============================\n";
		cout << "0. Log out\n";
		cout << "1. View your courses this semester\n";
		cout << "2. View your scoreboards\n";
		cout << "3. View profile\n";
		cout << "=============================\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;
		switch (choice) {
		case 0:
			return;
		case 1:
			s->printCourseThisSem();
			_getch();
			break;
		case 2:
			studentScoreboard(s);
			_getch();
			break;
		case 3:
			profile(s);
			break;
		default:
			throw "Invalid option.\n";
		}
		cin.ignore(1000, '\n');
	}
}
void profile(Student*& s) {
	int choice;
	system("cls");
	cout << "PROFILE\n";
	cout << "=============================\n";
	s->printStudentInfo();
	cout << "=============================\n";
	cout << "0. Return to menu\n";
	cout << "1. Change password\n";
	cout << "-----------------------------\n";
	cout << "YOUR CHOICE: ";
	cin >> choice;
	switch (choice) {
	case 0:
		return;
	case 1:
		break;
	default:
		throw "Invalid option.\n";
	}
	cin.ignore(1000, '\n');
}

void studentScoreboard(Student* s) {
	int choice;
	string buffer;
	system("cls");
	cout << "SCOREBOARD\n";
	cout << "=============================\n";
	cout << "0. Return to menu\n";
	cout << "1. See all scoreboards\n";
	cout << "2. Find scoreboard of a course\n";
	cout << "-----------------------------\n";
	cout << "YOUR CHOICE: ";
	cin >> choice;
	cin.ignore(1000, '\n');
	Scoreboard* sb;
	switch (choice) {
	case 0:
		return;
	case 1:
		s->printAllScoreboard();
		break;
	case 2:
		cout << "Enter course ID of the course you want to see: ";
		getline(cin, buffer);
		sb = s->findScoreboard(buffer);
		while (sb == nullptr) {
			cout << "Such course doesn't exist.\nPlease try again or enter 0 to return to menu.\n";
			getline(cin, buffer);
			if (buffer == "0") return;
			else sb = s->findScoreboard(buffer);
		}
		sb->print();
		return;
	default:
		throw "Invalid option.\n";
	}
}

void staffMenu(University& uni, LinkedList<SchoolYear*>& years) {
	system("cls");
	int choice = 1;
	SchoolYear* curyear = nullptr;
	Semester* cursem = nullptr;
	Course* course = nullptr;
	while (choice != 0) {
		system("cls");
		cout << "Currently, it's ___" << endl;
		cout << "=============================\n";
		cout << "0. Log out\n";
		cout << "1. View a list of classes\n";
		cout << "2. View list of students in a class\n";
		cout << "3. View list of students in a course\n";
		cout << "4. Create a new school year\n";
		cout << "5. Create a new semester\n";
		cout << "6. Create a new class\n";
		cout << "7. Export list of student from course to CSV\n";
		cout << "8. Import scoreboard of course\n";
		cout << "9. View scoreboard of course\n";
		cout << "10. View scoreboard of class\n";
		cout << "11. Update student's result\n";
		cout << "=============================\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		int b1;
		string buffer;
		switch (choice) {
		case 0:
			return;
		case 1:
			uni.printListOfClasses();
			cout << "Press anything to return to menu.\n";
			_getch();
			break;
		case 2:
			printStudentsInClass(uni);
			break;
		case 3:
			printStudentsInCourse(cursem);
			break;
		case 4:
			cout << "Enter starting year, enter 0 if current year:\n";
			cin >> b1;
			cout << "School year " << b1 << " - " << b1 + 1 << " is created.\n This will be the default school year";
			
			if (b1 == 0) {
				time_t t = time(NULL);
				struct tm curtime;
				auto buf = localtime_s(&curtime, &t);
				const int b1 = (curtime.tm_year) + 1900;
				curyear = new SchoolYear(b1, b1+1);
			}
			else {
				curyear = new SchoolYear(b1, b1+1);
			}
			years.push_back(curyear);
			_getch();
			break;
		case 5:
			//cai nay minh chua hieu lam :(( same
			cursem = createNewSemester(years, curyear);
			menuNewSemesterInStaff(uni, cursem);
			break;
		case 6:
			if (years.size() <= 1 || cursem == nullptr) {
				cout << "Can not create a new class. Please create a school year and semester first.\n";
				_getch();
				break;
			}
			else {
				uni.addClass();
			}
			break;
		case 7:
			cursem->printListOfCourses();
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer);
			if (course != nullptr) {
				course->exportStudentListToCSV(buffer);
			}
			else {
				cout << "Could not find course!\n";
			}
			break;
		case 8:
			cursem->printListOfCourses();
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer);
			if (course != nullptr) {
				try {
					course->importScoreboard();
					cout << "Scoreboard imported successfully!\n";
				}
				catch (const char* err) {
					cout << "Error: " << err << endl;
				}
			}
			else {
				cout << "Could not find course!\n";
			}
			break;
		case 9:
			cursem->printListOfCourses();
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer);
			if (course != nullptr) {
				course->viewScoreboard();
			}
			else {
				cout << "Could not find course!\n";
			}
			break;
		case 10:
			viewScoreboardOfClass(uni);
			break;
		case 11:
			cursem->printListOfCourses();
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer);
			if (course != nullptr) {
				updateStudentResult(course, buffer);
			}
			else {
				cout << "Could not find course!\n";
			}
			break;
		default:
			throw "Invalid option.\n";
		}
	}
	return;
}

void printStudentsInCourse(Semester* semester) {
	system("cls");

	if (!semester) {
		cout << "There are no semesters available.\n";
		cout << "Press anything to return to menu.\n";
		_getch();
		return;
	}

	string choice;
	cout << "Choose a semester:\n";
	semester->printListOfCourses();
	cout << "Your choice: ";
	getline(cin, choice);

	Course* selectedCourse = semester->findCourse(choice);

	if (!selectedCourse) {
		cout << "Invalid course selection.\n";
		cout << "Press anything to return to menu.\n";
		_getch();
		return;
	}

	cout << "List of students in " << selectedCourse->getName() << "(" << selectedCourse->getCourseId() << ")" << ":" << endl;
	selectedCourse->printListOfStudents();
	cout << "Press anything to return to menu.\n";
	_getch();
}

void printStudentsInClass(University& uni){
	cout << "Choose which class:\n";
	int i = 1, choiceclass = 0;
	for (Class* c : uni.listOfClasses) {
		cout << i << ": " << *c << endl;
		i++;
	}
	i = 1; Class* pclass = nullptr;
	cin >> choiceclass;
	if (choiceclass <= 0 || choiceclass > uni.listOfClasses.size()) return;
	else {
		pclass = uni.listOfClasses[choiceclass];
		cout << "List of students in class " << pclass->getClassName() << ":\n";
		pclass->printListOfStudents();
	}
}

void viewScoreboardOfClass(University& uni) {
	string classID, courseID;
	cout << "Enter a class:\n";
	getline(cin, classID);
	Class* c = uni.findClass(classID);
	while (c == nullptr) {
		cout << "Such class doesn't exist.\nPlease try again or enter 0 to return to menu.\n";
		getline(cin, classID);
		if (classID == "0") return;
		else c = uni.findClass(classID);
	}
	cout << "Enter course ID of the course you want to see: ";
	getline(cin, courseID);
	c->printScoreboardOfClass(courseID);
}

void updateStudentResult(Course* course, string courseID) {
	cout << "Enter a studentID to update result:\n";
	course->printListOfStudents();
	string choice;
	getline(cin, choice);
	Student* st = course->findStudent(choice);
	if (!st) return;
	else {
		string line;
		cout << "Enter which line need to update: ";
		getline(cin, line);
		st->updateScoreboard(courseID, line);
	}
}

Semester* createNewSemester(LinkedList<SchoolYear*> years, SchoolYear*& curyear) {
	cout << "Choose a school year that this semester belongs to:\n";
	int i = 1, inp = 0;
	for (SchoolYear* y : years) {
		cout << "O: Return\n";
		cout << i << ": " << *y << endl;
		i++;
	}
	while (inp < 1 || inp > years.size()) {
		cin >> inp;
		cin.ignore(1000, '\n');
		if (inp == 0) {
			cout << "Exitting...\n";
			return nullptr;
		}
		cout << "Invalid choice. Please enter again.\n";
	}
	i = 1;
	for (SchoolYear* y : years) {
		if (i == inp) curyear = y;
		else i++;
	}
	if (curyear) {
		curyear->createNewSemester();
		Semester* cursem = curyear->getCurrentSemester();
		cout << "Default semester is " << curyear->getCurrentNSemester() << " of school year " << *curyear << ".\n";
		return cursem;
	}
	return nullptr;
}

void menuNewSemesterInStaff(University& uni, Semester* semNew)
{
	string courseID, studentID;
	system("cls");
	int choice = -1;
	while (choice != 0) {
		system("cls");
		cout << "\tNEW SEMESTER CONTROL" << endl;
		cout << "=====================\n";
		cout << "0. Log out\n";
		cout << "1. Add a course\n";
		cout << "2. View list of courses\n";
		cout << "3. Update a course\n";
		cout << "4. Add student to a course\n";
		cout << "5. Remove a student from a course\n";
		cout << "6. Delete a course\n";
		cout << "=============================\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		Semester* sem1 = new Semester();
		Course* course = nullptr;
		Student* student = nullptr;
		switch (choice) {
		case 0:
			return;
		case 1:
			sem1->addCourse();
			break;
		case 2:
			sem1->printListOfCourses();
			break;
		case 3:
			sem1->printListOfCourses();
			cout << "\nEnter course ID of the course to update: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				break;
			}
			course->updateCourse(*course);
			break;
		case 4:
			sem1->printListOfCourses();
			cout << "\nEnter course ID to add student to the course: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				break;
			}
			cout << "Enter student ID to add student to "
				<< courseID << ": ";
			getline(cin, studentID);
			student = uni.findStudent(studentID);
			if (student == nullptr) {
				cout << "Student not found!\n";
				break;
			}
			course->addStudent(student);
			break;
		case 5:
			sem1->printListOfCourses();
			cout << "\nEnter course ID to remove student out the course: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				break;
			}
			cout << "Enter student ID to remove student to "
				<< courseID << ": ";
			getline(cin, studentID);
			student = uni.findStudent(studentID);
			if (student == nullptr) {
				cout << "Student not found!\n";
				break;
			}
			course->removeStudent(studentID);
			cout << "Removed!\n";
			break;
		case 6:
			sem1->printListOfCourses();
			cout << "\nEnter course ID to delete: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID);
			course->deleteCourse(course);
			cout << "Da xoa " << courseID << " \n";
			//e ma nha, cai course nam trong 1 sem thi co nhieu
			//courseID giong nhau ma nhi :((
			break;
		default:
			throw "Invalid option!\n";
		}
	}
	return;
}


void saving(University& u, LinkedList<SchoolYear*>& y) {
	u.exportToFile();
	exportToFile(y);
}

void loading(University& u, LinkedList<SchoolYear*>& y) {
	u.importFromFile();
	importFromFile(u, y);
}