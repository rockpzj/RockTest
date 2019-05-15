#include <iostream>
#include <Windows.h>

void pyramid(int  n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1-i; j++) {
			std::cout << " ";
		}
		for (int j=0; j<2*i+1; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int averageSalary(int data[], int n) {
	return 0;
}

int fib(int n) {
	if (n < 1) {
		std::cout << "非常参数." << std::endl;
		return -1;
	}

	if (n == 1 || n==2) {
		return 1;
	}

	int a1 = 1;
	int a2 = 1;
	int tmp; 
	for (int i=3; i<=n; i++) {
		tmp = a1 + a2;
		a1 = a2;
		a2 = tmp;
	}

	return a2;
}