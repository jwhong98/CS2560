Header file:

#ifndef Dice_H
#define Dice_H

class Dice {
private:
	int sides;
	int value;

public:
	Dice(int = 6);
	void roll();
	int getSides();
	int getValue();
};

#endif
--------------------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"
using namespace std;

Dice::Dice(int numSides) {
	unsigned seed = time(0);

	srand(seed);

	sides = numSides;

	roll();
}

void Dice::roll() {
	const int MIN_VALUE = 1;
	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

int Dice::getSides() {
	return sides;
}

int Dice::getValue() {
	return value;
}

int main() {
	const int diceSides = 6;

	Dice dice1(diceSides);
	Dice dice2(diceSides);

	int playerTotal = 0;
	int computerTotal = 0;

	while (true) {
		int roll;
		cout << "Roll dice? (1 for yes, else any number)";

		cin >> roll;

		if (roll != 1) {
			break;
		}
		else {
			dice1.roll();
			dice2.roll();
			computerTotal += dice1.getValue() + dice2.getValue();
			dice1.roll();
			dice2.roll();
			playerTotal += dice1.getValue() + dice2.getValue();

			cout << "Your total: " << playerTotal << endl;

			if (playerTotal > 21) {
				break;
			}
		}
	}

	cout << "Computer total: " << computerTotal << endl;
	if (playerTotal <= 21 && playerTotal > computerTotal) {
		cout << "You win!" << endl;
	}
	else if (playerTotal <= 21 && computerTotal <= 21 && playerTotal < computerTotal) {
		cout << "You lose!" << endl;
	}
	else if (playerTotal <= 21 && playerTotal == computerTotal) {
		cout << "You tie!" << endl;
	}
	else {
		cout << "Your total is over 21. You lose!" << endl;
	}

}
