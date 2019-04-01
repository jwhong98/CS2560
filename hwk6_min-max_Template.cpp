#include <iostream>

template <typename T>
T max(const T & a, const T & b){
	return (a>b ? a : b);
}

template <typename T>
T min(const T & a, const T & b){
	return (a < b ? a : b);
}

int main(){
	int a = 14;
	int b = 5;

	std::cout <<"max is " << max<int>(a, b) << std::endl;
	std::cout << "min is " << min<int>(a, b) << std::endl;

	return 0;
}


