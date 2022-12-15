#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>

#define fileAcc "User.txt"

#define KEYBOARD

enum Code : int {
	ESCAPE = 27,
	ENTER = 13,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	W = 119,
	w = 119,
	A = 65,
	a = 97,
	S = 83,
	s = 115,
	D = 68,
	d = 100
};

namespace Check {
	void checkInt(int& n); //�������� �� ���� ������ �����

	void checkDouble(double& n); //�������� �� ���� ������������� �����

	void checkString(std::string& str); //�������� �� ���� �����

	void checkPhoneNumber(std::string& phoneNumber);

	void checkFind(std::string& str); //�������� �� ���� ������ ��� ������

	void checkDel(std::string& str); //�������� �� ���� ��������� ��������/���������� �� ��������

	void checkID(std::string& ID); //�������� �� ���� ������������� ������

	void checkBankCard(std::string& bankCard);

	void checkWork(int& n);
}
void AccessDelete(); //����� ��������� �� �������� ��������

void Access(); //����� ��������� �� �������� ��������

void AccessEdit(); //����� ��������� �� �������� ��������������

void AccessAdd(); //����� ��������� �� �������� ����������

void AccessReg(); //����� ��������� � ������������� �����������

void GoToXY(HANDLE hStdOut, short x, short y);

void ConsoleCursorVisible(HANDLE hStdOut, bool show, short size);