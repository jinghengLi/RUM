#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[ROW][COL], int row, int col) {


	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void Printboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("+");
				}
			}
			printf("\n");
		}
	}
}

void Playmove(char board[ROW][COL], int row, int col) {

	int x = 0;
	int y = 0;
	while (1) {
		printf("������壬���������꣨�� �У���");
		scanf("%d %d", &x, &y);
		if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != ' ') {
			printf("����������������룡\n");
			continue;
		}
		board[x][y] = 'X'; // ����� 'X' ����
		break;
	}

}


void Commove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row; // �������������
		y = rand() % col; // �������������
		if (board[x][y] == ' ') { // �����λ��Ϊ��
			board[x][y] = 'O'; // ������ '#' ����
			printf("�������壬����Ϊ��%d %d\n", x, y);
			break;
		}
	}

}

int IsWin(char board[ROW][COL], int row, int col) {
	// �����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= col - 5; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && 
				board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && 
				board[i][j] == board[i][j + 4]) {
				return board[i][j]; // ����һ�ʤ
			}
		}
	}
	// �����
	for (int j = 0; j < col; j++) {
		for (int i = 0; i <= row - 5; i++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && 
				board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && 
				board[i][j] == board[i + 4][j]) {
				return board[i][j]; // ����һ�ʤ
			}
		}
	}
	// ������Խ���
	for (int i = 0; i <= row - 5; i++) {
		for (int j = 0; j <= col - 5; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && 
				board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && 
				board[i][j] == board[i + 4][j + 4]) {
				return board[i][j]; // ����һ�ʤ
			}
		}
	}
	// ��鸱�Խ���
	for (int i = 0; i <= row - 5; i++) {
		for (int j = 4; j < col; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && 
				board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && 
				board[i][j] == board[i + 4][j - 4]) {
				return board[i][j]; // ����һ�ʤ
			}
		}
	}
	
	// ����Ƿ�ƽ��
	if (IsFull(board, row, col)) {
		return 'Q'; // ƽ��
	}
	return 'C'; // ��Ϸ��������
}

int IsFull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0; // ����δ��
			}
		}
	}
	return 1; // ��������
}