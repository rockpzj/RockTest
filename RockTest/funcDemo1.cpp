#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void login(void) {
	string name;
	string pwd;
	
	while (1) {
		system("cls");

		std::cout << "ÇëÊäÈëÕËºÅ£º";
		std::cin >> name;

		std::cout << "ÇëÊäÈëÃÜÂë£º";
		std::cin >> pwd;

		if (name == "54hk" && pwd == "123456") {
			//break;
			return;
		} else {
                   cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó!" << endl;
			system("pause");
		}
	}
}

void menuShow(void) {
	system("cls");
	std::cout << "1.ÍøÕ¾404¹¥»÷" << std::endl;
	std::cout << "2.ÍøÕ¾´Û¸Ä¹¥»÷" << std::endl;
	std::cout << "3.ÍøÕ¾¹¥»÷ÐÞ¸´" << std::endl;
	std::cout << "4.²é¿´¹¥»÷¼ÇÂ¼" << std::endl;
	std::cout << "5.ÍË³ö" << std::endl;
}

int menuChoise(void) {
	int n = 0;

	while (1) {
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "ÎÞÐ§ÊäÈë. ÇëÖØÐÂÊäÈë." << endl;
			system("pause");
		} else {
			break;
		}
	}

	return n;
}

void attack404(void) {
	system("cls");
	cout << "404¹¥»÷..."; 
	system("pause");
}

void siteEdit(void) {
	system("cls");
	cout << "ÍøÕ¾´Û¸Ä¹¥»÷..."; 
	system("pause");
}

void siteRepair(void) {
	system("cls");
	cout << "ÍøÕ¾ÐÞ¸´..."; 
	system("pause");
}

void attckRecord(void) {
	system("cls");
	cout << "²é¿´¹¥»÷¼ÇÂ¼"; 
	system("pause");
}

int main(void) {
	// µÇÂ¼
	login();

	while (1) {
		menuShow();
		int n = menuChoise();
		switch (n) {
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			siteRepair();
			break;
		case 4:
			attckRecord();
			break;
		case 5:
			//break;
			return 0;
		default:
			cout << "ÎÞÐ§ÊäÈë. ÇëÖØÐÂÊäÈë." << endl;
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}