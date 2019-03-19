#include <iostream>
using namespace std;

typedef int boolean;
#define true 1
#define false 0

class PatientAccount {
private:
	int daysInHospital;
	const int dailyRate = 2000;
public:
	static int charges;
	PatientAccount(int days) {
		daysInHospital = days;
	}
	int charge(PatientAccount account) {
		charges = daysInHospital * dailyRate;
		return charges;
	}
	int getCharges() {
		return charges;
	}
};

int PatientAccount::charges = 0;

class Surgery {
private:
	const int surgery1Price = 100;
	const int surgery2Price = 200;
	const int surgery3Price = 300;
	const int surgery4Price = 400;
	const int surgery5Price = 500;

public:

	int addSurgery1Price() {
		return PatientAccount::charges += surgery1Price;
	}
	int addSurgery2Price() {
		return PatientAccount::charges += surgery2Price;
	}
	int addSurgery3Price() {
		return PatientAccount::charges += surgery3Price;
	}
	int addSurgery4Price() {
		return PatientAccount::charges += surgery4Price;
	}
	int addSurgery5Price() {
		return PatientAccount::charges += surgery5Price;
	}
};

class Pharmacy {
private:
	const int med1 = 10;
	const int med2 = 20;
	const int med3 = 30;
	const int med4 = 40;
	const int med5 = 50;

public:

	int addMedication1Price() {
		return PatientAccount::charges += med1;
	}
	int addMedication2Price() {
		return PatientAccount::charges += med2;
	}
	int addMedication3Price() {
		return PatientAccount::charges += med3;
	}
	int addMedication4Price() {
		return PatientAccount::charges += med4;
	}
	int addMedication5Price() {
		return PatientAccount::charges += med5;
	}
};

void mainMenu();
void surgeryMenu();
void medicationMenu();

int main() {

	PatientAccount patient(5); //assume patient stayed for 5 days
	patient.charge(patient);

	mainMenu();

	cout << patient.getCharges();

	//std::cin.get();


}

void mainMenu() {
	int selection;
	boolean run = true;
		cout << "Choose option number: \n1. Surgery type\n2. Medication type\n3. Exit" << endl;

		cin >> selection;

		switch (selection) {
		case 1: surgeryMenu();
			break;
		case 2: medicationMenu();
			break;
		case 3: cout << "Current charges: $";
			break;
		default: cout << "Select 1, 2, or 3" << endl;
			break;
		}

}
void surgeryMenu() {

	Surgery surgery;

	int selection;
	boolean run = true;
	while (run) {
		cout << "Select surgery to add: \n1. Surgery 1\n2. Surgery 2\n3. Surgery 3\n4. Surgery 4\n5. Surgery 5\n6. Previous menu" << endl;

		cin >> selection;

		switch (selection) {
		case 1: surgery.addSurgery1Price();
			break;
		case 2: surgery.addSurgery2Price();
			break;
		case 3: surgery.addSurgery3Price();
			break;
		case 4: surgery.addSurgery4Price();
			break;
		case 5: surgery.addSurgery5Price();
			break;
		case 6: run = false;
				mainMenu();
			break;
		default: cout << "Select a valid surgery or return to previous menu." << endl;
			break;
		}
	}
}

void medicationMenu() {

	Pharmacy pharmacy;

	int selection;
	boolean run = true;
	while (run) {
		cout << "Select medication to add: \n1. Medication 1\n2. Medication 2\n3. Medication 3\n4. Meciation 4\n5. Medication 5\n6. Previous menu" << endl;

		cin >> selection;

		switch (selection) {
		case 1: pharmacy.addMedication1Price();
			break;
		case 2: pharmacy.addMedication2Price();
			break;
		case 3: pharmacy.addMedication3Price();
			break;
		case 4: pharmacy.addMedication4Price();
			break;
		case 5: pharmacy.addMedication5Price();
			break;
		case 6: run = false;
				mainMenu();
			break;
		default: cout << "Select valid medication or return to previous menu." << endl;
		}
	}
}
