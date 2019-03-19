#include <iostream>
#include<string>
using namespace std;

class Date{
private:
	int month;
	int day;
	int year;
	int days[12];
public:
	Date(int m, int d, int y){
		month = m;
		day = d;
		year = y;
	}
	void setDaysInMonth(){
		days[0] = 31;
		days[1] = 28;
		days[2] = 31;
		days[3] = 30;
		days[4] = 31;
		days[5] = 30;
		days[6] = 31;
		days[7] = 30;
		days[8] = 30;
		days[9] = 31;
		days[10] = 30;
		days[11] = 31;
	}
	void printDate(){
		string mon[] = {"January", "February", "March", "April", "May", "June",
				"July", "August", "September", "October", "November", "December"};
		cout << mon[month - 1] << " " << day << ", " << year << endl;
	}
	int getMonth(){
		return month;
	}
	int getDay(){
		return day;
	}
	int getYear(){
		return year;
	}
	void setMonth(int m){
		month = m;
	}
	void setDay(int d){
		day = d;
	}
	void setYear(int y){
		year = y;
	}
	Date &operator ++(){
		Date date(month, day, year);
		if(day == days[month - 1]){
			day = 1;
			month++;
			month %= 12;
			if(month == 1){
				year++;
			}
		}else{
			day++;
		}
		return date;
	}
	Date operator ++(int){
		Date date(month, day, year);
		if(day == days[month - 1]){
			day = 1;
			month++;
			month %= 12;
			if(month == 1){
				year++;
			}
		}else{
			day++;
		}
		return date;
	}
	Date &operator --(){
		Date date(month, day, year);
		day--;
		if(day == 0){
			month--;
			if(month == 0){
				month = 12;
				year--;
			}
			day = days[month - 1];
		}
		return date;
	}
	Date operator --(int){
		Date date(month, day, year);
		day--;
		if(day == 0){
			month --;
			if(month == 0){
				month = 12;
				year --;
			}
			day = days[month - 1];
		}
		return date;
	}
};

int realDate(int m, int d){
	if(d <= 0){
		return 0;
	}
	switch(m){
	case 1: if(d > 31){
			return 0;
			}else{
				return 1;
			}
		break;
	case 2: if(d > 28){
				return 0;
			}else{
				return 1;
			}
		break;
	case 3: if(d > 31){
				return 0;
			}else{
				return 1;
			}
		break;
	case 4: if(d > 30){
				return 0;
			}else{
				return 1;
			}
		break;
	case 5: if(d > 31){
			return 0;
			}else{
				return 1;
			}
		break;
	case 6: if(d > 30){
			return 0;
			}else{
				return 1;
			}
		break;
	case 7 : if(d > 31){
				return 0;
			}else{
				return 1;
			}
		break;
	case 8: if(d > 31){
				return 0;
			}else{
				return 1;
			}
		break;
	case 9: if(d > 30){
				return 0;
			}else{
				return 1;
			}
		break;
	case 10: if(d > 31){
				return 0;
			}else{
				return 1;
			}
		break;
	case 11: if(d > 30){
				return 0;
			}else{
				return 1;
			}
		break;
		case 12: if(d > 2831){
					return 0;
				}else{
					return 1;
				}
		break;
		default: return 0;
		break;
	}
}
int main(){
	int month;
	int day;
	int year;

	cout << "Enter month: ";
	cin >> month;
	cout << "\nEnter day: ";
	cin >> day;
	cout << "\nEnter year: ";
	cin >> year;
	cout << endl;

	int real = realDate(month, day);

	if(real == 0){
		cout << "Invalid date";
	}else{
		Date date(month, day, year);
		date.setDaysInMonth();
		cout << "Current Date: ";
		date.printDate();
		cout << endl;
		cout << "Prefix incremented date: ";
		++date;
		date.printDate();
		cout << endl;
		cout << "Postfix incremented date: ";
		date++;
		date.printDate();
		cout << endl;
		cout << "Prefix decremented date: ";
		--date;
		date.printDate();
		cout << endl;
		cout << "Postfix decremented date: ";
		date--;
		date.printDate();
	}
}


