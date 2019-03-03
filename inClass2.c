#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	string name;
	int idNumber;
	string department;
	string position;

public:

	Employee(string n, int id, string d, string p);

	Employee(string n, int i);

	Employee();

	string getName() {
		return name;
	}

	int getId() {
		return idNumber;
	}

	string getDepartment() {
		return department;
	}
	string getPosition() {
		return position;
	}

	void setName(string n) {
		name = n;
	}

	void setIdNumber(int id) {
		idNumber = id;
	}

	void setDepartment(string d) {
		department = d;
	}

	void setPosition(string p) {
		position = p;
	}
};

Employee::Employee(string n, int id, string d, string p) {
	name = n;
	idNumber = id;
	department = d;
	position = p;
}

Employee::Employee(string n, int id) {
	name = n;
	idNumber = id;
}

Employee::Employee() {
	name = "";
	idNumber = 0;
	department = "";
	position = "";
}

void displayData(Employee);


int main() {

	Employee Employee1("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee Employee2("Mark Jones", 39119, "IT", "Programmer");
	Employee Employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	displayData(Employee1);
	displayData(Employee2);
	displayData(Employee3);

	std::cin.get(); //for visual studio purpose

	return 0;
}

void displayData(Employee employee) {
	cout << employee.getName() << "   " << employee.getId() << "   " << employee.getDepartment() << "   " << employee.getPosition() << endl;
}
