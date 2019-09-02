#include <iostream>
#include "Toy.h"

int main(void) {
	Toy toy("变形金刚", 5600, "China");
	cout << toy.getName() << ": " << toy.getPrice() 
		   << "[mode in " << toy.getOrigin() << "]"<<endl;

	cout << "打折大酬宾: 5折" << endl;
	toy.setDiscount(0.5);

	cout << toy.getName() << ": " << toy.getPrice()
	       << "[mode in " << toy.getOrigin() << "]" << endl;

	system("pause");
	return 0;
}
