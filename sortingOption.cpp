/* sortingOption.cpp */

#include "main_header.h"

extern vector<Student> students;

void sortingOption()
{
    int choice;

    cout << "[Sorting Option]" << endl;
    cout << "1. Sort by Name" << endl;
    cout << "2. Sort by Student ID" << endl;
    cout << "3. Sort by Admission Year" << endl;
    cout << "4. Sort by Department name" << endl;
    cout << "> ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            sorting(1);
            break;
        case 2:
            sorting(2);
            break;
        case 3:
            sorting(3);
            break;
        case 4:
            sorting(4);
            break;
    }
}

bool compare_name(Student s1,  Student s2)
{
    return s1.getName() < s2.getName();
}

bool compare_studentID(Student s1,  Student s2)
{
    return s1.getStudentID() < s2.getStudentID();
}

bool compare_admissionYear(Student s1,  Student s2)
{

    return s1.getStudentID().substr(0,4) < s2.getStudentID().substr(0,4);
}

bool compare_departmentName(Student s1,  Student s2)
{
    return s1.getDepartment() < s2.getDepartment();
}

void sorting(int num)
{

    switch(num) {
        case 1:
            cout << "~ Complete to Sort By Name ~" << endl;
            sort(students.begin(), students.end(), compare_name);
            break;
        case 2:
            cout << "~ Complete to Sort By Student ID ~" << endl;
            sort(students.begin(), students.end(), compare_studentID);
            break;
        case 3:
            cout << "~ Complete to Sort By Admission Year ~" << endl;
            sort(students.begin(), students.end(), compare_admissionYear);
            break;
        case 4:
            cout << "~ Complete to Sort By Department Name ~" << endl;
            sort(students.begin(), students.end(), compare_departmentName);
            break;
    }

    Student().printDefault();

    for (Student s : students) {
        s.printStudentInfo();
    }

    Student().printContainer();

    cout << endl;

}