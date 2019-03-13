1. 
  1.	
#include <stdio.h>
#include <stdlib.h>

int chart[10][10];

void chartDisplay(int chart[10][10]){

	int columns = 0;
	printf("\n        ");

	for(int c = 0; c < 10; c++){

		columns = columns + 1;

		if(columns > 9){
			printf(" %d", columns);
		}
		else {
			printf("  %d", columns);
		}
	}

	for(int row = 0; row < 10; row++){

		printf("\n Row %d", row+1);
		printf("   ");

		if(row < 9){
			printf(" ");
		}
		for(int column = 0; column < 10; column++){
			printf("%d", chart[row][column]);
			printf("  ");
		}
	}
}

int main(){

	for(int row = 0; row < 10; row++){
			for(int column = 0; column < 10; column++){
				int i = (row + 1) * (column + 1);
				chart[row][column] = i;
			}
		}

		chartDisplay(chart);

}
----------------------------
  2. 
  #include <iostream>
#include <array>
using namespace std;

class Array{
private:
	int size;

	int min = array[0];
	int max = array[0];
public:
	float array[];
	Array(int s){
		size = s;
		array[size];
	}
	~Array();

	int storeElement(int number, int index){
		array[index] = number;
	}

	/*float getNumber(int index){
		return array[index];
	}
*/
	int getHighestValue(){
		for(int i = 1; i < size; i++){
			if(max < array[i]){
				max = array[i];
			}
		}
	}

	int getLowestValue(){
		for(int i = 1; i < size; i++){
			if(min > array[i]){
				min = array[i];
			}
		}
	}
};

int main(){

	Array array1(5);

	array1.storeElement(5, 1);
	array1.storeElement(4, 2);
	array1.storeElement(3, 3);
	array1.storeElement(2, 4);
	array1.storeElement(1, 5);

	//array1.getNumber(3);

	array1.getHighestValue();
	array1.getLowestValue();

	~Array();
	return 0;

}
