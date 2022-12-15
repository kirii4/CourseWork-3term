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
	void checkInt(int& n); //Проверка на ввод целого числа

	void checkDouble(double& n); //Проверка на ввод вещественного числа

	void checkString(std::string& str); //Проверка на ввод строк

	void checkPhoneNumber(std::string& phoneNumber);

	void checkFind(std::string& str); //Проверка на ввод строки для поиска

	void checkDel(std::string& str); //Проверка на ввод параметра согласия/несогласия на удаление

	void checkID(std::string& ID); //Проверка на ввод студенческого билета

	void checkBankCard(std::string& bankCard);

	void checkWork(int& n);
}
void AccessDelete(); //Вывод сообщения об успешном удалении

void Access(); //Вывод сообщения об успешном действии

void AccessEdit(); //Вывод сообщения об успешном редактировании

void AccessAdd(); //Вывод сообщения об успешном добавлении

void AccessReg(); //Вывод сообщения о подтверждении регистрации

void GoToXY(HANDLE hStdOut, short x, short y);

void ConsoleCursorVisible(HANDLE hStdOut, bool show, short size);