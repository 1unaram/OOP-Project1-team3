/* Student Class Á¤ÀÇºÎ */

#include <iostream>
#include <string>

using namespace std;

class Student {

private:
	/* member constant */
	enum {
		NAME_SIZE = 15,
		STUDENT_ID_SIZE = 10,
		BIRTH_SIZE = 4,
		DEPT_SIZE = 25,
		TEL_SIZE = 10
	};

	/* member variable */
	string name;
	string student_id;
	string birth_year;
	string department;
	string tel;

public:
	/* Constructor */
	Student();
	Student(string, string, string, string, string);

	/* Method */
	void printStudentInfo();
	void printDefault();
	void printContainer();

	// Getter
	string getName();
	string getStudentID();
	string getBirthYear();
	string getDepartment();
	string getTel();
};
