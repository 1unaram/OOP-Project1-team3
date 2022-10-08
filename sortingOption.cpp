/* sortingOption.cpp */

#include "main_header.h"

extern vector<Student> _students;
extern int _sortingOption;

void sortingOption()
{
    while (true) {

        char menu;

        cout << "[Sorting Option]" << endl;
        cout << "1. Sort by Name" << endl;
        cout << "2. Sort by Student ID" << endl;
        cout << "3. Sort by Admission Year" << endl;
        cout << "4. Sort by Department name" << endl;
        cout << "> ";

        cin >> menu;
        cout << endl;

        switch (menu) {
        case '1':
            cout << "** Complete to Set Sorting Option By Name **" << endl << endl;
            _sortingOption = 1;
            return;
        case '2':
            cout << "** Complete to Set Sorting Option By Student ID **" << endl << endl;
            _sortingOption = 2;
            return;
        case '3':
            cout << "** Complete to Set Sorting Option By Admission Year **" << endl << endl;
            _sortingOption = 3;
            return;
        case '4':
            cout << "** Complete to Set Sorting Option By Department Name **" << endl << endl;
            _sortingOption = 4;
            return;
        default:
            cout << "Error: Please enter the correct menu.." << endl << endl;
            
            cin.ignore();
        }
    }
}

void sorting()
{
    switch (_sortingOption) {
    case 1:
        sort(_students.begin(), _students.end(), compare_name);
        return;
    case 2:
        sort(_students.begin(), _students.end(), compare_studentID);
        return;
    case 3:
        sort(_students.begin(), _students.end(), compare_admissionYear);
        return;
    case 4:
        sort(_students.begin(), _students.end(), compare_departmentName);
        return;
    }
}

string getOption() {
    switch (_sortingOption) {
    case 1:
        return "By Name";
    case 2:
        return "By Student ID";
    case 3:
        return "By Admission Year";
    case 4:
        return "By Department Name";
    }

    return "0";
}

bool compare_name(Student s1, Student s2)
{
    return s1.getName() < s2.getName();
}

bool compare_studentID(Student s1, Student s2)
{
    return s1.getStudentID() < s2.getStudentID();
}

bool compare_admissionYear(Student s1, Student s2)
{

    return s1.getStudentID().substr(0, 4) < s2.getStudentID().substr(0, 4);
}

bool compare_departmentName(Student s1, Student s2)
{
    return s1.getDepartment() < s2.getDepartment();
}