
void attack404(void) {
	char response[MAXSIZE] ;
	char id[64];

	memset(response, 0, sizeof(response));

	system("cls");
	printInMiddle("---网站404攻击---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));
	cout << "正在执行404攻击..." << endl;

	hk_404(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	system("pause");
}

void siteEdit(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---网站篡改攻击---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));
	cout <<   "请输入嵌入的内容：";
	cin >> attackText;

	GBKToUTF8(attackText);

	hk_tamper(id,  (char*)(attackText.c_str()), response);

	
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void siteRepair(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---网站攻击修复---");
	cout <<   "请输入准备查询的网站ID：";
	scanf_s("%s", id, sizeof(id));

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attckRecord(void) {
	char response[MAXSIZE] ;
	char id[64];

	system("cls");
	printInMiddle("---攻击记录获取---");
	cout <<   "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));

	hk_record(id, response);
	
	string retStr = UTF8ToGBK(response);

	cout << retStr;
	system("pause");
}

void input_pwd(char pwd[], int max_len) {
	char c;
	int i = 0;
		
	while (1) {
		c = getch();
        // getch不从输入缓冲区中读取
		//在getch中，把回车按键输入，识别为回车符'\r'
        //在getchar中，把回车按键输入，识别为换行符'\n'
		if (c == '\r' || i >= max_len) {  
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		printf("*", c);
	}
	printf("\n");
}