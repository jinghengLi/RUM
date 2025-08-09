#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("***********************************\n");
	printf("*********     1.play   ************\n");
	printf("*********     0.exit     ************\n");
	printf("**********************************\n");

}

void game() {
	char board[ROW][COL];
	// ��ʼ������������
	Initboard(board, ROW, COL);
	// ��ӡ����������
	while (1) {
		int result = IsWin(board, ROW, COL);  // ���ڴ洢��Ϸ���
		Printboard(board, ROW, COL);
		// �������������
		if (result != 'C') {
			if (result == 'X') {
				printf("��һ�ʤ��\n");
				break;
			}
			else if (result == 'O') {
				printf("���Ի�ʤ��\n");
				break;
			}
			else if (result == 'Q') {
				printf("ƽ�֣�\n");
				break;
			}
			break; // ��Ϸ����
		}
		Playmove(board, ROW, COL);
		// ��ӡ����������
		Printboard(board, ROW, COL);
		//�������������
		Commove(board, ROW, COL);
	}

}



int  main() {
	int choice = 0;
	srand((unsigned int)time(NULL));  // ��ʼ�����������
	do
	{
		menu();  //��ӡ�˵�
		printf("��ѡ��>");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			game();  //������Ϸ����
			//������Ե�����Ϸ�ĺ���
			break;
		case 0:
			printf("�˳���Ϸ\n");
			return 0;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (choice);
	return 0;
}