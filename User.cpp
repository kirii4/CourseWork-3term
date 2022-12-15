#include "User.h"

User::User() {
	login = "None";
	password = "None";
	role = 0;
}

User::User(std::string login, std::string password, int role) {
	this->login = login;
	this->password = password;
	this->role = role;
}

User::User(const User& obj) {
	this->login = obj.login;
	this->password = obj.password;
	this->role = obj.role;
}

void User::setLogin(const std::string login)
{
	this->login = login;
}

void User::setPassword(const std::string password)
{
	this->password = password;
}

void User::setRole(const int role)
{
	this->role = role;
}

void User::plusPasswordSymb(char ch)
{
	this->password += ch;
}

std::string User::getLogin()
{
	return login;
}

std::string User::getPassword()
{
	return password;
}

int User::getRole()
{
	return role;
}

User& User::operator=(const User& obj)
{
	if (this != &obj) {
		this->login = obj.login;
		this->password = obj.password;
		this->role = obj.role;
	}
	return *this;
}

std::istream& operator>>(std::istream& is, User& obj) {
	is >> obj.login >> obj.password >> obj.role;
	return is;
}

std::ostream& operator<<(std::ostream& os, User& obj)
{
	os << obj.login << ' ' << obj.password << ' ' << obj.role;
	return os;
}

//Меню пользователя
void User::userMenu(std::string& login) {
	Transaction<Order> _order;
	std::vector<Shop> vecShop;
	Shop::fileInput(vecShop);
	Client account;
	Client::accFileInput(account, login);
	if (account.getLogin() == "None") account.setLogin(login);
	Order order;
	Order::fileInputBasket(order, login);
	if (order.getID() == "None") Order::createID(order, account);

#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню пользователя",
							"",
							"",
							"1.Мой аккаунт.",
							"2.Заказать товар.",
							"3.Выход из системы." };
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
			std::cout << "Выход из системы.\n";
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::myAccount(account);
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Order::add(account, order, vecShop);
				//_order.beginTransaction(order);
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "\nВыход из программы.\n";
				_order.commit();
				if (order.getAddress() == "None" && account.getAddress() != "None") {
					order.setAddress(account.getAddress());
				}
				Order::fileOutputBasket(order);
				Client::accFileOutput(account);
				exit(0);
				break;
			}
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
		std::cout << "\t Меню пользователя\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.Мой аккаунт.\n"
			"2.Заказать товар.\n"
			"3.Выход из системы.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Client::myAccount(account);
			break;
		case 2:
			system("cls");
			Order::add(account, order, vecShop);
			break;
		case 3:
			std::cout << "\nВыход из программы.\n";
			Order::fileOutputBasket(order);
			Client::accFileOutput(account);
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "\nОшибка ввода!!\n";
			break;
		}
	}
#endif // !KEYBOARD

}

void DataMenu(std::vector<Shop>& vecShop, std::vector<Order>& vecOrd, std::vector<Client>& vecClient) {

#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "     Меню работы с данными",
		"",
		"",
		"1.Работа с данными магазинов.",
		"2.Работа с данными заказов.",
		"3.Работа с данными клиентов.",
		"4.Вернуться в главное меню." };
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
			std::cout << "Выход из системы.\n";
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Shop::DataMenu(vecShop);
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Order::DataMenu(vecOrd);
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Client::DataMenu(vecClient);
				break;
			}
			case 4:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			}
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 4) {
		system("cls");
		std::cout << "     Меню работы с данными\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.Работа с данными магазинов.\n"
			"2.Работа с данными заказов.\n"
			"3.Работа с данными клиентов.\n"
			"4.Вернуться в главное меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Shop::DataMenu(vecShop);
			break;
		case 2:
			system("cls");
			Order::DataMenu(vecOrd);
			break;
		case 3:
			system("cls");
			Client::DataMenu(vecClient);
			break;
		case 4:
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

void User::adminMenu(std::string& login) {
	std::vector<User> vecReg;
	std::vector<User> vecAcc;
	std::vector<Shop> vecShop;
	std::vector<Order> vecOrd;
	std::vector<Client> vecClient;
	User::fileInputReg(vecReg);
	User::fileInputUser(vecAcc);
	Shop::fileInput(vecShop);
	Order::fileInput(vecOrd);
	Client::fileInput(vecClient);

#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню админа",
							"",
							"",
							"1.Работа с аккаунтами.",
							"2.Работа с данными.",
							"3.Выход из системы." };
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
			std::cout << "Выход из системы.\n";
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				AccMenu(vecReg, vecAcc, login);
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				DataMenu(vecShop, vecOrd, vecClient);
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "\nВыход из системы.\n";
				User::fileOutputReg(vecReg);
				User::fileOutputUser(vecAcc);
				Shop::fileOutput(vecShop);
				Order::fileOutput(vecOrd);
				Client::fileOutput(vecClient);
				exit(0);
				break;
			}
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
		std::cout << "\t\t Меню админа\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.Работа с аккаунтами.\n" //1.Просмотр заявок на регистрацию
			"2.Работа с данными.\n"
			"3.Выход из системы.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			AccMenu(vecReg, vecAcc, login);
			break;
		case 2:
			system("cls");
			DataMenu(vecShop, vecOrd, vecClient);
			break;
		case 3:
			std::cout << "\nВыход из системы.\n";
			User::fileOutputReg(vecReg);
			User::fileOutputUser(vecAcc);
			Shop::fileOutput(vecShop);
			Order::fileOutput(vecOrd);
			Client::fileOutput(vecClient);
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "Ошибка ввода!!\n";
			break;
		}
	}
#endif // KEYBOARD
}

void AccMenu(std::vector<User>& vecReg, std::vector<User>& vecUser, std::string& login) {
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню работы с аккаунтами",
							"",
							"",
							"1.Просмотр заявок на регистрацию.",
							"2.Просмотр учетных записей.",
							"3.Удаление учетный записей.",
							"4.Создать заявку для новой учетной записи.",
							"5.Вернуться в главное меню." };

	char aT = 3;
	char c;
	bool isG = true;
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
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				GoToXY(hStdOut, 0, 0);
				registrMenu(vecUser, vecReg);
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printConsole(vecUser);
				aT = 3;
				system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printConsole(vecUser);
				delAcc(vecUser, login);
				system("pause");
				aT = 3;
				break;
			}
			case 4:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				registration(vecUser, vecReg, "admin");
				system("pause");
				aT = 3;
				break;
			}
			case 5:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				system("cls");
				aT = 3;
				break;
			}
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 5) {
		system("cls");
		std::cout << "\tМеню работы с аккаунтами\n"
			<< "=============================================\n\n";
		std::cout << "1.Просмотр заявок на регистрацию.\n"
			"2.Просмотр учетных записей.\n"
			"3.Удаление учетный записей.\n"
			"4.Создать заявку для новой учетной записи.\n"
			"5.Вернуться в главное меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			registrMenu(vecUser, vecReg);
			break;
		case 2:
			system("cls");
			printConsole(vecUser);
			system("pause");
			break;
		case 3:
			system("cls");
			printConsole(vecUser);
			delAcc(vecUser, login);
			system("pause");
			break;
		case 4:
			system("cls");
			registration(vecUser, vecReg, "admin");
			system("pause");
			break;
		case 5:
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

void User::fileInputReg(std::vector<User>& vecUser) {
	std::ifstream f_in(fileReg);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		User n;
		while (f_in >> n) {//Запись из файла в вектор
			if (vecUser.size() >= MAX_VECTOR_SIZE && vecUser[149].getLogin() != "None") {
				std::cout << "\n\nПревышение размерности списка!!!.\n";
				break;
			}
			vecUser.push_back(n);
		}
	}
	f_in.close();
}

void User::fileInputUser(std::vector<User>& vecUser) {
	std::ifstream f_in(fileAcc);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		User n;
		while (f_in >> n) {//Запись из файла в вектор
			if (vecUser.size() >= MAX_VECTOR_SIZE && vecUser[149].getLogin() != "None") {
				std::cout << "\n\nПревышение размерности списка!!!.\n";
				break;
			}
			vecUser.push_back(n);
		}
	}
	f_in.close();
}

void User::fileOutputReg(std::vector<User>& vecReg) {
	std::ofstream fout(fileReg, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		User::printFile(vecReg, fout);
	}
	fout.close();
}

void User::fileOutputUser(std::vector<User>& vecUser) {
	std::ofstream fout(fileAcc, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		User::printFile(vecUser, fout);
	}
	fout.close();
}

void User::printFile(std::vector<User>& vecUser, std::ostream& fl)
{
	for (auto i = 0; i < vecUser.size(); i++) {
		fl << vecUser[i] << std::endl;
	}
}

void User::printFile(User& obj, std::ostream& fl)
{
	fl << obj << std::endl;
}

void User::createAdmin() {
	std::ofstream User(fileAcc);
	User << "admin " << 16559146482384667732 << ' ' << 1; //Заполнение файла аккаунтом базового админа
	User.close();										  //16559146482384667732 = hash("admin")
}

int User::welcome() {
	std::vector<User> vecReg;
	vecReg.resize(150);
	std::vector<User> vecAcc;
	vecAcc.resize(150);

#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "Добро пожаловать!",
							"",
							"",
						   "1.Войти в аккаунт.",
						   "2.Создать аккаунт.",
						   "3.Выход." };
	bool isG = true;
	char aT = 3;
	char c;
	while (isG)
	{
		system("cls");
		char x = 50, y = 8;
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
			std::cout << "Выход из системы.\n";
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
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				GoToXY(hStdOut, 0, 0);
				aT = 3;
				return 1;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				User::fileInputReg(vecReg);
				User::fileInputUser(vecAcc);
				GoToXY(hStdOut, 0, 0);
				registration(vecAcc, vecReg, "reg");
				aT = 3;
				return 0;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << "Выход из системы.\n";
				isG = false;
				break;
			}
			default:
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else
	std::cout << "\tДобро пожаловать!" << std::endl
		<< "1.Войти в аккаунт." << std::endl
		<< "2.Создать аккаунт." << std::endl
		<< "3.Выход." << std::endl;
	int menu{ 0 };
	Check::checkInt(menu);
	switch (menu) {
	case 1:
		getchar();
		return 1;
		break;
	case 2:
		User::fileInputReg(vecReg);
		User::fileInputUser(vecAcc);
		registration(vecAcc, vecReg, "reg");
		return 0;
		break;
	case 3:
		std::cout << "Выход из системы.\n";
		break;
	default:
		std::cout << "Ошибка ввода!\n";
		break;
	}

#endif // KEYBOARD
	return {};
}

int User::sign_in(std::string& login) {  //Вход в аккаунт
	std::ifstream acc(fileAcc);
	if (!acc.is_open()) {
		User::createAdmin();
	}
	acc.close();
	acc.open(fileAcc);
	int try_ = 0; // Количество попыток(максимум 3)
	bool user = false;
	User obj;
	std::string _login, _password; int _role; //1 - админ, 0 - пользователь
	system("cls");
	while (true) {
		std::cout << "\tАвторизация" << std::endl;
		std::cout << "==============================" << std::endl << std::endl;
		std::cout << "Введите логин:" << std::endl;
		//if (try_ == 0) getchar();
		getline(std::cin, _login);
		obj.setLogin(_login);
		std::cout << "Введите пароль:" << std::endl;
		star(obj);
		std::hash<std::string> salt;
		obj.setPassword(std::to_string(salt(obj.getPassword()))); //Хешируем введенный пароль

		while (acc >> _login && acc >> _password && acc >> _role) {
			if (_login == obj.getLogin() && _password == obj.getPassword()) { //Пароль с логином нашли - выходим из цикла проверки по файлу
				user = true;
				break;
			}
		}


		if (user) { //Если логин и пароль подошли переходим в меню
			login = obj.getLogin();
			if (_role == 1) {
				return 1; //Код админа
			}
			else {
				return 0; //Код пользователя
			}
		}
		else {
			acc.clear(); //возврат указателя на начало файла
			acc.seekg(0);
			try_++;
			system("cls");
			std::cout << "Пароль или логин неправильный!!!\n\n";
			if (try_ == 1) std::cout << "У вас осталось " << 3 - try_ << " попытки!!!\n\n"; // осталось 2 попытки
			else std::cout << "У вас осталась " << 3 - try_ << " попытка!!!\n\n"; // осталась 1 попытка
			if (try_ == 3) {           //Проверка пароля
				std::cout << "\nОшибка входа!!!\n";
				exit(0);
			}
		}
	}
}

void star(User& obj) {
	obj.setPassword("");
	int ch = 0;
	while (true) {              // Замена пароля при вводе на звездочки (*)
		ch = _getch();        // Помещаем код нажатой клавиши в переменную.
		if (ch == 13) {         // Установка Enter на прерывание цикла.
			break;         // Прерывание цикла.
		}
		if (ch == 27) {   // Esc - конец программы
			exit(0);
		}
		if (ch == 8) {    //Backspace
			std::cout << (char)8 << ' ' << char(8); //Смещение курсора на одну позицию влево, вывод пробела и
													// снова смещение курсора влево (при нажатии Backspace
													// символ будет стираться, а курсор перемещается).
			if (!obj.getPassword().empty()) //Если строка pass не является пустой, то из неё
									//можно удалять последний символ (Иначе закрывалась консоль.
				obj.getPassword().erase(obj.getPassword().length() - 1); // позволяет удалить последний символ из строки pass
		}
		else {
			std::cout << '*';            // Замена символов на *
			obj.plusPasswordSymb((char)ch);       // Код из целого числа -> символ.
		}
	}
}

void registrMenu(std::vector<User>& vecAcc, std::vector<User>& vecReg) {

	if (vecReg.empty()) {
		system("cls");
		std::cout << "Запросов для регистраций нет.\n\n";
		system("pause");
	}
	else {
#ifdef KEYBOARD

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursorVisible(hStdOut, false, 100);
		std::string Menu[] = { "Меню работы с регистрацией",
								"",
								"",
							   "1.Обработать запросы на регистрацию.",
							   "2.Вернуться в главное меню." };
		char aT = 3;
		char c;
		bool isG = true;
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
					GoToXY(hStdOut, x, y);
					SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					GoToXY(hStdOut, 0, 0);
					regWork(vecAcc, vecReg);
					aT = 3;
					system("pause");
					break;
				}
				case 2:
				{
					system("cls");
					GoToXY(hStdOut, x, y);
					SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					GoToXY(hStdOut, 0, 0);
					isG = false;
					system("cls");
					break;
				}
				default:
					std::cout << "Ошибка ввода!\n";
					break;
				}
			}
		}

#else
		int menu = 0;
		while (menu != 2) {
			system("cls");
			std::cout << "\tМеню работы с регистрацией\n"
				<< "==========================================\n\n";
			std::cout << "1.Обработать запросы на регистрацию.\n"
				<< "2.Вернуться в главное меню.\n";
			Check::checkInt(menu);
			if (vecReg.empty() && menu == 1) {
				system("cls");
				std::cout << "Запросов для регистраций нет.\n\n";
				break;
			}
			else
				if (menu == 1) {
					switch (menu) {
					case 1:
						regWork(vecAcc, vecReg);
						system("pause");
						break;
					case 2:
						system("cls");
						break;
					default:
						std::cout << "Ошибка ввода!!\n";
						break;
					}
				}
		}
#endif // KEYBOARD
	}
}

void regWork(std::vector<User>& vecAcc, std::vector<User>& vecReg) {
	int reg;
	std::string val;
	printConsole(vecReg);
	std::cout << "Выберите номер поля для обработки: ";
	int pos;
	Check::checkInt(pos);
	std::cout << "1. Подтвердить регистрацию.\n"
		<< "2. Отклонить регистрацию.\n";
	Check::checkInt(reg);
	switch (reg) {
	case 1:
		system("cls");
		finishReg(vecAcc, vecReg, pos);
		break;
	case 2:
		system("cls");
		std::cout << "Возможна потеря данных!\n"
			<< "Подтвердите действие(y/n): ";
		getchar();
		Check::checkDel(val);
		if (val == "n" || val == "N") {
			std::cout << "\nУдаление отменено!\n\n";
			break;
		}
		else {
			vecReg.erase(vecReg.begin() + pos - 1);
			AccessDelete();
			break;
		}
	default:
		std::cout << "Ошибка ввода!!\n";
		break;
	}
}

void registration(std::vector<User>& vecAcc, std::vector<User>& vecReg, std::string typeReg) {
	User obj;
	int try_ = 0;
	bool bLogin = false;
	system("cls");
	while (try_ != 3) {
		std::cout << "Введите логин: " << std::endl;
		getline(std::cin, obj.login);
		if (obj.login.size() < 3) {
			std::cout << std::endl << "Минимальная длина логина 4 символа." << std::endl;
			try_++;
			bLogin = false;
			continue;
		}
		for (auto i = 0U; i < vecAcc.size(); i++) {
			if (vecAcc[i].login == obj.login) {
				system("cls");
				bLogin = true;
				break;
			}
		}
		if (bLogin) {
			std::cout << "Данный логин уже занят.\n";
			try_++;
			bLogin = false;
		}
		else {
			break;
		}
		if (try_ == 3) {
			std::cout << "Неудачная попытка регистрации\n";
		}
	}

	if (try_ != 3) {
		try_ = 0;
		enterRegPass(try_, vecAcc, obj);
		if (try_ == 3) {
			std::cout << std::endl << "Неудачная попытка регистрации.\n";
		}
		else {
			std::cout << std::endl << "Введите роль данного аккаунта(0 - пользователь, 1 - админ):\n";
			Check::checkWork(obj.role);

			std::string file = "registration.txt";
			std::ofstream fReg(file, std::ios_base::out | std::ios_base::app);
			User::printFile(obj, fReg);
			std::cout << "Регистрация завершена.\n";
			vecReg.push_back(obj);
			fReg.close();
			if (typeReg == "reg") {
				std::cout << "Ожидайте подтверждение регистрации админом!\n";
			}
		}
	}
}

void enterRegPass(int& try_, std::vector<User>& vecAcc, User& obj) {
	User _obj;
	bool bPassword = false;
	while (try_ != 3) {
		std::cout << "Введите пароль: " << std::endl;
		UserPassword(obj);
		if (obj.getPassword().size() <= 3) {
			std::cout << std::endl << "Минимальная длина пароля 4 символа.\n";
			try_++;
			continue;
		}
		std::cout << std::endl << "Повторите пароль: " << std::endl;
		UserPassword(_obj);

		if (_obj.getPassword().size() <= 3) {
			std::cout << std::endl << "Минимальная длина пароля 4 символа.\n";
			try_++;
			continue;
		}

		if (obj.getPassword() != _obj.getPassword()) {
			std::cout << std::endl << "Пароли не совпадают!\n";
			try_++;
			continue;
		}

		std::hash<std::string> salt;
		obj.setPassword(std::to_string(salt(obj.getPassword())));

		for (auto i = 0U; i < vecAcc.size(); i++) {
			if (vecAcc[i].getPassword() == obj.getPassword()) {
				try_++;
				bPassword = true;
				break;
			}
		}
		if (bPassword) {
			std::cout << std::endl << "Данный пароль не уникален.\n";
			bPassword = false;
		}
		else {
			break;
		}
	}
}

void UserPassword(User& obj) {
	bool error{ false };
	do {
		error = false;
		star(obj);
		for (auto i = 0U; i < obj.getPassword().size(); i++) {
			if (obj.getPassword()[i] == ' ') {
				std::cout << std::endl << "Ошибка ввода(возможно введен пробел)." << std::endl;
				break;
				error = true;
			}
		}
	} while (error);
}

void delAcc(std::vector<User>& vecAcc, std::string& login) {
	if (vecAcc.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecAcc.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else if (vecAcc[num].getLogin() == login) {
				std::cout << "\tОшибка\nВы не можете удалить собственный аккаунт.\n	";
				break;
			}
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				getchar();
 				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else if (val == "y" || val == "Y") {
					vecAcc.erase(vecAcc.begin() + num);
					system("cls");
					AccessDelete();
					break;
				}
			}
		}
	}
}

void finishReg(std::vector<User>& vecAcc, std::vector<User>& vecReg, const int pos) {
	std::ofstream fout(fileAcc, std::ios_base::app); //acc_base
	vecAcc.push_back(vecReg[pos - 1]);
	//fout << vecReg[pos - 1].login << ' ' << vecReg[pos - 1].password << ' ' << vecReg[pos - 1].role << std::endl;
	vecReg.erase(vecReg.begin() + pos - 1);
	AccessReg();
	system("pause");
	system("cls");
}

void printConsole(std::vector<User> vecAcc) { //Вывод в консоль
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 40, y = 4;
	std::cout << std::endl << std::endl;
	std::cout << std::setw(82) << "=========================================\n";
	std::cout << std::setw(82) << "|              Логин          Роль      |\n";
	for (auto i = 0U; i < vecAcc.size(); i++) {
		GoToXY(hStdOut, x, y++);
		printf("|%2d. %15s %14s     |\n", i + 1, vecAcc[i].login.c_str(), (vecAcc[i].role == 1) ? "Админ" : "Польз.");
	}
	std::cout << std::setw(83) << "=========================================\n\n";
}

User::~User() = default;