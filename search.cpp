/* search.cpp */

#include "main_header.h"

extern vector<Student> _students;

void search() {

	// Sort by Set Option
	sorting();

	while (true) {

		char menu;

		cout << "[Search Mode]" << endl;
		cout << "1. Search by name" << endl;
		cout << "2. Search by student ID (10 numbers)" << endl;
		cout << "3. Search by Admission year (4 numbers)" << endl;
		cout << "4. Search by department name" << endl;
		cout << "5. List All" << endl;
		cout << ">  ";

		cin >> menu;
		cout << endl;
		cin.ignore();

		switch (menu) {
		case '1': {
			string sName;
			cout << "Name keyword ?  ";
			getline(cin, sName);
			searchName(sName);
			return;
		}
		case '2': {
			string sId;
			cout << "Id keyword ?  ";
			getline(cin, sId);
			searchId(sId);
			return;
		}
		case '3': {
			string sYear;
			cout << "Admission Year keyword ?  ";
			getline(cin, sYear);
			searchAdYear(sYear);
			return;
		}
		case '4': {
			string sDepName;
			cout << "Department name keyword ?  ";
			getline(cin, sDepName);
			searchDepName(sDepName);
			return;
		}
		case '5':
			listAll();
			return;
		default:
			cout << "Error: Please enter the correct menu.." << endl << endl;
		}
	}

	cout << endl;
}

void searchName(string sName) {

	bool isMatching = false;
	Student().printDefault();

	cout << "/*  Results Exactly Matching  */" << endl;
	for (Student s : _students) {
		if (s.getName() == sName) {
			s.printStudentInfo();
			isMatching = true;
		}
	}
	if (!isMatching)
		cout << "(No Results Exactly Matching)" << endl;

	cout << endl;

	bool isContaining = false;
	cout << "/* Results Containing Keyword */" << endl;
	for (Student s : _students) {
		if (s.getName().find(sName) != string::npos)
			if (s.getName() != sName) {
				s.printStudentInfo();
				isContaining = true;
			}
	}

	if (!isContaining)
		cout << "(No Results Containing Keywords)" << endl;

	Student().printContainer();
	cout << endl;
}

void searchId(string sId) {

	bool isMatching = false;
	Student().printDefault();

	for (Student s : _students) {
		if (s.getStudentID() == sId) {
			s.printStudentInfo();
			isMatching = true;
			break;
		}
	}

	if (!isMatching)
		cout << "(No Exactly Matching Result)" << endl;

	Student().printContainer();
	cout << endl;
}

void searchAdYear(string sYear) {

	bool isMatching = false;
	Student().printDefault();

	for (Student s : _students) {
		if (s.getStudentID().substr(0, 4) == sYear) {
			s.printStudentInfo();
			isMatching = true;
		}
	}

	if (!isMatching)
		cout << "(No Exactly Matching Result)" << endl;

	Student().printContainer();
	cout << endl;
}

void searchDepName(string sDepName) {

	bool isMatching = false;
	Student().printDefault();

	cout << "/*  Results Exactly Matching  */" << endl;
	for (Student s : _students) {
		if (s.getDepartment() == sDepName) {
			s.printStudentInfo();
			isMatching = true;
		}
	}

	if (!isMatching)
		cout << "(No Exactly Matching Result)" << endl;

	cout << endl;

	bool isContaining = false;
	cout << "/* Results Containing Keyword */" << endl;
	for (Student s : _students) {
		if (s.getDepartment().find(sDepName) != string::npos)
			if (s.getName() != sDepName) {
				s.printStudentInfo();
				isContaining = true;
			}
	}

	if (!isContaining)
		cout << "(No Result Containing Keywords)" << endl;

	Student().printContainer();
	cout << endl;
}

void listAll() {

	Student().printDefault();

	for (Student s : _students) {
		s.printStudentInfo();
	}

	Student().printContainer();
	cout << endl;
}