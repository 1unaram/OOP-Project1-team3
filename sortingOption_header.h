/* sorting function header */

#ifndef UNTITLED1_SORTINGOPTION_HEADER_H
#define UNTITLED1_SORTINGOPTION_HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // sort()
#include <vector>

#include "Student.h"

using namespace std;

void sorting(int num);
bool compare_name(Student s1,  Student s2);
bool compare_studentID(Student s1,  Student s2);
bool compare_admissionYear(Student s1,  Student s2);
bool compare_departmentName(Student s1,  Student s2);



#endif //UNTITLED1_SORTINGOPTION_HEADER_H
