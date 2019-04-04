#include <iostream>
#include <string>

class Employee{
	std::string name;
	int number;
	std::string hireDate;

public:
	Employee(){
		std::cout << "Employee Information. ";
	}

	void setNumber(int n);
	void setName(std::string n){
		name = n;
	}
	void setHireDate(std::string date){
		hireDate = date;
	}
	std::string getName(){
		return name;
	}
	int getNumber(){
		return number;
	}
	std::string getHireDate(){
		return hireDate;
	}

	class InvalidEmployeeNumber{
		int value;
	public:
		InvalidEmployeeNumber(int val){
			value = val;
		}
		int getValue() const{
			return value;
		}
	};
};

void Employee::setNumber(int num){
	if (num > 0 && num < 9999){
		number = num;
	}else{
		throw InvalidEmployeeNumber(num);
	}
}

class ProductionWorker : public Employee {
	int shift;
	double hourlyPayRate;
public:
	ProductionWorker(){
		std::cout << "Answer the following questions: \n";
	}
	void setShift(int s);
	std::string getShift(){
		std::string shiftType;
		if(shift == 1){
			shiftType = "Day";
		}else{
			shiftType = "Night";
		}
		return shiftType;
	}
	void setPayRate(double p);
	double getPayRate(){
		return hourlyPayRate;
	}
	class InvalidShift{
			int value;
		public:
			InvalidShift(int val){
				value = val;
			}
			int getValue() const{
				return value;
			}
		};
		class InvalidPayRate{
			int value;
		public:
			InvalidPayRate(int val){
				value = val;
			}
			int getValue() const{
				return value;
			}
		};
};

void ProductionWorker::setShift(int num){
	if(num == 1 or num == 2){
		shift = num;
	}else{
		throw InvalidShift(num);
	}
}
void ProductionWorker::setPayRate(double num){
	if(num >= 0){
		hourlyPayRate = num;
	}else{
		throw InvalidPayRate(num);
	}
}

int main(){
	std::string name;
	int number;
	std::string hireDate;
	int shift;
	double hourlyPay;

	ProductionWorker p;

	std::cout << "Enter employee's name: ";
	std::cin >> name;
	std::cout << "Enter employee number: ";
	std::cin >> number;
	std::cout << "Enter date hired: ";
	std::cin >> hireDate;
	std::cout << "Enter shift (1 or 2): ";
	std::cin >> shift;
	std::cout << "Enter hourly pay rate: ";
	std::cin >> hourlyPay;

	try{
		p.setName(name);
		p.setNumber(number);
		p.setHireDate(hireDate);
		p.setShift(shift);
		p.setPayRate(hourlyPay);
		std::cout << "Name: " << p.getName() << std::endl;
		std::cout << "Number: " << p.getNumber() << std::endl;
		std::cout << "Hired: " << p.getHireDate() << std::endl;
		std::cout << "Shift: " << p.getShift() << std::endl;
		printf("Hourly Pay: $%.2f", p.getPayRate());

	}catch (Employee::InvalidEmployeeNumber p){
		std::cout << "Error: " << p.getValue() << " is an invalid employee number.";
	}
	catch (ProductionWorker::InvalidShift p){
		std::cout << "Error: " << p.getValue() << " is an invalid shift.";
	}
	catch (ProductionWorker::InvalidPayRate p){
		std::cout << "Error: " << p.getValue() << " is an invalid pay.";
	}
}
