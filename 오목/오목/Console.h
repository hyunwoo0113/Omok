#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//Ŀ���� �ش� ��ġ�� �̵��ϴ� �Լ�
void GotoXY(int _x, int _y) {
	COORD pos = { _x , _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ���� x, y��ġ�� �˷��ִ� �Լ�
COORD GetXY(void) {
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO curInfor;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);

	pos.X = curInfor.dwCursorPosition.X;
	pos.Y = curInfor.dwCursorPosition.Y;

	return pos;
}

//ȭ���� ����� �Լ�
void Clear(void) {
	system("cls");
}

//Ÿ��Ʋ�� �����ϴ� �Լ�
void SetTitle(char* _szConsoleName) {
	SetConsoleTitle(_szConsoleName);
}

// ���ڻ�, ������ �����ϴ� �Լ�
void SetColor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

// Ŀ���� ���̰� �ϰų� (TRUE) ������ �ʰ� �ϴ� �Լ� (FALSE)
void SetCurcor(BOOL _bShow) {
	CONSOLE_CURSOR_INFO curInfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	curInfor.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);

}