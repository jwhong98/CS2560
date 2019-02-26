#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

int tickets;
int selectRow;
int selectColumn;
float price[15];
char seats[15][30];
float totalPrice = 0;

//display available/taken seats
void seatDisplay(char seats[15][30]){

	int columns = 0;
	printf("\n        ");

	for(int c = 0; c < 30; c++){

		columns = columns + 1;

		if(columns > 9){
			printf(" %d", columns);
		}
		else {
			printf("  %d", columns);
		}
	}

	for(int row = 0; row < 15; row++){

		printf("\n Row %d", row+1);
		printf("   ");

		if(row < 9){
			printf(" ");
		}
		for(int column = 0; column < 30; column++){
			printf("%c", seats[row][column]);
			printf("  ");
		}
	}
}

bool availableSeat(int row, int column, char seatMap[15][30]){
	if((row <= 15) && (column <=30) && (seatMap[row][column] == '#')){
		return true;
	}
	else{
		return false;
	}
}

void buyTickets(){

	printf("\nHow many tickets would you like to purchase? ");
			fflush(stdout);
			scanf("%d", &tickets);

			for (int j = 0; j < tickets; j++){

				while(true){
					printf("\n\nSelect row: ");
					fflush(stdout);
					scanf("%d", &selectRow);
					selectRow = selectRow - 1;
					printf("\nSelect Column: ");
					fflush(stdout);
					scanf("%d", &selectColumn);
					selectColumn = selectColumn - 1;

					if(availableSeat(selectRow, selectColumn, seats) == true){
						seats[selectRow][selectColumn] = '*';
						totalPrice = totalPrice + price[selectRow + 1];
						break;
					}
					else{
						printf("Seats are not available. Please select another seat.");
					}
				}
			}

			seatDisplay(seats);

			printf("\n\nTotal Price: $%.2f\n", totalPrice);

}

void endProgram(){
	printf("Exiting program.");
	exit(0);
}

int main(){

	printf("Enter price of each row: \n");
	for(int r = 1; r <= 15; r++){
		printf("Row %d: ", r);
		fflush(stdout);
		scanf("%f", &price[r]);
	}

	//set all seats to available
	for(int row = 0; row < 15; row++){
		for(int column = 0; column < 30; column++){
			seats[row][column] = '#';
		}
	}

	seatDisplay(seats);

	buyTickets();

	char selection;

	while(true){
		printf("\n1. Purchase tickets \n2. Check total price \n3. Show theater seats \n4. Exit program\nWhat would you like to do?\n");
		fflush(stdout);
		scanf(" %c", &selection);

		switch(selection){
			case '1':
				buyTickets();
				break;

			case '2':
				printf("Total price: $%.2f\nS", totalPrice);
				break;

			case '3':
				seatDisplay(seats);
				break;

			case '4':
				endProgram();
				break;

			default:
				printf("\nPlease select from the menu.");
		}

	}


}


