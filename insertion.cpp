/* insertion.cpp */

#include "insertion_header.h"

// variable forward declarations (�ܺ� ���� ���� ���)
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

	// ���� üũ
	if (name.size() == 0 || id.size() == 0) {
		cout << "Error: Name and Student ID should not be blank..\n\n";
		return;
	}
	// Student ID �ߺ� üũ
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
	// Input���� ���� Student ID�� ���� �ý��ۿ� �����ϴ��� üũ
	// true: �ý��ۿ� �������� ���� & false: �ý��ۿ� ������

	for (Student s : students) {
		if (!id.compare(s.getStudentID())) {
			return false;
		}
	}

	return true;
}