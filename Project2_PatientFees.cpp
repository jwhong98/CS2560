#include <iostream>
using namespace std;

class PatientAccount{
private:
	int daysInHospital;
	const int dailyRate = 0;
public:
	int charges = 0;
	PatientAccount(int days){
		daysInHospital = days;
	}
	int charge(PatientAccount account){
		charges = daysInHospital * dailyRate;
		return charges;
	}
};

class Surgery{
private:
	const int surgery1Price = 100;
	const int surgery2Price = 200;
	const int surgery3Price = 300;
	const int surgery4Price = 400;
	const int surgery5Price = 500;

public:
	int getSurgery1Price(){
		return surgery1Price;
	}
	int getSurgery2Price(){
			return surgery2Price;
		}
	int getSurgery3Price(){
			return surgery3Price;
		}
	int getSurgery4Price(){
			return surgery4Price;
		}
	int getSurgery5Price(){
			return surgery5Price;
		}
};

class Pharmacy{
private:
	const int med1 = 10;
	const int med2 = 20;
	const int med3 = 30;
	const int med4 = 40;
	const int med5 = 50;

public:
	int getmedication1Price(){
		return med1;
	}
	int getmedication2Price(){
			return med2;
		}
	int getmedication3Price(){
			return med3;
		}
	int getmedication4Price(){
			return med4;
		}
	int getmedication5Price(){
			return med5;
		}
};

int main(){

	return 0;
}
