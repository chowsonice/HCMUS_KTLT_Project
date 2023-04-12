// V01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "SchoolYear.h"
#include "Semester.h"
#include "Course.h"
#include "Class.h"
#include "Student.h"
#include "University.h"

int main()
{
    Account main;
    University uni;
    
    try {
        loginScreen(main);
    }
    catch (const char* error) {
        cout << "ERROR: " << error << endl;
        return -1;
    }
    if (main.getType() == 1) staffMenu();
    else if (main.getType() == 2) {
        // T nghĩ là mình cần chỉnh lại một chút phần student
        // Thông tin student t thấy là mình nên xuất ra thành file hết, rồi khi đăng nhập vào thì tìm file đó mà đọc thôi
        // Vậy nên chắc mình thêm:
        // 1. Hiếu - Student thêm phần, exportToText(), xuất thông tin student ra file, trong thư mục student_data/[MSSV].txt
        // Student có thay đổi gì (update thông tin /  update scoreboard) gì thì phải xuất ra hết
        // 2. XĐ - Thêm hàm ngoài Student* readStudentFromFile() để đọc thông tin student để cho phần StudentMenu
        // Do xong 2 cái đó mới làm cái này được nên làm nhanh nha
    }
    return 0;
}
