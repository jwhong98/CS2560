/*
 * hwk3.c
 *
 *  Created on: Feb 19, 2019
 *      Author: jwhong
 */

#include <stdio.h>

double circleArea(){

	float radius;
	printf("Enter the radius: \n");
	fflush(stdout);
	scanf("%f", &radius);
	float pi = 3.14159;
	float area = pi * radius * radius;
	return area;
}

double rectangleArea(){
	float length;
	float width;
	printf("Enter length: \n");
	fflush(stdout);
	scanf("%f", &length);
	printf("Enter width: \n");
	fflush(stdout);
	scanf("%f", &width);
	float area = length * width;
	return area;
}

double triangleArea(){

	float length;
	float height;

	printf("Enter length: ");
	fflush(stdout);
	scanf("%f", &length);
	printf("Enter height: ");
	fflush(stdout);
	scanf("%f", &height);
	float area = length * height * .5;
	return area;

}

void endProgram(){
	printf("Exiting program.");
	exit(0);
}

int main(){

	char selection;

	printf("1. Calculate the Area of a Circle \n2. Calculate the Area of a Rectangle \n3. Calculate the Area of a Triangle \n4. Quit\nSelect from the menu: \n");
	fflush(stdout);
	selection = getchar();

	switch(selection) {
	case '1':
		printf("Area of the circle is: %.2f", circleArea());
		break;

	case '2':
		printf("Area of the rectangle is: %.2f", rectangleArea());
		break;

	case '3':
		printf("Area of the triangle is: %.2f", triangleArea());
		break;
	case '4':
		endProgram();
		break;

	default:
		printf("Please select from the menu.");

	}
}

------------------------------------------------------------------------------------------------------

#include <stdio.h>

float startingPopulation;
float birthRate;
float deathRate;
float years;

float populationSize(){
	birthRate = birthRate / 100;
	deathRate = deathRate / 100;
	float population = (startingPopulation + (birthRate * startingPopulation) - (deathRate * startingPopulation)) * years;
	return population;

}

int main(){

	printf("Enter starting population size: ");
	fflush(stdout);
	scanf("%f", &startingPopulation);

	if(startingPopulation < 2){
		printf("Population size can't be less than 2. Please enter another size: ");
		fflush(stdout);
		scanf("%f", &startingPopulation);
	}

	printf("Enter birth rate: ");
	fflush(stdout);
	scanf("%f", &birthRate);

	if(birthRate < 0){
			printf("Birth rate can't be negative. Please enter a positive birth rate: ");
			fflush(stdout);
			scanf("%f", &birthRate);
		}

	printf("Enter death rate: ");
	fflush(stdout);
	scanf("%f", &deathRate);

	if(deathRate < 0){
				printf("Death rate can't be negative. Please enter a positive death rate: ");
				fflush(stdout);
				scanf("%f", &deathRate);
			}

	printf("Number of years to display: ");
	fflush(stdout);
	scanf("%f", &years);

	if(years < 1){
			printf("Number of years must be greater than 1. Please enter another size: ");
			fflush(stdout);
			scanf("%f", &years);
		}

	printf("Population after %g year(s) is %g", years, populationSize());

}

------------------------------------------------------------------------------------------------------
