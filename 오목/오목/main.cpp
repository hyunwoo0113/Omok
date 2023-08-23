#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "DRAW_BOARD.h"
#include "Event_Processing.h"

#define MAX_BOARD 15 // ������ ũ�� 15X15
#define MAX_BOARD_X 14 // ������ �ִ� X��
#define MAX_BOARD_Y 14 // ������ �ִ� Y��
#define MAX_PLAYER_X 28 //�÷��̾� X �ִ�
#define MAX_PLAYER_Y 14 //�÷��̾� Y �ִ�
#define MAX_STONE 255 // �ִ� �� ����

struct ST_OBJECT {
	int X = 0;
	int Y = 0;
	bool Active = false;
};
ST_OBJECT PLAYER;
ST_OBJECT WHITE_STONE_INFO[MAX_STONE];
ST_OBJECT BLACK_STONE_INFO[MAX_STONE];

struct ST_STONE {
	bool Active = false;
	int total = 0;
};
ST_STONE WHITE_STONE_STATE;
ST_STONE BLACK_STONE_STATE;

int TOTAL_STONE = 0;
bool Breaking_Rules_State = false;

void DRAW_PLAYER() {
	GotoXY(PLAYER.X, PLAYER.Y);
	if (TOTAL_STONE % 2 == 0) {
		SetColor(0, 8); //0,8 ������
		printf("��");
		GotoXY(0, 16);
		SetColor(0, 15); //0,15 �Ͼ��
		printf("���� : �浹 �����Դϴ�.");
	}
	else if (TOTAL_STONE % 2 != 0) {
		SetColor(0, 15); //0,15 �Ͼ��
		printf("��");
		GotoXY(0, 16);
		SetColor(0, 15); //0,15 �Ͼ��
		printf("���� : �鵹 �����Դϴ�.");
	}
}

void DRAW_STONE() {
	SetColor(0, 15); //0,15 �Ͼ��

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) {
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			if (BOARD[Y][X] == 1) {
				GotoXY(X * 2, Y);
				printf("��");
			}
			if (BOARD[Y][X] == 2) {
				GotoXY(X * 2, Y);
				printf("��");
			}
		}
	}
}

void GAME_END() {
	if (BLACK_END() >= 1) {
		GotoXY(8, 8);
		SetColor(0, 15); //0,15 �Ͼ��
		printf("�浹 �¸�");
		exit(0);
	}
	if (WHITE_END() >= 1) {
		GotoXY(8, 8);
		SetColor(0, 15); //0,15 �Ͼ��
		printf("�鵹 �¸�");
		exit(0);
	}
}

void GAME_INFO() {
	GotoXY(31, 3);
	SetColor(0, 15); //0,15 �Ͼ��
	printf("���ñ� : X:%d Y:%d", PLAYER.X / 2, PLAYER.Y);

	GotoXY(31, 5);
	printf("�浹�� : %d", BLACK_STONE_STATE.total);

	GotoXY(31, 7);
	printf("�鵹�� : %d", WHITE_STONE_STATE.total);

	GotoXY(31, 9);
	printf("��ü�� : %d", TOTAL_STONE);
}

void Breaking_Rules() {
	GotoXY(0, 16);
	SetColor(0, 15); //0,15 �Ͼ��
	printf("���� : ���� ��Ģ�� ��߳��ϴ�.");
	Breaking_Rules_State = false;
}

void UPDATE() {
	Clear();
	DRAW_BOARD(MAX_BOARD);
	DRAW_STONE();
	DRAW_PLAYER();
	GAME_INFO();
	if (Breaking_Rules_State == true) {
		Breaking_Rules();
	}
}

void INPUT_EVENT() {
	Sleep(100);
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		PLAYER.X -= 2;
		if (PLAYER.X < 0) PLAYER.X = 0;
		UPDATE();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		PLAYER.X += 2;
		if (PLAYER.X > MAX_PLAYER_X) PLAYER.X = MAX_PLAYER_X;
		UPDATE();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		PLAYER.Y -= 1;
		if (PLAYER.Y < 0) PLAYER.Y = 0;
		UPDATE();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		PLAYER.Y += 1;
		if (PLAYER.Y > MAX_PLAYER_Y) PLAYER.Y = MAX_PLAYER_Y;
		UPDATE();
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (BLACK_STONE_STATE.Active == true && WHITE_STONE_STATE.Active == true) {
			if (BOARD[PLAYER.Y][PLAYER.X / 2] == 0) {
				if (TOTAL_STONE % 2 == 0) {
					if (Renju_Rule(PLAYER.X / 2, PLAYER.Y) == true) {
						Breaking_Rules_State = true;
					}
					else {
						BOARD[PLAYER.Y][PLAYER.X / 2] = 1; //�ٵ����� �浹�� ����
						BLACK_STONE_STATE.total++; // �浹 ���� �ø�
						TOTAL_STONE += 1;
					}
				}
				else if (TOTAL_STONE % 2 != 0) {
					BOARD[PLAYER.Y][PLAYER.X / 2] = 2; //�ٵ����� �鵹�� ����
					WHITE_STONE_STATE.total++; // �浹 ���� �ø�
					TOTAL_STONE += 1;
				}
				UPDATE();
			}
		}
	}
}

void RESET_DATA() {
	BLACK_STONE_STATE.Active = true; //�浹 Ȱ��ȭ
	WHITE_STONE_STATE.Active = true; //�鵹 Ȱ��ȭ
	TOTAL_STONE = 0; //��ü�� �ʱ�ȭ
	Breaking_Rules_State = false; //���ַ� ���� �ʱ�ȭ

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //�ٵ��� �ʱ�ȭ
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			BOARD[Y][X] = 0;
		}
	}
}

int main() {
	system("mode con cols=50 lines=20");
	UPDATE();
	RESET_DATA();
	while (1)
	{
		INPUT_EVENT();
		GAME_END();
	}
}