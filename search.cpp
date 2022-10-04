/* search function */

#include "search_header.h"

extern vector<Student> students;
extern string filename;

void search() {
	int menu;
	
	cout << "[Search Mode]" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by admission year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << ">  ";

	cin >> menu;
	cout << endl;

	switch (menu) {
	case 1: {
		string sName;
		cout << "Name keyword ?  ";
		getline(cin, sName);
		searchName(sName);
		break;
	}		
	case 2: {
		string sId;
		cout << "Id keyword ?  ";
		getline(cin, sId);
		searchId(sId);
		break;
	}
	case 3: {
		string sYear;
		cout << "Admission Year ?  ";
		getline(cin, sYear);
		searchAdYear(sYear);
		break;
	}
	case 4: {
		string sDepName;
		cout << "Department name keyword ?  ";
		getline(cin, sDepName);
		searchDepName(sDepName);
		break;
	}
	case 5:							// 5 -> 처음 Student 저장 후 sort by name 필요
		listAll();
		break;
	default:
		cout << "Wrong Menu";
	}
}


void searchName(string sName) {
	for (Student s : students) {
		if(s.getName() == sName) {
			s.printDefault();
			s.printStudentInfo();
			break;
		}
	}
}

void searchId(string sId) {
	for (Student s : students) {
		if (s.getStudentID() == sId) {
			s.printDefault();
			s.printStudentInfo();
			break;
		}
	}
}

void searchAdYear(string sYear) {
	for (Student s : students) {
		if (s.getBirthYear() == sYear) {
			s.printDefault();
			s.printStudentInfo();
			break;
		}
	}
}

void searchDepName(string sDepName) {
	for (Student s : students) {
		if (s.getDepartment() == sDepName) {
			s.printDefault();
			s.printStudentInfo();
			break;
		}
	}
}

void listAll() {
	Student temp;
	temp.printDefault();

	for (Student s : students) {
		s.printStudentInfo();
	}
}