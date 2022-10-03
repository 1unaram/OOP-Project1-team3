/*
	학생 정보를 담고 있는 txt 파일 형식은 아래와 같음.

	name,student_id,birth,dept,tel\n
*/

#include "main_header.h"

// Global variable
vector<Student> students;
string filename;

int main(int argc, char ** argv) {

	filename = argv[1];

	fileOpen();

	printMenu();
}

void printMenu() {

	int menu;

	while (true) {
		cout << "1. Insertion" << endl;
		cout << "2. Search" << endl;
		cout << "3. Sorting Option" << endl;
		cout << "4. Exit" << endl;
		cout << ">  ";

		cin >> menu;
		cout << endl;

		switch (menu) {
		case 1:
			insertion();
			break;
		case 2:
			//search();
			break;
		case 3:
			//sortingOption();
			break;
		case 4:
			cout << "** Exit the program **" << endl;
			exit(0);
		}
	}
}

void fileOpen() {
	
	ifstream file;
	file.open(filename);

	// Success to open file
	if (file.is_open()) {

		while (!file.eof()) {

			// Read Student Info
			char name[256];
			file.getline(name, 256, ',');

			char id[256];
			file.getline(id, 256, ',');

			char birth[256];
			file.getline(birth, 256, ',');

			char dept[256];
			file.getline(dept, 256, ',');

			char tel[256];
			file.getline(tel, 256);

			// Push Student object
			Student s(name, id, birth, dept, tel);
			students.push_back(s);
		}
		
		file.close();
	}
	// Fail to open file
	else {
		cout << "Fail to open file.." << endl;
		exit(0);
	}
}

