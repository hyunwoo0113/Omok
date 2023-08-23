#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Console.h"

void GotoXY_Draw(int _x, int _y) {
	COORD pos = { _x * 2, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DRAW_BOARD(int MAX_BOARD) {
	GotoXY_Draw(0, 0);
	SetColor(0, 6);
	for (int i = 0; i < MAX_BOARD; i++) {
		for (int j = 0; j < MAX_BOARD; j++) {
			GotoXY_Draw(j, i);
			if (i == 0) {
				if (j == 0) {
					printf("¦£");
				}
				else if (j == MAX_BOARD - 1)
					printf("¦¤");
				else
					printf("¦¨");
			}
			else if (j == 0) {
				if (i == MAX_BOARD - 1)
					printf("¦¦");
				else
					printf("¦§");
			}
			else if (j == MAX_BOARD - 1) {
				if (i == MAX_BOARD - 1)
					printf("¦¥");
				else
					printf("¦©");
			}
			else if (i == MAX_BOARD - 1) {
				printf("¦ª");
			}
			else
				printf("¦«");
		}
		printf("\n");
	}
}