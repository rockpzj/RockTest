#include <iostream>
#include <Windows.h>

using namespace std;

void scorePrint(int score[], int n) {
	for (int i=0; i<n; i++) {
		cout << "��" << i+1 << "�ųɼ� : " << score[i] << endl;
	}
}

//ÿ���ɼ���5��
void scoreAdd(int score[], int n, int val) {
	for (int i=0; i<n; i++) {
		score[i] += val;
	}
}

int main(void) {
	int score[3] = {60, 70, 80};

	scorePrint(score, 3);
	scoreAdd(score, 3, 5);
	scorePrint(score, 3);

	system("pause");
	return 0;
}