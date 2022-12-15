#include "Client.h"
#include <iomanip>

Client::Client() : Inicials()
{
	this->Address = "None";
	this->phoneNumber = "None";
	this->bankCard = "None";
	this->login = "None";
}

Client::Client(const Client& obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->patronymic = obj.patronymic;
	this->Address = obj.Address;
	this->phoneNumber = obj.phoneNumber;
	this->bankCard = obj.bankCard;
	this->login = obj.login;
}

Client& Client::operator=(const Client& obj)
{
	{
		if (this != &obj) {
			this->name = obj.name;
			this->surname = obj.surname;
			this->patronymic = obj.patronymic;
			this->Address = obj.Address;
			this->phoneNumber = obj.phoneNumber;
			this->bankCard = obj.bankCard;
			this->login = obj.login;
		}
		return *this;
	}
}

void Client::DataMenu(std::vector<Client>& vecClient)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню данных о клиентах\n",
							"",
							"",
							"1.Просмотреть список клиентов.",
							"2.Удалить клиента.",
							"3.Отсортировать список.",
							"4.Корректировать данные.",
							"5.Поиск клиента.",
							"6.Вернуться в меню." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 40, y = 8;
		GoToXY(hStdOut, x, y);
		for (char i = 0; i < size(Menu); i++)
		{
			if (i == aT) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(hStdOut, x, y++);
			std::cout << Menu[i] << std::endl;
		}
		c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESCAPE:
			GoToXY(hStdOut, x, y + 3);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			isG = false;
			aT = 3;
			break;
		case UP:
			if (aT > 3)	--aT;
			break;
		case DOWN:
			if (aT < size(Menu) - 1) ++aT;
			break;
		case ENTER:
			aT -= 2;
			switch (aT)
			{
			case 1:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecClient.size() == 0) {
					system("cls");
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
				}
				else {
					system("cls");
					Client::print(vecClient);
				}
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::del(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::sortMenu(vecClient);
				system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::print(vecClient);
				Client::edit(vecClient);
				system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::findMenu(vecClient);
				system("pause");
				break;
			}
			case 6:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 6) {
		system("cls");
		std::cout << "\tМеню данных о клиентах\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.Просмотреть список клиентов.\n"
			"2.Удалить клиента.\n"
			"3.Отсортировать список.\n"
			"4.Корректировать данные.\n"
			"5.Поиск клиента.\n"
			"6.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecClient.size() == 0) {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
			}
			else {
				Client::print(vecClient);
			}
			system("pause");
			break;
		case 2:
			system("cls");
			Client::del(vecClient);
			system("pause");
			break;
		case 3:
			system("cls");
			Client::sortMenu(vecClient);
			system("pause");
			break;
		case 4:
			system("cls");
			Client::print(vecClient);
			Client::edit(vecClient);
			system("pause");
			break;
		case 5:
			system("cls");
			Client::findMenu(vecClient);
			system("pause");
			break;
		case 6:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "Ошибка ввода!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Client::print(int& i)
{
	i++;
	printf("|%3d. %-14s %-14s %-15s| %14s| %15s  |%10s|\n",
		i, this->getSurname().c_str(), this->getName().c_str(), this->getPatronymic().c_str(), this->getPhoneNumber().c_str(),
		this->getAddress().c_str(), this->getLogin().c_str());
}

void Client::myAccount(Client& account)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "    Меню личного аккаунта",
							"",
							"",
							"1.Просмотреть информацию об аккаунте.",
							"2.Редактировать данные аккаунта.",
							"3.Вернуться в меню." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 40, y = 8;
		GoToXY(hStdOut, x, y);
		for (char i = 0; i < size(Menu); i++)
		{
			if (i == aT) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(hStdOut, x, y++);
			std::cout << Menu[i] << std::endl;
		}
		c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESCAPE:
			GoToXY(hStdOut, x, y + 3);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			isG = false;
			aT = 3;
			break;
		case UP:
			if (aT > 3)	--aT;
			break;
		case DOWN:
			if (aT < size(Menu) - 1) ++aT;
			break;
		case ENTER:
			aT -= 2;
			switch (aT)
			{
			case 1:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::printAcc(account);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::editAcc(account);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 3) {
		system("cls");
		std::cout << "\t\tМеню личного аккаунта\n"
			<< "=============================================\n\n";
		std::cout << "1.Просмотреть информацию об аккаунте.\n"
			"2.Редактировать данные аккаунта.\n"
			"3.Вернуться в меню.\n";

		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Client::printAcc(account);
			system("pause");
			break;
		case 2:
			system("cls");
			Client::editAcc(account);
			system("pause");
			break;
		case 3:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "Ошибка ввода!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Client::accFileInput(Client& account, std::string& login)
{
	std::ifstream f_in(fileClient);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		Client n;
		while (f_in >> n) {
			if (n.getLogin() == login) {
				std::string val = n.getAddress();
				std::replace(val.begin(), val.end(), '_', ' ');
				n.setAddress(val);
				account = n;
			}
		}
	}
	f_in.close();
}

void Client::accFileOutput(Client& account)
{
	std::string val = account.getLogin();
	Client::clearLine(val);
	std::ofstream fout(fileClient, std::ios_base::app);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		std::string val = account.getAddress();
		std::replace(val.begin(), val.end(), ' ', '_');
		account.setAddress(val);
		fout << account << std::endl;
	}
	fout.close();
}

void Client::printAcc(Client& account)
{
	system("cls");
	printf("+---------------------------------------------+------------------+--------------------------------------------+----------+\n");
	printf("|                    ФИО                      |  Номер телефона  |      Адрес                Банковская карта |   Логин  |\n");
	printf("+---------------------------------------------+------------------+--------------------------------------------+----------+\n");
	printf("|%-14s %-14s %-15s|%17s | %15s       %16s |%10s|\n",
		account.getSurname().c_str(), account.getName().c_str(), account.getPatronymic().c_str(),
		account.getPhoneNumber().c_str(), account.getAddress().c_str(), account.getBankCard().c_str(), account.getLogin().c_str());
	printf("+------------------------------------------------------------------------------------------------------------------------+\n\n");
}

void Client::editAcc(Client& account)
{
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string address;
	std::string phoneNumber;
	std::string bankCard;
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "Изменить:",
		"",
		"",
		"1.Фамилию.",
		"2.Имя.",
		"3.Отчество.",
		"4.Адрес.",
		"5.Номер телефона.",
		"6.Банковскую карту.",
		"7.Назад." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 40, y = 8;
		GoToXY(hStdOut, x, y);
		for (char i = 0; i < size(Menu); i++)
		{
			if (i == aT) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(hStdOut, x, y++);
			std::cout << Menu[i] << std::endl;
		}
		c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESCAPE:
			GoToXY(hStdOut, x, y + 3);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			isG = false;
			aT = 3;
			break;
		case UP:
			if (aT > 3)	--aT;
			break;
		case DOWN:
			if (aT < size(Menu) - 1) ++aT;
			break;
		case ENTER:
			aT -= 2;
			switch (aT)
			{
			case 1:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getSurname() << ".\n"
					<< "Введите новое значение: ";
				Check::checkString(surname);
				account.setSurname(surname);
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getName() << ".\n"
					<< "Введите новое значение: ";
				Check::checkString(name);
				account.setName(name);
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getPatronymic() << ".\n"
					<< "Введите новое значение: ";
				Check::checkString(patronymic);
				account.setPatronymic(patronymic);
				aT = 3;
				break;
			}
			case 4:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getAddress() << ".\n"
					<< "Введите новое значение: ";
				//Check::checkString(address);
				getline(std::cin, address);
				account.setAddress(address);
				aT = 3;
				break;
			}
			case 5:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getPhoneNumber() << ".\n"
					<< "Введите новое значение: ";
				getline(std::cin, phoneNumber);
				//Check::checkString(phoneNumber);
				account.setPhoneNumber(phoneNumber);
				aT = 3;
				break;
			}
			case 6:
			{
				system("cls");
				//GoToXY(hStdOut, x, 0);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Текущее значение: " << account.getBankCard() << ".\n"
					<< "Введите новое значение (16 цифр): ";
				Check::checkBankCard(bankCard);
				//Check::checkString(phoneNumber);
				account.setBankCard(bankCard);
				aT = 3;
				break;
			}
			case 7:
				system("cls");
				//GoToXY(hStdOut, x, y);
				//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	std::cout << "Изменить:\n"
		"1.Фамилию.\n"
		"2.Имя.\n"
		"3.Отчество.\n"
		"4.Адрес.\n"
		"5.Номер телефона.\n"
		"6.Банковскую карту.\n"
		"7.Назад.\n";
	int menu;
	Check::checkInt(menu);
	if (menu != 7) {
		std::cout << "Текущее значение: ";
		switch (menu) {
		case 1:
			std::cout << account.getSurname() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(surname);
			account.setSurname(surname);
			break;
		case 2:
			std::cout << account.getName() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(name);
			account.setName(name);
			break;
		case 3:
			std::cout << account.getPatronymic() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(patronymic);
			account.setPatronymic(patronymic);
			break;
		case 4:
			std::cout << account.getAddress() << ".\n"
				<< "Введите новое значение: ";
			//Check::checkString(address);
			getchar();
			getline(std::cin, address);
			account.setAddress(address);
			break;
		case 5:
			std::cout << account.getPhoneNumber() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			getline(std::cin, phoneNumber);
			//Check::checkString(phoneNumber);
			account.setPhoneNumber(phoneNumber);
			break;
		case 6:
			std::cout << account.getBankCard() << ".\n"
				<< "Введите новое значение (16 цифр): ";
			getline(std::cin, bankCard);
			//Check::checkString(phoneNumber);
			account.setBankCard(bankCard);
			break;
		default:
			std::cout << "Ошибка ввода!!\n";
			break;
		}
		AccessEdit();
	}

#endif // DEBUG
}

void Client::clearLine(std::string& login)
{
	Client n;
	size_t index = 0;
	std::ifstream f_in(fileClient);
	while (f_in >> n) {
		if (n.getLogin() == login) break;
		index++;
	}
	f_in.close();
	std::vector<std::string> vec;
	std::ifstream file(fileClient);
	if (file.is_open())
	{
		std::string str;
		while (std::getline(file, str))
			vec.push_back(str);
		file.close();
		if (index < vec.size()) {
			vec.erase(vec.begin() + index);
			std::ofstream outfile(fileClient);
			if (outfile.is_open())
			{
				std::copy(vec.begin(), vec.end(),
					std::ostream_iterator<std::string>(outfile, "\n"));
				outfile.close();
			}
		}
	}
}

void Client::print(std::vector<Client>& vecClient)
{
	system("cls");
	std::cout << std::setw(108) << "+-----------------------------------------------------------------------------------------+----------+" << std::endl;
	std::cout << std::setw(108) << "|                      ФИО                         |   Номер телефона  |      Адрес       |   Логин  |" << std::endl;
	std::cout << std::setw(108) << "+-----------------------------------------------------------------------------------------+----------+" << std::endl;
	for (auto i = 0; i < vecClient.size(); i++) {
		printf("%6s|%3d. %-14s %-14s %-15s| %17s | %15s  |%10s |\n", "",
			i + 1, vecClient[i].getSurname().c_str(), vecClient[i].getName().c_str(), vecClient[i].getPatronymic().c_str(), vecClient[i].getPhoneNumber().c_str(),
			vecClient[i].getAddress().c_str(), vecClient[i].getLogin().c_str());
	
		std::cout << std::setw(108) << "+-----------------------------------------------------------------------------------------+----------+" << std::endl;
	}
}

void Client::del(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		Client::print(vecClient);
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecClient.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else {
					vecClient.erase(vecClient.begin() + num);
					AccessDelete();
					break;
				}
			}
		}
	}
}

void Client::edit(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::cout << "Введите номер элемента для изменения.\n";
		int num_list;
		Check::checkInt(num_list);
		while (!(num_list > 0 && num_list <= vecClient.size())) {
			std::cout << "Неверный ввод номера!\n";
			Check::checkInt(num_list);
		}
		std::cout << "Изменить:\n"
			"1.Фамилию.\n"
			"2.Имя.\n"
			"3.Отчество.\n"
			"4.Адрес.\n"
			"5.Номер телефона.\n";
		int menu;
		std::string surname;
		std::string name;
		std::string patronymic;
		std::string address;
		std::string phoneNumber;
		Check::checkInt(menu);
		std::cout << "Текущее значение: ";
		switch (menu) {
		case 1:
			std::cout << vecClient[num_list - 1].getSurname() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(surname);
			vecClient[num_list - 1].setSurname(surname);
			break;
		case 2:
			std::cout << vecClient[num_list - 1].getName() << ".\n"
				<< "Введите новое значение: ";
			Check::checkString(name);
			getchar();
			vecClient[num_list - 1].setName(name);
			break;
		case 3:
			std::cout << vecClient[num_list - 1].getPatronymic() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(patronymic);
			vecClient[num_list - 1].setPatronymic(patronymic);
			break;
		case 4:
			std::cout << vecClient[num_list - 1].getAddress() << ".\n"
				<< "Введите новое значение: ";
			//Check::checkString(address);
			getchar();
			getline(std::cin, address);
			vecClient[num_list - 1].setAddress(address);
			break;
		case 5:
			std::cout << vecClient[num_list - 1].getPhoneNumber() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkPhoneNumber(phoneNumber);
			vecClient[num_list - 1].setPhoneNumber(phoneNumber);
			break;
		default:
			std::cout << "Ошибка ввода!!\n";
			break;
		}
		AccessEdit();
	}
}

void Client::findMenu(std::vector<Client>& vecClient)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню поиска",
							"",
							"",
							"1.Поиск по ФИО.",
							"2.Поиск по адресу.",
							"3.Вернуться в меню." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 40, y = 8;
		GoToXY(hStdOut, x, y);
		for (char i = 0; i < size(Menu); i++)
		{
			if (i == aT) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(hStdOut, x, y++);
			std::cout << Menu[i] << std::endl;
		}
		c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESCAPE:
			GoToXY(hStdOut, x, y + 3);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			isG = false;
			aT = 3;
			break;
		case UP:
			if (aT > 3)	--aT;
			break;
		case DOWN:
			if (aT < size(Menu) - 1) ++aT;
			break;
		case ENTER:
			aT -= 2;
			switch (aT)
			{
			case 1:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::findInicials(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::findAddress(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 3) {
		system("cls");
		std::cout << "\t\tМеню поиска\n"
			<< "=============================================\n\n";
		std::cout << "1.Поиск по ФИО.\n"
			"2.Поиск по адресу.\n"
			"3.Вернуться в меню.\n";

		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Client::findInicials(vecClient);
			system("pause");
			break;
		case 2:
			system("cls");
			Client::findAddress(vecClient);
			system("pause");
			break;
		case 3:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "Ошибка ввода!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Client::findInicials(std::vector<Client>& vecClient)
{
	system("cls");
	std::cout << "Введите ФИО клиента: ";
	std::string name;
	getline(std::cin, name);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0U; i < vecClient.size(); i++) {
		std::string _name = vecClient[i].getSurname() + ' ' + vecClient[i].getName() + ' ' + vecClient[i].getPatronymic();
		if (_name.find(name) != std::string::npos) {
			vecClient[i].print(k);
		}
	}
	if (k == 0) {
		std::cout << "Клиентов по запрошенной фамилии не найдено!\n";
	}
	std::cout << std::endl;
}

void Client::findAddress(std::vector<Client>& vecClient)
{
	system("cls");
	std::cout << "Введите адрес: ";
	std::string address;
	getchar();
	getline(std::cin, address);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0U; i < vecClient.size(); i++) {
		if (vecClient[i].getName().find(address) != std::string::npos) {
			vecClient[i].print(k);
		}
	}
	if (k == 0) {
		std::cout << "Товары по запрошенному названию не найдено!\n";
	}
}

void Client::sortMenu(std::vector<Client>& vecClient)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню сортировки",
								"",
								"",
								"1.Отсортировать по алфавиту.",
								"2.Отсортировать по номеру телефона.",
								"3.Отсортировать по логину.",
								"4.Отсортировать по адресу.",
								"5.Вернуться в меню." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 40, y = 8;
		GoToXY(hStdOut, x, y);
		for (char i = 0; i < size(Menu); i++)
		{
			if (i == aT) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(hStdOut, x, y++);
			std::cout << Menu[i] << std::endl;
		}
		c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESCAPE:
			GoToXY(hStdOut, x, y + 3);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			isG = false;
			aT = 3;
			break;
		case UP:
			if (aT > 3)	--aT;
			break;
		case DOWN:
			if (aT < size(Menu) - 1) ++aT;
			break;
		case ENTER:
			aT -= 2;
			switch (aT)
			{
			case 1:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::alphSort(vecClient);
				std::cout << "\tСортировка по алфавиту." << std::endl << std::endl;
				Client::print(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::phoneNumberSort(vecClient);
				std::cout << "\tСортировка по телефону." << std::endl << std::endl;
				Client::print(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::loginSort(vecClient);
				std::cout << "\tСортировка по логину." << std::endl << std::endl;
				Client::print(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 4:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::addressSort(vecClient);
				std::cout << "\tСортировка по адресу." << std::endl << std::endl;
				Client::print(vecClient);
				system("pause");
				aT = 3;
				break;
			}
			case 5:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	system("cls");
	int menu = 0;
	std::cout << "\tМеню сортировки\n"
		<< "==================================\n\n";
	while (menu != 5) {
		std::cout << "1.Отсортировать по алфавиту.\n"
			"2.Отсортировать по номеру телефона.\n"
			"3.Отсортировать по логину.\n"
			"4.Отсортировать по адресу.\n"
			"5.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Client::alphSort(vecClient);
			std::cout << "\t\t\t\t\t" << "Сортировка по алфавиту." << std::endl << std::endl;
			Client::print(vecClient);
			system("pause");
			break;
		case 2:
			system("cls");
			Client::phoneNumberSort(vecClient);
			std::cout << "\t\t\t\t\t" << "Сортировка по телефону." << std::endl << std::endl;
			Client::print(vecClient);
			system("pause");
			break;
		case 3:
			system("cls");
			Client::loginSort(vecClient);
			std::cout << "\t\t\t\t\t" << "Сортировка по логину." << std::endl << std::endl;
			Client::print(vecClient);
			system("pause");
			break;
		case 4:
			system("cls");
			Client::addressSort(vecClient);
			std::cout << "\t\t\t\t\t" << "Сортировка по адресу." << std::endl << std::endl;
			Client::print(vecClient);
			system("pause");
			break;
		case 5:
			system("cls");
			break;
		default:
			std::cout << "\nОшибка ввода!!\n";
			break;
			}
			}

#endif // KEYBOARD
		}

void Client::alphSort(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::sort(vecClient.begin(), vecClient.end(), [](Client clin1, Client clin2) {
			if (clin1.getSurname() == clin2.getSurname()) {
				if (clin1.getName() == clin2.getName()) {
					return clin1.getPatronymic() < clin1.getPatronymic();
				}
				else {
					return clin1.getName() < clin2.getName();
				}
			}
			else {
				return clin1.getSurname() < clin2.getSurname();
			}
			});
	}
}

void Client::addressSort(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::sort(vecClient.begin(), vecClient.end(), [](Client clin1, Client clin2) {
			return clin1.getAddress() < clin2.getAddress();
			});
	}
}

void Client::loginSort(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::sort(vecClient.begin(), vecClient.end(), [](Client clin1, Client clin2) {
			return clin1.getLogin() < clin2.getLogin();
			});
	}
}

void Client::setAddress(std::string Address)
{
	this->Address = Address;
}

void Client::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Client::setBankCard(std::string bankCard)
{
	this->bankCard = bankCard;
}

void Client::setLogin(std::string login)
{
	this->login = login;
}

void Client::phoneNumberSort(std::vector<Client>& vecClient)
{
	if (vecClient.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::sort(vecClient.begin(), vecClient.end(), [](Client clin1, Client clin2) {
			return clin1.getPhoneNumber() < clin2.getPhoneNumber();
			});
	}
}

std::string Client::getAddress()
{
	return Address;
}

std::string Client::getPhoneNumber()
{
	return phoneNumber;
}

std::string Client::getBankCard()
{
	return bankCard;
}

std::string Client::getLogin()
{
	return login;
}

std::ostream& operator<<(std::ostream& os, Client& obj)
{
	os << ' ' << obj.surname << ' ' << obj.name << ' '
		<< obj.patronymic << ' ' << obj.phoneNumber << ' '
		<< obj.Address << ' ' << obj.bankCard << ' ' << obj.login;
	return os;
}

std::istream& operator>>(std::istream& is, Client& obj)
{
	is >> obj.surname >> obj.name >> obj.patronymic >> obj.phoneNumber >> obj.Address >> obj.bankCard >> obj.login;
	return is;
}

void Client::fileInput(std::vector<Client>& vecClient)
{
	std::ifstream f_in(fileClient);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		Client n;
		while (f_in >> n) {//Запись из файла в вектор
			if (vecClient.size() >= MAX_VECTOR_SIZE) {
				std::cout << "\n\nПревышение размерности списка!!!.\n";
				break;
			}
			std::string val = n.getAddress();
			std::replace(val.begin(), val.end(), '_', ' ');
			n.setAddress(val);
			vecClient.push_back(n);
		}
	}
	f_in.close();
}

void Client::fileOutput(std::vector<Client>& vecClient)
{
	std::ofstream fout(fileClient, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		for (auto i = 0; i < vecClient.size(); i++) {
			std::string val = vecClient[i].getAddress();
			std::replace(val.begin(), val.end(), ' ', '_');
			vecClient[i].setAddress(val);
			fout << vecClient[i] << std::endl;
		}
	}
	fout.close();
}

Client::~Client()
{

}