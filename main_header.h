/* main function header */

// Include library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm> // sort()

#include "Student.h"

// Namespace
using namespace std;

// Function Prototype
void printMenu();
void insertion();
void fileRead();
void search();
void sortingOption();

// insertion_header
bool checkStudentID(string);

// search_header
void searchName(string);
void searchId(string);
void searchAdYear(string);
void searchDepName(string);
void listAll();

// sorting_header
void sorting();
bool compare_name(Student, Student);
bool compare_studentID(Student, Student);
bool compare_admissionYear(Student, Student);
bool compare_departmentName(Student, Student);
string getOption();