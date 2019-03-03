#include <iostream>
#include String
using namespace std;

class Employee{
private:
	String name;
	int idNumber;
	String department;
	String position;
	
public:
	Employee(String n, int id, String d, String p){
		name = n;
		idNumber = id;
		department = d;
		position = p;
	}
	Employee(String n, int i){
		name = n;
		idNumber = i;
		department = "";
		position = "";
	}
	Employee(){
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}
	

}

int main(){
	
	Employee Employee1(Susan Meyers, 47899, Accounting, Vice President);
	Employee Employee2(Mark Jones, 39119, IT, Programmer);
	Employee EMployee3(Joy Rogers, 81774, Manufacturing, Engineer);
}
