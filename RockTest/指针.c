#include<stdio.h>
#include<Windows.h>
#include<string.h>

/******************* 暗恋密语 *********************/
// 48340
void decode(int msg) {
	char *p = (char*)&msg;
	printf("%s\n", p);
}

int main1(void) {
	printf("Rock哥，代码敲完了吗？今晚 48340\n");
	decode(48340);

	system("pause");
	return 0;
}

/******************* 指针的本质 *********************/
int main2(void) {
	// demo1 int类型指针
	int girl1Age = 25;
	int girl2Age = 18;

	int *p; 
	p = &girl1Age;
	printf("girlFriend 年龄：%d\n", *p); //25
	p = &girl2Age;
	printf("girlFriend 年龄：%d\n", *p); //25

	// demo2 char类型指针
	char girl1Size = 'A';
	char girl2Size = 'B';
	
	char *p2;
	p2 = &girl1Size;
	printf("girlFriend size: %c\n", *p2);
	p2 = &girl2Size;
	printf("girlFriend size: %c\n", *p2);

	system("pause");
	return 0;
}

/******************* 二级指针 - 经典笔试题 【三星广州研究院】 *********************/
void getMemory(char *p, int size) {
	p = (char*)malloc(sizeof(char) * size);
	memset(p, 0, size);
}

int main3(void) {
	char *p = NULL;
	getMemory(p, 100);
	strcpy(p, "I love you.");
	printf("%s\n", p);

	system("pause");
	return 0;
}

/******************* 二级指针 - 实例 *********************/
char girl1Size = 'B';
char girl2Size = 'C';

void getBiggerSize(char **p) {
	char *tmp;
	if (girl1Size > girl2Size) {
		tmp = &girl1Size;
	}
	else {
		tmp = &girl2Size;
	}

	*p = tmp;
}

int main4(void) {
	char *p = NULL;
	// size是变化的
	getBiggerSize(&p);
	printf("Bigger: %c\n", *p);

	// size是变化的
	girl1Size += 2;
	printf("girl1Size: %c\n", girl1Size);
	printf("Bigger: %c\n", *p);

	getBiggerSize(&p);
	printf("Bigger: %c\n", *p);

	system("pause");
	return 0;
}

/******************* 二级指针 - 指向数组的指针 *********************/
int main(void) {
	char girlSizes[10] = { 'A',  'B',  'C',  'D',  'E',  'F', 'B',  'D',  'C', 'A'};
	char (*p)[10];
	p = &girlSizes;

	for (int i = 0; i < 10; i++) {
		printf("%c ", (*p)[i]);
	}

	char(*p2)[2];
	p2 = (char(*)[2])&girlSizes; //强制转化
	printf("\n\n%c %c\n", (*p)[0], (*p)[1]);
	p2++;
	printf("%c %c\n", (*p2)[0], (*p2)[1]);

	system("pause");
	return 0;
}
