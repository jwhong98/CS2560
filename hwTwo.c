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
------------------------------------------------------------------------------------------------------
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
------------------------------------------------------------------------------------------------------
3)
#include <stdio.h>

double sharesPurchased;
double pricePerShare;
double commissionPercentage;
double priceSold;

double pricePaid(){
	return sharesPurchased * pricePerShare;
}

double commission(){
	return pricePaid() * commissionPercentage;
}
double soldStock(){
	return sharesPurchased * priceSold;
}
double commission2(){
	return soldStock() * commissionPercentage;
}
double profit(){
	return soldStock() - (pricePaid() + commission() + commission2());
}

int main(){

	sharesPurchased = 1000;
	pricePerShare = 45.50;
	commissionPercentage = .02;
	priceSold = 56.90;

	printf("Amount Paid: $%.2f\n", pricePaid());
	printf("Commission after purchase: $%.2f\n", commission());
	printf("Amount Sold: $%.2f\n", soldStock());
	printf("Commission after selling: $%.2f\n", commission2());
	printf("Profit: $%.2f\n", profit());

	return 0;
}
------------------------------------------------------------------------------------------------------
4)
#include <stdio.h>

int main(){

	printf("Pattern A\n");
	int rows = 10;

	for(int row = 0; row < rows; row++){
		for(int column = 0; column <= row; column++){
			printf("+");
		}
		printf("\n");
	}

	printf("\n");

	printf("Pattern B\n");

	for(int i = rows; i >= 0; i--){
		for(int j = 1; j<=i; j++){
			printf("+");
		}
		printf("\n");
	}
}
	

