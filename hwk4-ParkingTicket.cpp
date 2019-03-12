#include <iostream>
#include <string>
using namespace std;

typedef int boolean;
#define true 1
#define false 0

class ParkedCar {
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesParked;
public:
	ParkedCar(string m, string mod, string col, string ln, int min);

	ParkedCar(ParkedCar *car2);

	string getMake() {
		return make;
	}
	string getModel() {
		return model;
	}
	string getColor() {
		return color;
	}
	string getLicenseNumber() {
		return licenseNumber;
	}
	int getMinutesParked() {
		return minutesParked;
	}
	string setMake(string m) {
		make = m;
	}
	string setModel(string mod) {
		model = mod;
	}
	string setColor(string col) {
		color = col;
	}
	string setLicenseNumber(string ln) {
		licenseNumber = ln;
	}
	int setMinutesParked(int min) {
		minutesParked = min;
	}
};

ParkedCar::ParkedCar(string m, string mod, string col, string ln, int min) {
	make = m;
	model = mod;
	color = col;
	licenseNumber = ln;
	minutesParked = min;
}

ParkedCar::ParkedCar(ParkedCar *car2) {
	this->make = car2->make;
	this->model = car2->model;
	this->color = car2->color;
	this->licenseNumber = car2->licenseNumber;
	this->minutesParked = car2->minutesParked;
}

class ParkingMeter {
private:
	int minutesPurchased;
public:
	ParkingMeter(int m) {
		minutesPurchased = m;
	}
	int getMinutesPurchased() {
		return minutesPurchased;
	}
	void setMinutesPurchased(int m) {
		minutesPurchased = m;
	}
};

class PoliceOfficer {
private:
	string name;
	int badgeNumber;

public:
	PoliceOfficer(string n, int bn) {
		name = n;
		badgeNumber = bn;
	}

	string getName() {
		return name;
	}
	int getBadgeNumber() {
		return badgeNumber;
	}
	void setName(string n) {
		name = n;
	}
	void setBadgeNumber(int bn) {
		badgeNumber = bn;
	}

	boolean patrol(int timePurchased, int timeParked) {
		if (timeParked - timePurchased > 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

class ParkingTicket {

private:
	int fine;
	int overtime;
public:
	int getFine() {
		return fine;
	}
	void setFine(int fine) {
		this->fine = fine;
	}
	void ticket(ParkedCar aCar, ParkingMeter meter, PoliceOfficer anOfficer) {
		cout << "Car's make: " << aCar.getMake() << endl;
		cout << "Car's model: " << aCar.getModel() << endl;
		cout << "Car's color: " << aCar.getColor() << endl;
		cout << "Car's license number: " << aCar.getLicenseNumber() << endl;

		overtime = ((aCar.getMinutesParked() - meter.getMinutesPurchased()) / 60) + 1;
		if (overtime <= 1) {
			setFine(25);
		}
		else {
			setFine(25 + ((overtime - 1) * 10));
			cout << "Fine: $" << getFine() << endl;
			cout << "Officer: " << anOfficer.getName() << endl;
			cout << "Badge number: " << anOfficer.getBadgeNumber() << endl;
		}
	}
};



int main() {

	boolean status;

	ParkedCar car("Lexus", "2008", "White", "147RHZM", 125);

	ParkingMeter meter(60);

	PoliceOfficer officer("Paul Blart", 4788);

	status = officer.patrol(meter.getMinutesPurchased(), car.getMinutesParked());
	if (status == true) {
		ParkingTicket *ticket = new ParkingTicket();
		ticket->ticket(car, meter, officer);
	}
	else {
		cout << "Car is legallt parked." << endl;
	}

	std::cin.get();

	return 0;
}
