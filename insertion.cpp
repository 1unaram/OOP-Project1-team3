/* insertion function */

#include "main_header.h"

// variable forward declarations (�ܺ� ���� ���� ���)
extern vector<Student> students;
extern string filename;

void insertion() {

	cout << "[Insert Mode]" << endl;
	cin.ignore();

	// Input Student info from user
	string name;
	cout << "Name ? ";
	getline(cin, name);

	string id;
	cout << "Studnet ID(10 digits) ? ";
	getline(cin, id);

	string birth;
	cout << "Birth Year (4 digits) ? ";
	getline(cin, birth);

	string dept;
	cout << "Department ?: ";
	getline(cin, dept);

	string tel;
	cout << "Tel ? ";
	getline(cin, tel);

	// Name Size üũ
	if (name.size() > 15) {
		cout << "Error: 'Name' should have up to 15 (English) characters..\n\n";
		return;
	}

	// Student ID Size üũ
	if (id.size() != 10) {
		cout << "Error: 'Student ID' should be exactly 10 digits..\n\n";
		return;
	}

	// Birth Year Size üũ
	if (birth.size() != 4) {
		cout << "Error: 'Birth Year' should be exactly 4 digits..\n\n";
		return;
	}

	// Tel Size üũ
	if (tel.size() > 12) {
		cout << "Error: 'Tel' should have up to 12 digits..\n\n";
		return;
	}

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

	Student newStudent(name, id, birth, dept, tel);
	students.push_back(newStudent);

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