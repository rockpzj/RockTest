
void attack404(void) {
	char response[MAXSIZE] ;
	char id[64];

	memset(response, 0, sizeof(response));

	system("cls");
	printInMiddle("---��վ404����---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout << "����ִ��404����..." << endl;

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
	printInMiddle("---��վ�۸Ĺ���---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout <<   "������Ƕ������ݣ�";
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
	printInMiddle("---��վ�����޸�---");
	cout <<   "������׼����ѯ����վID��";
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
	printInMiddle("---������¼��ȡ---");
	cout <<   "������׼����������վID��";
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
        // getch�������뻺�����ж�ȡ
		//��getch�У��ѻس��������룬ʶ��Ϊ�س���'\r'
        //��getchar�У��ѻس��������룬ʶ��Ϊ���з�'\n'
		if (c == '\r' || i >= max_len) {  
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		printf("*", c);
	}
	printf("\n");
}