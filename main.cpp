/* main.cpp */

#include "main_header.h"

// Global variable
vector<Student> students;
string filename;

int main(int argc, char ** argv) {

	filename = argv[1];

	fileRead();

	printMenu();
}

void printMenu() {

	cout << "\n\n<< Student Information Management System - Team#3 >>\n\n";

	while (true) {

		int menu;

		cout << "[Main Menu]" << endl;
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
			search();
			break;
		case 3:
			sortingOption();
			break;
		case 4:
			cout << "** Exit the program **" << endl;
			exit(0);
		}
	}
}

// txt 파일을 읽어 studnets 벡터에 push
void fileRead() {
	
	fstream file;
	file.open(filename, ios::in | ios::app);

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
			Student newStudent(name, id, birth, dept, tel);

			// End of file
			string end(name);
			if (end.size() == 0) break;

			students.push_back(newStudent);
		}
		
		file.close();
	}
	// Fail to open file
	else {
		cout << "Fail to open file.." << endl;
		exit(0);
	}
}

