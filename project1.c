#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void seatDisplay(char seats[15][30]){

	int columns = 0;
	printf("\n        ");

	for(int column = 0; column < 30; column++){

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

int main(int argc, char *argv[]){

	//char type;
	int tickets;
	int selectRow;
	int selectColumn;
	double price;
	char seats[15][30];

	for(int row = 0; row < 15; row++){
		for(int column = 0; column < 30; column++){
			seats[row][column] = '#';
		}
	}

	seatDisplay(seats);

	printf("\nHow many tickets would you like to purchase? ");
	fflush(stdout);
	scanf("%d", &tickets);

	for (int j = 0; j < tickets; j++){
		price = price + 10.00;

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
				break;
			}
			else{
				printf("Seats are not available. Please select another seat.");
			}
		}
	}

	seatDisplay(seats);

	printf("\n\nTotal Price: $%f", price);

	return 0;

}
