#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void login(void) {
	string name;
	string pwd;
	
	while (1) {
		system("cls");

		std::cout << "�������˺ţ�";
		std::cin >> name;

		std::cout << "���������룺";
		std::cin >> pwd;

		if (name == "54hk" && pwd == "123456") {
			//break;
			return;
		} else {
                   cout << "�û������������!" << endl;
			system("pause");
		}
	}
}

void menuShow(void) {
	system("cls");
	std::cout << "1.��վ404����" << std::endl;
	std::cout << "2.��վ�۸Ĺ���" << std::endl;
	std::cout << "3.��վ�����޸�" << std::endl;
	std::cout << "4.�鿴������¼" << std::endl;
	std::cout << "5.�˳�" << std::endl;
}

int menuChoise(void) {
	int n = 0;

	while (1) {
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "��Ч����. ����������." << endl;
			system("pause");
		} else {
			break;
		}
	}

	return n;
}

void attack404(void) {
	system("cls");
	cout << "404����..."; 
	system("pause");
}

void siteEdit(void) {
	system("cls");
	cout << "��վ�۸Ĺ���..."; 
	system("pause");
}

void siteRepair(void) {
	system("cls");
	cout << "��վ�޸�..."; 
	system("pause");
}

void attckRecord(void) {
	system("cls");
	cout << "�鿴������¼"; 
	system("pause");
}

int main(void) {
	// ��¼
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
			cout << "��Ч����. ����������." << endl;
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}