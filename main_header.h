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
void searchName(string name);
void searchId(string sId);
void searchAdYear(string sYear);
void searchDepName(string sDepName);
void listAll();

// sorting_header
void sorting(int num);
bool compare_name(Student s1, Student s2);
bool compare_studentID(Student s1, Student s2);
bool compare_admissionYear(Student s1, Student s2);
bool compare_departmentName(Student s1, Student s2);