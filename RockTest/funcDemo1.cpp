#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

#define WIDTH		40
#define HEIGHT		15

void printInMiddle(string msg) {
	int space = (WIDTH - msg.length()) /2 ;
	for (int i=0; i<space; i++) {
		cout << " ";
	}
	cout << msg << endl;
}

void menuShow(void) {
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ�����޸�",
		"4.�鿴������¼",
		"5.�˳�"
	};

	system("cls");
	printInMiddle("---�ڿ͹���ϵͳ---");

	// ����˵���󳤶ȣ�
	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);
	for (int i=0; i< menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	int leftSpace = (WIDTH - max) / 2;

	for (int i=0; i<menuCount; i++) {
		for (int i=0; i<leftSpace; i++){
			printf(" ");
		}
		cout << menu[i] << endl;
	}
}