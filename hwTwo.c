1) 
#include <stdio.h>

double mealCost;
double taxPercentage;
double tipPercentage;

double tax(){
	return mealCost * taxPercentage;
}

double tip(){
	return (mealCost + tax()) * tipPercentage;
}

double totalMeal(){
	return mealCost + tax() + tip();
}


int main(){

	mealCost = 88.67;
	taxPercentage = .0675;
	tipPercentage = .2;

	printf("Meal Cost: $%.2f\n", mealCost);
	printf("Tax: $%.2f\n", tax());
	printf("Tip: $%.2f\n", tip());
	printf("Total Bill: $%.2f\n", totalMeal());

	return 0;
}

