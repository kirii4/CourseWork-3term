#include "Check.h"

void Check::checkInt(int& n) {
	while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1'000'000'000)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
	}
}

void Check::checkDouble(double& n) {
	while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1'000'000'000)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
	}
}

void Check::checkString(std::string& str) {
	while (true) {
		int8_t k = 0;

		getline(std::cin, str);
		for (auto i = 0; i < str.size(); i++) //проверка на ввод
		{
			if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] == '-')) {}
			else {
				k++;
				std::cout << "\nОшибка ввода!!\n";
				break;
			}
		}

		if (k == 1) { continue; }

		while (str[str.size() - 1] == ' ')
			str.erase(str.end() - 1);

		if (str == "" || str == " ") {
			std::cout << "\nОшибка ввода!!\n";
		}

		if (str.size() > 14) {
			std::cout << "Введите меньше символов.\n";
			continue;
		}

		char delta = 'А' - 'а';     //Корректировка регистра
		if (str[0] >= 'а' && str[0] <= 'я') str[0] += delta;
		for (auto i = 1; i < str.size(); i++) {
			if (str[i] == 'Ё') { str[i] = 'ё'; }
			else if (str[i] >= 'А' && str[i] <= 'Я') { str[i] -= delta; }
		}

		break;
	}
}

void Check::checkPhoneNumber(std::string& phoneNumber)
{
	while (true) {
		int8_t k = 0;

		getline(std::cin, phoneNumber);
		for (auto i = 0; i < phoneNumber.size(); i++) //проверка на ввод
		{ 
			if ((phoneNumber[i] >= '0' && phoneNumber[i] <= '9') || (phoneNumber[i] == '-') || (phoneNumber[i] == '+') || (phoneNumber[i] == '(') || (phoneNumber[i] == ')')) {}
			else {
				k++;
				std::cout << "\nОшибка ввода!!\n";
				break;
			}
		}

		if (k == 1) { continue; }

		if (phoneNumber.size() > 17) {
			std::cout << "Введите меньше символов.\n";
			continue;
		}

		break;
	}
}

void Check::checkFind(std::string& str) {
	getchar();
	while (true) {
		int8_t k = 0;
		getline(std::cin, str);
		for (auto i = 0; i < str.size(); i++) //проверка на ввод числа
		{
			if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] == '-') || (str[i] == ' ')) {}
			else {
				k++;
				std::cout << "\nОшибка ввода!!\n";
				break;
			}
		}
		if (k == 1) { continue; }
		if (str == "" || str[str.size() - 1] == ' ') {
			std::cout << "\nОшибка ввода!!\n";
			continue;
		}
		char delta = 'А' - 'а';     //Корректировка регистра

		if (str.size() > 14) {
			std::cout << "Введите меньше символов.\n";
			continue;
		}

		if (str[0] >= 'а' && str[0] <= 'я') str[0] += delta;
		for (auto i = 1; i < str.size(); i++) {
			if (str[i] == 'Ё') { str[i] = 'ё'; }
			if (str[i] >= 'А' && str[i] <= 'Я') { str[i] -= delta; }
			if (str[i] >= 'а' && str[i] <= 'я' && str[i - 1] == ' ') str[i] += delta;
		}

		break;
	}
}

void Check::checkBankCard(std::string& bankCard) {
	getchar();
	while (true) {
		int8_t k = 0;
		getline(std::cin, bankCard);
		if (bankCard.size() > 16) {
			bankCard.erase(std::remove(bankCard.begin(), bankCard.end(), ' '), bankCard.end());
		}

		if (bankCard.size() != 16) {
			std::cout << "\nОшибка ввода!!\n";
			continue;
		}
		for (auto i = 0; i < bankCard.size(); i++) //проверка на ввод числа
		{
			if ((bankCard[i] >= '0' && bankCard[i] <= '9')) {}
			else {
				k++;
				std::cout << "\nОшибка ввода!!\n";
				break;
			}
		}
		if (k == 1) { continue; }
		if (bankCard == "" || bankCard[bankCard.size() - 1] == ' ') {
			std::cout << "\nОшибка ввода!!\n";
			continue;
		}
		break;
	}
}

void Check::checkID(std::string& ID) {
	while (true) {
		int8_t k = 0;
		getline(std::cin, ID);
		for (auto i = 0; i < ID.size(); i++) //проверка на ввод числа
		{
			if ((ID[i] >= '0' && ID[i] <= '9')) {}
			else {
				k++;
				std::cout << "\nОшибка ввода!!\n";
				break;
			}
		}
		if (k == 1) { continue; }
		if (ID == "" || ID[ID.size() - 1] == ' ') {
			std::cout << "\nОшибка ввода!!\n";
			continue;
		}
		
		if (ID.size() > 4) {
			std::cout << "Введите меньше символов.\n";
			continue;
		}

		if (ID.size() == 1) ID = "0000" + ID;
		if (ID.size() == 2) ID = "000" + ID;
		if (ID.size() == 3) ID = "00" + ID;
		if (ID.size() == 4) ID = "0" + ID;
		
		break;
	}
}

void Check::checkWork(int& n) {
	while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1)) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
	}
}

void Check::checkDel(std::string& str) {
	bool val = true;
	while (val) {
		try {
			getline(std::cin, str);
			if (std::cin.fail()) {
				throw 1;
			}
			if ((str != "y" && str != "Y") && (str != "n" && str != "N")) {
				throw 1;
			}
			val = false;
		}
		catch (int) {
			std::cout << "Ошибка ввода!!" << std::endl;
		}
	}
}

void AccessDelete() {
	system("cls");
	std::cout << "***************************\n"
		<< "     Успешное удаление\n"
		<< "***************************\n";
}

void Access() {
	system("cls");
	std::cout << "************************\n"
		<< "\tУспешно\n"
		<< "************************\n";
}

void AccessEdit() {
	std::cout << "\n***************************\n"
		<< "  Успешное редактирование\n"
		<< "***************************\n";
}

void AccessAdd() {
	std::cout << "\n***************************\n"
		<< "  Успешное добавление\n"
		<< "***************************\n";
}

void AccessReg() {
	std::cout << "\n***************************\n"
		<< "  Успешная регистрация\n"
		<< "***************************\n";
}

void GoToXY(HANDLE hStdOut, short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(HANDLE hStdOut, bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}