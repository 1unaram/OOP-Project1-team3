/* insertion.cpp */

#include "insertion_header.h"

// variable forward declarations (외부 전역 변수 사용)
extern vector<Student> students;
extern string filename;

void insertion() {

	cout << "[Insert Mode]" << endl;

	// Input Student info from user
	string name;
	cout << "Name: ";
	cin >> name;

	string id;
	cout << "Studnet ID(10 digits): ";
	cin >> id;

	string birth;
	cout << "Birth Year (4 digits): ";
	cin >> birth;

	string dept;
	cout << "Department: ";
	cin >> dept;

	string tel;
	cout << "Tel: ";
	cin >> tel;

	// 공백 체크
	if (name.size() == 0 || id.size() == 0) {
		cout << "Error: Name and Student ID should not be blank..\n\n";
		return;
	}
	// Student ID 중복 체크
	if (!checkStudentID(id)) {
		cout << "Error: Already inserted..\n\n";
		return;
	}


	string studentInfoStr = name + "," + id + "," + birth + "," + dept + "," + tel + "\n";
	ofstream writeFile;
	writeFile.open(filename, ios::in | ios::app);

	if (writeFile.is_open()) {
		writeFile.write(studentInfoStr.c_str(), studentInfoStr.size());
		writeFile.close();
		cout << "** Success to insert! **\n\n";
	}
	else {
		cout << "Error: Fail to open file..\n\n";
	}
}

bool checkStudentID(string id) {
	// Input으로 들어온 Student ID가 기존 시스템에 존재하는지 체크
	// true: 시스템에 존재하지 않음 & false: 시스템에 존재함

	for (Student s : students) {
		if (!id.compare(s.getStudentID())) {
			return false;
		}
	}

	return true;
}