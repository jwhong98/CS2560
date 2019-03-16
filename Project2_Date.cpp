#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	string month;
	int mont;
	int day;
	int year;

public:
	Date(int m, int d, int y) {
		mont = m;
		day = d;
		year = y;
	}
	Date(string m, int d, int y) {
		month = m;
		day = d;
		year = y;
	}
	Date(int d, string m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void printNumerical() {
		if (mont > 12 or day > 31) {
			cout << "Invalid date." << endl;
		}
		else {
			cout << mont << "/" << day << "/" << year << endl;
		}
	}
	void printMonthFirst() {
		if (day > 31) {
			cout << "Invalid date." << endl;
		}
		else {
			cout << month << day << ", " << year << endl;
		}
	}
	void printDayFirst() {
		if (day > 31) {
			cout << "Invalid date." << endl;
		}
		else {
			cout << day << month << year << endl;
		}
	}
	void incrementDayPre(Date date) {
		++day;
	}
	void incrementDayPost(Date date) {
		day++;
	}
	void decrementDayPre(Date date) {
		--day;
	}
	void decrementDayPost(Date date) {
		day--;
	}
	int subtractDate(Date date, Date date1) {
		if (date.getDay() < date1.getDay()) {
			cout << "Input larger date first" << endl;
		}
		else {
			day = date.getDay() - date1.getDay();
			return day;
		}
	}
	int getDay() {
		return day;
	}
	void displayDate(Date date) {
		cout << month << " " << day << ", " << year << endl;
	}

};

int main() {

	Date date1(12, 25, 2014);
	Date date2("December", 25, 2014);
	Date date3(25, "December", 2014);

	date1.printNumerical();
	date2.printMonthFirst();
	date3.printDayFirst();


	std::cin.get();
		return 0;
}
