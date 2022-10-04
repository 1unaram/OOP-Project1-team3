/* insertion function */

#include "insertion_header.h"

// variable forward declarations (�ܺ� ���� ���� ���)
extern vector<Student> students;
extern string filename;

void insertion() {

	cout << "[Insert Mode]" << endl;

	// Input Student info from user
	string name;
	cout << "Name ? ";
	cin >> name;

	string id;
	cout << "Studnet ID(10 digits) ? ";
	cin >> id;

	string birth;
	cout << "Birth Year (4 digits) ? ";
	cin >> birth;

	string dept;
	cout << "Departmen ?: ";
	cin >> dept;

	string tel;
	cout << "Tel ? ";
	cin >> tel;


	// Name Size üũ
	if (name.size() > 15) {
		cout << "'Name' should have up to 15 (English) characters..\n\n";
		return;
	}

	// Student ID Size üũ
	if (id.size() != 10) {
		cout << "'Student ID' should be exactly 10 digits..\n\n";
		return;
	}

	// Birth Year Size üũ
	if (birth.size() != 10) {
		cout << "'Birth Year' should be exactly 4 digits..\n\n";
		return;
	}

	// Tel Size üũ
	if (tel.size() != 10) {
		cout << "'Tel' should have up to 12 digits..\n\n";
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