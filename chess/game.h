#pragma once
#include <stdio.h>
#define ROW 10
#define COL 10

// ��ʼ������������
void Initboard(char board[ROW ][COL ], int row, int col);
// ��ӡ����������
void Printboard(char board[ROW][COL], int row, int col);
// �������������
void Playmove(char board[ROW][COL], int row, int col);
// �������������
void Commove(char board[ROW][COL], int row, int col);
//�������ж���Ӯ
int IsWin(char board[ROW][COL], int row, int col);
// �������ж�ƽ��
int IsFull(char board[ROW][COL], int row, int col);