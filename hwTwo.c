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

2)
#include <stdio.h>

int main(){

	double risingRate = 1.5;

	printf("Displaying rise of ocean levels from current levels in millimeters: \n");
	printf("In 5 years: %.2f\n", risingRate * 5);
	printf("In 7 years: %.2f\n", risingRate * 7);
	printf("In 10 years: %.2f\n", risingRate * 10);
	
	return 0;

}
	

