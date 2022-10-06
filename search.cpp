#include "search_header.h"

extern vector<Student> students;

void search() {
	int menu;

	cout << "[Search Mode]" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by birth year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << ">  ";

	cin >> menu;
	cout << endl;
	cin.ignore();

	switch (menu) {
	case 1: {
		string sName;
		cout << "Name keyword ?  ";
		getline(cin, sName);
		cout << endl;
		searchName(sName);
		break;
	}
	case 2: {
		string sId;
		cout << "Id keyword ?  ";
		getline(cin, sId);
		cout << endl;
		searchId(sId);
		break;
	}
	case 3: {
		string sYear;
		cout << "Birth Year keyword ?  ";
		getline(cin, sYear);
		cout << endl;
		searchBirthYear(sYear);
		break;
	}
	case 4: {
		string sDepName;
		cout << "Department name keyword ?  ";
		getline(cin, sDepName);
		cout << endl;
		searchDepName(sDepName);
		break;
	}
	case 5:
		listAll();
		break;
	default:
		cout << "Error: Wrong Menu..";
	}

	cout << endl;
}

void searchName(string sName) {

	bool isMatching = false;
	Student().printDefault();

	cout << "/*  Results Exactly Matching  */" << endl;
	for (Student s : students) {
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
	for (Student s : students) {
		if (s.getName().find(sName) != string::npos)
			if (s.getName() != sName) {
				s.printStudentInfo();
				isContaining = true;
			}
	}

	if (!isContaining)
		cout << "(No Results Containing Keywords)" << endl;

	Student().printContainer();
}

void searchId(string sId) {

	bool isMatching = false;
	Student().printDefault();

	for (Student s : students) {
		if (s.getStudentID() == sId) {
			s.printStudentInfo();
			isMatching = true;
			break;
		}
	}

	if (!isMatching)
		cout << "(No Exactly Matching Result)" << endl;

	Student().printContainer();
}

void searchBirthYear(string sYear) {

	bool isMatching = false;
	Student().printDefault();

	for (Student s : students) {
		if (s.getBirthYear() == sYear) {
			s.printStudentInfo();
			isMatching = true;
		}
	}

	if (!isMatching)
		cout << "(No Exactly Matching Result)" << endl;

	Student().printContainer();
}

void searchDepName(string sDepName) {

	bool isMatching = false;
	Student().printDefault();

	cout << "/*  Results Exactly Matching  */" << endl;
	for (Student s : students) {
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
	for (Student s : students) {
		if (s.getDepartment().find(sDepName) != string::npos)
			if (s.getName() != sDepName) {
				s.printStudentInfo();
				isContaining = true;
			}
	}
	
	if (!isContaining)	
		cout << "(No Result Containing Keywords)" << endl;

	Student().printContainer();
}

void listAll() {

	Student().printDefault();

	for (Student s : students) {
		s.printStudentInfo();
	}

	Student().printContainer();
}