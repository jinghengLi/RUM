#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
void menu() {
	printf("***********************************************\n");
	printf("************    1.�����ϵ��     **************\n");
	printf("************    2.ɾ����ϵ��     **************\n");
	printf("************    3.������ϵ��     **************\n");
	printf("************    4.�޸���ϵ��     **************\n");
	printf("************    5.�鿴��ϵ��     **************\n");
	printf("************    6.������ϵ��     **************\n");
	printf("************    0.�˳�ͨѶ¼     **************\n");
	printf("***********************************************\n");
}



int main() {
	int input = 0;
	char name[] = { 0 };
	Contact con;     //����ͨѶ¼��������ϵ����Ϣ�ͼ�¼��
	InitContact(&con);   //��ʼ��ͨѶ¼
	do {
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			printf("�����˳�ͨѶ¼");
			break;
		default:
			printf("�����������������");
			break;
		}
	} while (input);
	return 0;
}