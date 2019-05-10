#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

#define WIDTH		40
#define HEIGHT		15

//在main函数中,最开始就调用init()
void init(void) {
	//mode con cols=80 lines=40
	char cmd[128]; 
	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}

void printInMiddle(string msg) {
	int space = (WIDTH - msg.length()) /2 ;
	for (int i=0; i<space; i++) {
		cout << " ";
	}
	cout << msg << endl;
}

void menuShow(void) {
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击修复",
		"4.查看攻击记录",
		"5.退出"
	};

	system("cls");
	printInMiddle("---黑客攻击系统---");

	// 计算菜单最大长度：
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