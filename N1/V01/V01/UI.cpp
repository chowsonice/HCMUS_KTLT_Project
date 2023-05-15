#pragma warning(disable: 6031)
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
			pass.clear();
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

void changePassword(Account& main) {
	string oldPassword, newPassword;
	cout << "CHANGE PASSWORD\n";
	cout << "----------------------------------------\n";
	cout << "Please enter your old password: ";
	getline(cin, oldPassword);
	cout << "Please enter your new password: ";
	getline(cin, newPassword);

	if (main.changePassword(oldPassword, newPassword))
	{
		cout << "Password changed successfully." << endl;
	}
	else
	{
		cout << "Password change failed." << endl;
	}
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
		cin.ignore(1000, '\n');
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
			profile(main, s);
			break;
		default:
			throw "Invalid option.\n";
		}
		cin.ignore(1000, '\n');
	}
}
void profile(Account& acc, Student*& s) {
	int choice;
	while (true) {
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
		cin.ignore(1000, '\n');
		switch (choice) {
		case 0:
			return;
		case 1:
			changePassword(acc);
			break;
		default:
			cout << "Invalid option.\nPlease enter another.\n";
			_getch();
		}
	}
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
	Semester* cursem = nullptr;
	SchoolYear* curyear = nullptr;
	Course* course = nullptr;

	//updating curyear and cursem if existing
	if (years.size() > 0) cursem = years[0]->getCurrentSemester();
	if (cursem) {
		for (SchoolYear* y : years) {
			if (*y == cursem) {
				curyear = y;
				break;
			}
		}
	}

	while (choice != 0) {
		system("cls");
		cout << "Currently, it's ";
		if (!cursem) cout << "___" << endl;
		else cursem->printInfo();

		cout << "========================================================\n";
		cout << "||    0. Log out                                      ||\n";
		cout << "||    1. View a list of classes                       ||\n";
		cout << "||    2. View list of students in a class             ||\n";
		cout << "||    3. View list of students in a course            ||\n";
		cout << "||    4. Create a new school year                     ||\n";
		cout << "||    5. Create a new semester                        ||\n";
		cout << "||    6. Create a new class                           ||\n";
		cout << "||    7. Export list of student from course to CSV    ||\n";
		cout << "||    8. Import scoreboard of course                  ||\n";
		cout << "||    9. View scoreboard of course                    ||\n";
		cout << "||    10. View scoreboard of class                    ||\n";
		cout << "||    11. Update a student's results                  ||\n";
		if (cursem) cout << "||    12. Change semester's information               ||\n";
		cout << "========================================================\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		int b1;
		string buffer, classID, studentID;
		Student* s = nullptr; Scoreboard* sb = nullptr;
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
			cout << "Enter starting year, enter 1 if current year, 0 to exit:\n";
			if (cin >> b1) {
				if (b1 == 1) {
					time_t t = time(NULL);
					struct tm curtime;
					auto buf = localtime_s(&curtime, &t);
					const int cur_year = (curtime.tm_year) + 1900;
					b1 = cur_year;
					curyear = new SchoolYear(b1, b1 + 1);
					cout << "School year " << b1 << " - " << b1 + 1 << " is created.\n This will be the default school year";
				}
				else if (b1 == 0) {
					cout << "Cancelled. Returning to menu...\n";
					_getch();
					break;
				}
				else if (b1 > 0) {
					curyear = new SchoolYear(b1, b1 + 1);
					cout << "School year " << b1 << " - " << b1 + 1 << " is created.\n This will be the default school year";
				}
				else {
					cout << "Illegal input.\n";
				}
			}
			else {
				cout << "Cancelled. Returning to menu...\n";
				break;
				_getch();
			}
			years.push_back(curyear);
			_getch();
			break;
		case 5:
			cursem = createNewSemester(years, curyear);
			if (cursem) menuNewSemesterInStaff(uni, cursem);
			break;
		case 6:
			if (years.size() < 1) {
				cout << "Cannot create a new class. Please create a school year first.\n";
				_getch();
				break;
			}
			else {
				uni.addClass();
			}
			break;
		case 7:
			cout << "Enter class ID: ";
			getline(cin, classID);
			cout << "\nEnter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer, classID);
			if (course != nullptr) {
				course->exportStudentListToCSV(buffer);
			}
			else {
				cout << "Could not find course!\n";
			}
			break;
		case 8:
			cout << "===========LIST OF COURSES===========\n";
			cursem->printListOfCourses();
			cout << "\nEnter class ID: ";
			getline(cin, classID);
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer, classID);
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
			_getch();
			break;
		case 9:
			cout << "LIST OF COURSES\n";
			cursem->printListOfCourses();
			cout << "Enter class ID: ";
			getline(cin, classID);
			cout << "\nEnter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer, classID);
			if (course != nullptr) {
				course->viewScoreboard();
				_getch();
			}
			else {
				cout << "Could not find course!\n";
			}
			_getch();
			break;
		case 10:
			viewScoreboardOfClass(uni);
			_getch();
			break;
		case 11:
			cout << "Enter class ID of course: ";
			getline(cin, classID);
			cout << "Enter course ID: ";
			getline(cin, buffer);
			course = cursem->findCourse(buffer, classID);
			cout << "============LIST OF STUDENTS============\n";
			course->printListOfStudents();
			cout << "\nEnter student's ID: ";
			getline(cin, studentID);
			s = course->findStudent(studentID);
			if (s) {
				int score = -1;
				sb = s->findScoreboard(buffer);
				if (sb) {
					cout << "|" << setw(10) << studentID << "|";
					sb->print();
					sb->updateScoreboard();
				}
			}
			else cout << "Student didn't participate in this course exists.\n";
			_getch();
			break;
		case 12:
			if (cursem) menuNewSemesterInStaff(uni, cursem);
			else cout << "NO SEMESTER AVAILABLE. PLEASE CREATE ONE AND TRY AGAIN LATER.\n";
			_getch();
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

	string courseID, classID;
	cout << "LIST OF COURSES\n";
	semester->printListOfCourses();
	cout << "Enter class ID: ";
	getline(cin, classID);
	cout << "Enter course ID: ";
	getline(cin, courseID);

	Course* selectedCourse = semester->findCourse(courseID, classID);

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
		cout << i++ << ": " << c->getClassName() << endl;
	}
	i = 1; 
	Class* pclass = nullptr;
	cin >> choiceclass;
	if (choiceclass <= 0 || choiceclass > uni.listOfClasses.size()) return;
	else {
		pclass = uni.listOfClasses[choiceclass - 1];
		cout << "List of students in class " << pclass->getClassName() << ":\n";
		pclass->printListOfStudents();
		_getch();
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
	if (c) {
		cout << "Enter course ID of the course you want to see: ";
		getline(cin, courseID);
		c->printScoreboardOfClass(courseID);
	}
}

//void updateStudentResult(Course* course) {
//	cout << "Choose a student to update result:\n";
//	course->printListOfStudents();
//	string id;
//	getline(cin, id);
//
//	
//	else {
//		pclass = uni.listOfClasses[choiceclass];
//		cout << "List of students in class " << pclass->getClassName() << ":\n";
//		pclass->printListOfStudents();
//	}
//}

Semester* createNewSemester(LinkedList<SchoolYear*> years, SchoolYear*& curyear) {
	cout << "Choose a school year that this semester belongs to:\n";
	int i = 1, inp = 0;
	cout << "O: Return\n";
	for (SchoolYear* y : years) {
		cout << i << ": " << *y << endl;
		i++;
	}
	cin >> inp;
	while (inp < 1 || inp > years.size()) {
		cin >> inp;
		cin.ignore(1000, '\n');
		if (inp == 0) {
			cout << "Exitting...\n";
			return nullptr;
		}
		cout << "Invalid choice. Please enter again.\nEnter 0  if cancel.\n";
		_getch();
	}
	i = 1;
	for (SchoolYear* y : years) {
		if (i == inp) {
			curyear = y;
			break;
		}
		else i++;
	}
	if (curyear) {
		curyear->createNewSemester();
		Semester* cursem = curyear->getCurrentSemester();
		cout << "Default semester is " << curyear->getCurrentNSemester() << " of school year " << *curyear << ".\n";
		_getch();
		return cursem;
	}
	cin.ignore(1000, '\n');
	return nullptr;
}

void menuNewSemesterInStaff(University& uni, Semester*& sem1)
{
	string courseID, studentID, classID;
	Course* course = nullptr;
	Student* student = nullptr;
	int choice = -1;

	while (choice != 0) {
		system("cls");
		cout << "              SEMESTER CONTROL\n";
		cout << "=============================================\n";
		cout << "||    0. RETURN                            ||\n";
		cout << "||    1. Add a course                      ||\n";
		cout << "||    2. View list of courses              ||\n";
		cout << "||    3. Update a course                   ||\n";
		cout << "||    4. Add student to a course           ||\n";
		cout << "||    5. Remove a student from a course    ||\n";
		cout << "||    6. Delete a course                   ||\n";
		cout << "=============================================\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		
		switch (choice) {
		case 0:
			return;
		case 1:
			sem1->addCourse(uni);
			_getch();
			break;
		case 2:
			sem1->printInfoOfCourses();
			cout << "PRESS ANYTHING TO RETURN.\n";
			_getch();
			break;
		case 3:
			cout << "===========LIST OF COURSES=============\n";
			sem1->printListOfCourses();
			cout << "\nEnter class ID: ";
			getline(cin, classID);
			cout << "\nEnter course ID: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID, classID);
			if (course == nullptr) {
				cout << "Course not found!\n";
				cout << "PRESS ANYTHING TO RETURN.";
				_getch();
				break;
			}
			course->updateCourse(sem1->getN(), sem1->getYear(), uni);
			_getch();
			break;
		case 4:
			cout << "==========LIST OF COURSES===========\n";
			sem1->printListOfCourses();
			cout << "\nEnter class ID of the course: ";
			getline(cin, classID);
			cout << "\nEnter course ID: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID, classID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				break;
			}
			cout << "Enter student ID to add student to "
				<< courseID << ": ";
			getline(cin, studentID);
			student = uni.findStudent(studentID);
			
			if (student == nullptr) {
				cout << "Student not found in this University!\n";
				cout << "PRESS ANYTHING TO RETURN.\n";
				_getch();
				break;
			}
			else {
				Student* tempStu = course->findStudent(studentID);
				if (tempStu != nullptr) {
					cout << "Student ID " << studentID << " is already in the course.\n";
					cout << "PRESS ANYTHING TO RETURN.\n";
					_getch();
					break;
				}
				else {
					course->addStudent(student);
					cout << "Student ID " << student->getId() << " added to the course.\n";
					cout << "PRESS ANYTHING TO RETURN.\n";
					_getch();
					break;
				}
			}
		case 5:
			sem1->printListOfCourses();
			cout << "Enter class ID: ";
			getline(cin, classID);
			cout << "\nEnter course ID: ";
			getline(cin, courseID);
			course = sem1->findCourse(courseID, classID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				_getch();
				break;
			}
			cout << "=============LIST OF STUDENTS===============";
			course->printListOfStudents();
			cout << "Enter student ID to remove student to "
				<< courseID << ": ";
			getline(cin, studentID);
			student = uni.findStudent(studentID);
			if (student == nullptr) {
				cout << "Student not found in the University!\n";
				cout << "PRESS ANYTHING TO RETURN.\n";
				_getch();
				break;
			}
			else {
				Student* tempStu = course->findStudent(studentID);
				if (tempStu == nullptr) {
					cout << "Student ID " << studentID << " is not in this course.\n";
					cout << "PRESS ANYTHING TO RETURN.\n";
					_getch();
					break;
				}
				else {
					course->removeStudent(studentID);
					cout << "PRESS ANYTHING TO RETURN.\n";
					_getch();
					break;
				}
			}
		case 6:
			cout << "LIST OF COURSES\n";
			sem1->printListOfCourses();
			cout << "Enter class ID: ";
			getline(cin, classID);
			cout << "\nEnter course ID to delete: ";
			getline(cin, courseID);

			course = sem1->findCourse(courseID, classID);
			if (course == nullptr) {
				cout << "Course not found.\n";
				_getch();
				break;
			}

			sem1->deleteCourse(courseID, classID); // co ve cho nay sai
			cout << "Removed course " << courseID << ".\n";
			cout << "PRESS ANYTHING TO RETURN.\n";
			_getch();
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