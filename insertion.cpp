/* insertion function */

#include "main_header.h"

// variable forward declarations (외부 전역 변수 사용)
extern vector<Student> _students;
extern string _filename;

void insertion() {

	cin.ignore();

	while (true) {

		cout << "[Insert Mode]" << endl;
		
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

		// Name Size 체크
		if (name.size() > 15) {
			cout << "\nError: 'Name' should have up to 15 (English) characters..\n\n";
			continue;
		}

		// Student ID Size 체크
		if (id.size() != 10) {
			cout << "\nError: 'Student ID' should be exactly 10 digits..\n\n";
			continue;
		}

		// Birth Year Size 체크
		if (birth.size() != 4) {
			cout << "\nError: 'Birth Year' should be exactly 4 digits..\n\n";
			continue;
		}

		// Tel Size 체크
		if (tel.size() > 12) {
			cout << "\nError: 'Tel' should have up to 12 digits..\n\n";
			continue;
		}

		// 공백 체크
		if (name.size() == 0 || id.size() == 0) {
			cout << "\nError: Name and Student ID should not be blank..\n\n";
			continue;
		}
		// Student ID 중복 체크
		if (!checkStudentID(id)) {
			cout << "\nError: Already inserted..\n\n";
			continue;
		}

		Student newStudent(name, id, birth, dept, tel);
		_students.push_back(newStudent);

		string studentInfoStr = name + "," + id + "," + birth + "," + dept + "," + tel + "\n";
		ofstream writeFile;
		writeFile.open(_filename, ios::in | ios::app);

		if (writeFile.is_open()) {
			writeFile.write(studentInfoStr.c_str(), studentInfoStr.size());
			writeFile.close();
			cout << "** Success to insert! **\n\n";
		}
		else {
			cout << "Error: Fail to open file..\n\n";
		}
		return;
	}
}

bool checkStudentID(string id) {
	// Input으로 들어온 Student ID가 기존 시스템에 존재하는지 체크
	// true: 시스템에 존재하지 않음 & false: 시스템에 존재함

	for (Student s : _students) {
		if (!id.compare(s.getStudentID())) {
			return false;
		}
	}

	return true;
}