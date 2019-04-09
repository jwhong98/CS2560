#include <iostream>
#include <vector>
#include <algorithm>

//print elements of the vector
template<typename T>

void printv(std::vector<T> & v){

	if(v.empty()) return;

	for(T &i : v) std::cout << i << " ";

	std::cout << std::endl;
}


void primeNum(std::vector <int> & v, int size){

	//bool prime = true;

	for(int i = 0; i < size; i++){
		int num = v[i];
		for(int j = 2; 2 <= num/2; j++){
			if(num%j == 0){
				//prime = false;
				v.erase(v.begin() + i);
				break;
			}
		}
	}
}

int main(){

	int num;

	std::cout << "Enter a positive integer greater than 1: ";

	std::cin >> num;

	std::vector<int> v1;

	for(int i = 2; i <= num; i++){
		v1.push_back(i);
	}

	printv(v1);

	std::cout << "Prime numbers:" << std::endl;

	primeNum(v1, v1.size());

	//std::for_each(v1.begin(), v1.end(), primeNum(v1, v1.size()));

	printv(v1);




}
