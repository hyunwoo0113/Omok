#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BOARD_X 14 // ������ �ִ� X��
#define MAX_BOARD_Y 14 // ������ �ִ� Y��
#define MAX_BOARD 15 // ������ ũ�� 15X15
#define MAX_STONE 255 // �ִ� �� ����

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
	if (BOARD[Y][X + 1] == 1) { //���� ���� �������� �浹�̶��
		if (BOARD[Y][X + 2] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y][X - 2] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //���� ���� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y - 2][X] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}

	if (BOARD[Y + 1][X - 1] == 1) { //���� ������ �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X - 2] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //���� ������ �밢�� ������ �浹�̶��
			if (BOARD[Y - 2][X + 2] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //���� ���� �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X + 2] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //���� ���� �밢�� ������ �浹�̶��
			if (BOARD[Y - 2][X - 2] == 1) {
				Count += 1; //ī��Ʈ
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

int _3X2(int X, int Y) { // �� ��X�� �� �밢��
	int Count = 0;
	if (BOARD[Y + 1][X - 1] == 1) { //���� ������ �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 3][X - 3] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //���� ������ �밢�� ������ �浹�̶��
			if (BOARD[Y - 3][X + 3] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //���� ���� �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 3][X + 3] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //���� ���� �밢�� ������ �浹�̶��
			if (BOARD[Y - 3][X - 3] == 1) {
				Count += 1; //ī��Ʈ
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

	//	   ��
	// ��  X��
	//     ��
	if (BOARD[Y][X + 1] == 1) { //���� ���� �������� �浹�̶��
		if (BOARD[Y - 1][X] == 1) {
			if (BOARD[Y + 1][X] == 1) {
				if (BOARD[Y][X - 2] == 1) {
					Count += 1;
				}
			}
		}
	}
	else {
		//	  ��
		//  ��X  ��
		//    ��
		if (BOARD[Y][X - 1] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y - 1][X] == 1) {
				if (BOARD[Y + 1][X] == 1) {
					if (BOARD[Y][X + 2] == 1) {
						Count += 1;
					}
				}
			}
		}
	}

	//	   ��
	//
	//   ��X��
	//	   ��
	if (BOARD[Y + 1][X] == 1) { //���� ���� �Ʒ����� �浹�̶��
		if (BOARD[Y][X + 1] == 1) {
			if (BOARD[Y][X - 1] == 1) {
				if (BOARD[Y - 2][X] == 1) {
					Count += 1;
				}
			}
		}
	}
	else {
		//	  ��
		//  ��X��
		//    
		//    ��
		if (BOARD[Y - 1][X] == 1) { //���� ���� ������ �浹�̶��
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
	if (BOARD[Y][X + 1] == 1) { //���� ���� �������� �浹�̶��
		if (BOARD[Y][X + 2] == 1) {
			if (BOARD[Y][X + 3] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y][X - 2] == 1) {
				if (BOARD[Y][X - 3] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //���� ���� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X] == 1) {
			if (BOARD[Y + 3][X] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y - 2][X] == 1) {
				if (BOARD[Y - 3][X] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X - 1] == 1) { //���� ������ �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X - 2] == 1) {
			if (BOARD[Y + 3][X - 3] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X + 1] == 1) { //���� ������ �밢�� ������ �浹�̶��
			if (BOARD[Y - 2][X + 2] == 1) {
				if (BOARD[Y - 3][X + 3] == 1) {
					Count += 1;
				}
			}
		}
	}

	if (BOARD[Y + 1][X + 1] == 1) { //���� ���� �밢�� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X + 2] == 1) {
			if (BOARD[Y + 3][X + 3] == 1) {
				Count += 1;
			}
		}
	}
	else {
		if (BOARD[Y - 1][X - 1] == 1) { //���� ���� �밢�� ������ �浹�̶��
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

int _4X2(int X, int Y) { // �� ��X�� ��
	int Count = 0;
	if (BOARD[Y][X + 1] == 1) { //���� ���� �������� �浹�̶��
		if (BOARD[Y][X + 2] != 1 && BOARD[Y][X + 3] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y][X - 1] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y][X - 2] != 1 && BOARD[Y][X - 3] == 1) {
				Count += 1; //ī��Ʈ
			}
		}
	}

	if (BOARD[Y + 1][X] == 1) { //���� ���� �Ʒ����� �浹�̶��
		if (BOARD[Y + 2][X] != 1 && BOARD[Y + 3][X] == 1) {
			Count += 1; //ī��Ʈ
		}
	}
	else {
		if (BOARD[Y - 1][X] == 1) { //���� ���� ������ �浹�̶��
			if (BOARD[Y - 2][X] != 1 && BOARD[Y - 3][X] == 1) {
				Count += 1; //ī��Ʈ
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
	// A. 3,3 �ݼ� �Ϸ�
	if (_3X3(X, Y) == true || _3X2(X, Y) == true || _3Xplus(X, Y) == true || _3Xplus_(X, Y) == true) {
		return true;
	}
	// B. 4,4 �ݼ� �Ϸ�
	if (_4X4(X, Y) == true || _4X2(X, Y) == true) {
		return true;
	}
	// C. 6,6 �ݼ� �Ϸ�
	// D. 3,3,4 �ݼ� �Ϸ�
	// E. 3,4,4 �ݼ� �Ϸ�
	else {
		return false;
	}
}

int BLACK_END() {
	int Temp_Count = 0, Count = 0;

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //����
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //����
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //���� �밢��
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //������ �밢��
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //����
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //����
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //���� �밢��
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

	for (int Y = 0; Y <= MAX_BOARD_Y; Y++) { //������ �밢��
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