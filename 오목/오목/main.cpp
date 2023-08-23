#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "DRAW_BOARD.h"
#include "Event_Processing.h"

#define MAX_BOARD 15 // 보드판 크기 15X15
#define MAX_BOARD_X 14 // 보드판 최대 X값
#define MAX_BOARD_Y 14 // 보드판 최대 Y값
#define MAX_PLAYER_X 28 //플레이어 X 최대
#define MAX_PLAYER_Y 14 //플레이어 Y 최대
#define MAX_STONE 255 // 최대 돌 개수

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
		SetColor(0, 8); //0,8 검은색
		printf("◎");
		GotoXY(0, 16);
		SetColor(0, 15); //0,15 하얀색
		printf("도움말 : 흑돌 차례입니다.");
	}
	else if (TOTAL_STONE % 2 != 0) {
		SetColor(0, 15); //0,15 하얀색
		printf("◎");
		GotoXY(0, 16);
		SetColor(0, 15); //0,15 하얀색
		printf("도움말 : 백돌 차례입니다.");
	}
}

void DRAW_STONE() {
	SetColor(0, 15); //0,15 하얀색

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) {
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			if (BOARD[Y][X] == 1) {
				GotoXY(X * 2, Y);
				printf("○");
			}
			if (BOARD[Y][X] == 2) {
				GotoXY(X * 2, Y);
				printf("●");
			}
		}
	}
}

void GAME_END() {
	if (BLACK_END() >= 1) {
		GotoXY(8, 8);
		SetColor(0, 15); //0,15 하얀색
		printf("흑돌 승리");
		exit(0);
	}
	if (WHITE_END() >= 1) {
		GotoXY(8, 8);
		SetColor(0, 15); //0,15 하얀색
		printf("백돌 승리");
		exit(0);
	}
}

void GAME_INFO() {
	GotoXY(31, 3);
	SetColor(0, 15); //0,15 하얀색
	printf("선택기 : X:%d Y:%d", PLAYER.X / 2, PLAYER.Y);

	GotoXY(31, 5);
	printf("흑돌수 : %d", BLACK_STONE_STATE.total);

	GotoXY(31, 7);
	printf("백돌수 : %d", WHITE_STONE_STATE.total);

	GotoXY(31, 9);
	printf("전체수 : %d", TOTAL_STONE);
}

void Breaking_Rules() {
	GotoXY(0, 16);
	SetColor(0, 15); //0,15 하얀색
	printf("도움말 : 렌주 규칙에 어긋납니다.");
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
						BOARD[PLAYER.Y][PLAYER.X / 2] = 1; //바둑판을 흑돌로 변경
						BLACK_STONE_STATE.total++; // 흑돌 개수 올림
						TOTAL_STONE += 1;
					}
				}
				else if (TOTAL_STONE % 2 != 0) {
					BOARD[PLAYER.Y][PLAYER.X / 2] = 2; //바둑판을 백돌로 변경
					WHITE_STONE_STATE.total++; // 흑돌 개수 올림
					TOTAL_STONE += 1;
				}
				UPDATE();
			}
		}
	}
}

void RESET_DATA() {
	BLACK_STONE_STATE.Active = true; //흑돌 활성화
	WHITE_STONE_STATE.Active = true; //백돌 활성화
	TOTAL_STONE = 0; //전체돌 초기화
	Breaking_Rules_State = false; //렌주룰 상태 초기화

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //바둑판 초기화
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