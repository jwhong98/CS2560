#include <iostream>
#include <string>
using namespace std;

class ParkedCar {
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesParked;

public:
	ParkedCar(string mk, string mod, string col, string lic, int min) {
		make = mk;
		model = mod;
		color = col;
		licenseNumber = lic;
		minutesParked = min;
	}

	ParkedCar(ParkedCar car2) {
		make = car2.make;
		model = car2.model;
		color = car2.color;
		licenseNumber = car2.licenseNumber;
		minutesParked = car2.minutesParked;
	}

	void setMinutesParked(int min) {
		minutesParked = min;
	}

	int getMinutesParked() {
		return minutesParked;
	}

	/*string toString() {
		
	}*/
};

class ParkingMeter {
private:
	int minutesPurchased;

public:
	ParkingMeter(int m) {
		minutesPurchased = m;
	}

	void setMinutesPurchased(int m) {
		minutesPurchased = m;
	}

	int getMinutesPurchased() {
		return minutesPurchased;
	}
};

class ParkingTicket {
private:
	ParkedCar car;
	PoliceOfficer officer;
	double fine;
	int minutes;
	double baseFine = 25.00;
	double hourlyFine = 10.00;

public:
	ParkingTicket(ParkedCar aCar, PoliceOfficer anOfficer, int min) {
		car = aCar;
		officer = anOfficer;
		minutes = min;
		calculateFine();
	}

	ParkingTicket(ParkingTicket ticket2) {
		car = ticket2.car;
		officer = ticket2.officer;
		minutes = ticket2.minutes;
	}

	void calculateFine() {
		double hours = minutes / 60.0;
		int hoursAsInt = (int)hours;

		if ((hours - hoursAsInt) > 0) {
			hoursAsInt++;
		}
		fine = baseFine;
		fine += (hoursAsInt + hourlyFine);
	}

	void setFine(double f) {
		fine = f;
	}

	double getFine() {
		return fine;
	}

	ParkedCar getCar() {
		return car;
	}

	PoliceOfficer getOfficer() {
		return officer;
	}

	int getMinutes() {
		return minutes;
	}
};

	class PoliceOfficer {
	private:
		string name;
		string badgeNumber;

	public:
		PoliceOfficer(string n, string bn) {
			name = n;
			badgeNumber = bn;
		}

		ParkingTicket patrol(ParkedCar car, ParkingMeter meter) {
			ParkingTicket ticket = null;
			int illegalMinutes = car.getMinutesParked() - meter.getMinutesPurchased();

			if (illegalMinutes > 0) {
				ticket = new ParkingTicket(car, this, illegalMinutes);
			}
			return ticket;
		}
};

int main() {

	ParkedCar = new ParkedCar
}
