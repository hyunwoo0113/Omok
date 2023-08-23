#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BOARD_X 14 // 보드판 최대 X값
#define MAX_BOARD_Y 14 // 보드판 최대 Y값
#define MAX_BOARD 15 // 보드판 크기 15X15
#define MAX_STONE 255 // 최대 돌 개수

int BOARD[MAX_BOARD][MAX_BOARD] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int _3X3(int X, int Y) {
	int Count = 0;
	if (BOARD[Y][X + 1] == 1) { //보드 가로 오른쪽이 흑돌이라면
		if (BOARD[Y][X + 2] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //보드 가로 왼쪽이 흑돌이라면
			if (BOARD[Y][X - 2] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //보드 세로 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //보드 세로 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (BOARD[Y + 1][X - 1] == 1) { //보드 오른쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X - 2] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //보드 오른쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X + 2] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //보드 왼쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X + 2] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //보드 왼쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X - 2] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (Count >= 2) {
		return true;
	}
	else {
		return false;
	}
}

int _3X2(int X, int Y) { // 흑 흑X흑 흑 대각선
	int Count = 0;
	if (BOARD[Y + 1][X - 1] == 1) { //보드 오른쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 3][X - 3] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //보드 오른쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 3][X + 3] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //보드 왼쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 3][X + 3] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //보드 왼쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 3][X - 3] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (Count >= 1) {
		return true;
	}
	else {
		return false;
	}
}

int _3Xplus(int X, int Y) {
	int Count = 0;
	if (BOARD[Y][X + 1] == 1) {
		if (BOARD[Y][X - 1] == 1) {
			if (BOARD[Y - 1][X] == 1) {
				if (BOARD[Y + 1][X] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (Count >= 1) {
		return true;
	}
	else {
		return false;
	}
}

int _3Xplus_(int X, int Y) { 
	int Count = 0;

	//	   흑
	// 흑  X흑
	//     흑
	if (BOARD[Y][X + 1] == 1) { //보드 가로 오른쪽이 흑돌이라면
		if (BOARD[Y - 1][X] == 1) {
			if (BOARD[Y + 1][X] == 1) {
				if (BOARD[Y][X - 2] == 1) {
					Count += 1;
				}
			}
		}
	}
	else {
		//	  흑
		//  흑X  흑
		//    흑
		if (BOARD[Y][X - 1] == 1) { //보드 가로 왼쪽이 흑돌이라면
			if (BOARD[Y - 1][X] == 1) {
				if (BOARD[Y + 1][X] == 1) {
					if (BOARD[Y][X + 2] == 1) {
						Count += 1;
					}
				}
			}
		}
	}

	//	   흑
	//
	//   흑X흑
	//	   흑
	if (BOARD[Y + 1][X] == 1) { //보드 세로 아래쪽이 흑돌이라면
		if (BOARD[Y][X + 1] == 1) {
			if (BOARD[Y][X - 1] == 1) {
				if (BOARD[Y - 2][X] == 1) {
					Count += 1;
				}
			}
		}
	}
	else {
		//	  흑
		//  흑X흑
		//    
		//    흑
		if (BOARD[Y - 1][X] == 1) { //보드 세로 위쪽이 흑돌이라면
			if (BOARD[Y][X + 1] == 1) {
				if (BOARD[Y][X - 1] == 1) {
					if (BOARD[Y + 2][X] == 1) {
						Count += 1;
					}
				}
			}
		}
	}

	if (Count >= 1) {
		return true;
	}
	else {
		return false;
	}
}

int _4X4(int X, int Y) {
	int Count = 0;
	if (BOARD[Y][X + 1] == 1) { //보드 가로 오른쪽이 흑돌이라면
		if (BOARD[Y][X + 2] == 1) {
			if (BOARD[Y][X + 3] == 1) {
				Count += 1; //카운트
			}
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //보드 가로 왼쪽이 흑돌이라면
			if (BOARD[Y][X - 2] == 1) {
				if (BOARD[Y][X - 3] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //보드 세로 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X] == 1) {
			if (BOARD[Y + 3][X] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //보드 세로 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X] == 1) {
				if (BOARD[Y - 3][X] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X - 1] == 1) { //보드 오른쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X - 2] == 1) {
			if (BOARD[Y + 3][X - 3] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //보드 오른쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X + 2] == 1) {
				if (BOARD[Y - 3][X + 3] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //보드 왼쪽 대각선 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X + 2] == 1) {
			if (BOARD[Y + 3][X + 3] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //보드 왼쪽 대각선 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X - 2] == 1) {
				if (BOARD[Y - 3][X - 3] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (Count >= 2) {
		return true;
	}
	else {
		return false;
	}
}

int _4X2(int X, int Y) { // 흑 흑X흑 흑
	int Count = 0;
	if (BOARD[Y][X + 1] == 1) { //보드 가로 오른쪽이 흑돌이라면
		if (BOARD[Y][X + 2] != 1 && BOARD[Y][X + 3] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //보드 가로 왼쪽이 흑돌이라면
			if (BOARD[Y][X - 2] != 1 && BOARD[Y][X - 3] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //보드 세로 아래쪽이 흑돌이라면
		if (BOARD[Y + 2][X] != 1 && BOARD[Y + 3][X] == 1) {
			Count += 1; //카운트
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //보드 세로 위쪽이 흑돌이라면
			if (BOARD[Y - 2][X] != 1 && BOARD[Y - 3][X] == 1) {
				Count += 1; //카운트
			}
		}
	}

	if (Count >= 1) {
		return true;
	}
	else {
		return false;
	}
}

int Renju_Rule(int X, int Y) { //http://omok.mgame.com/help/rule.htm
	// A. 3,3 금수 완료
	if (_3X3(X, Y) == true || _3X2(X, Y) == true || _3Xplus(X, Y) == true || _3Xplus_(X, Y) == true) {
		return true;
	}
	// B. 4,4 금수 완료
	if (_4X4(X, Y) == true || _4X2(X, Y) == true) {
		return true;
	}
	// C. 6,6 금수 완료
	// D. 3,3,4 금수 완료
	// E. 3,4,4 금수 완료
	else {
		return false;
	}
}

int BLACK_END() {
	int Temp_Count = 0, Count = 0;

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //가로
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y][X + temp] == 1) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //세로
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X] == 1) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //왼쪽 대각선
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X - temp] == 1) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //오른쪽 대각선
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X + temp] == 1) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	return Count;
}

int WHITE_END() {
	int Temp_Count = 0, Count = 0;

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //가로
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y][X + temp] == 2) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //세로
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X] == 2) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //왼쪽 대각선
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X - temp] == 2) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //오른쪽 대각선
		for (int X = 0; X <= MAX_BOARD_X; X++) {
			for (int temp = 0; temp <= 4; temp++) {
				if (BOARD[Y + temp][X + temp] == 2) {
					Temp_Count += 1;
					if (Temp_Count == 5) {
						Count += 1;
						break;
					}
				}
				else {
					Temp_Count = 0;
					break;
				}
			}
		}
	}

	return Count;
}