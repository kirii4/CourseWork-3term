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

//���� ������������
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
	std::string Menu[] = { "\t���� ������������",
							"",
							"",
							"1.��� �������.",
							"2.�������� �����.",
							"3.����� �� �������." };
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
			std::cout << "����� �� �������.\n";
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
				std::cout << "\n����� �� ���������.\n";
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
				std::cout << "������ �����!\n";
				break;
			}
		}
	}
#else
	int menu = 0;
	while (menu != 3) {
		system("cls");
		std::cout << "\t ���� ������������\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.��� �������.\n"
			"2.�������� �����.\n"
			"3.����� �� �������.\n";
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
			std::cout << "\n����� �� ���������.\n";
			Order::fileOutputBasket(order);
			Client::accFileOutput(account);
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "\n������ �����!!\n";
			break;
		}
	}
#endif // !KEYBOARD

}

void DataMenu(std::vector<Shop>& vecShop, std::vector<Order>& vecOrd, std::vector<Client>& vecClient) {

#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "     ���� ������ � �������",
		"",
		"",
		"1.������ � ������� ���������.",
		"2.������ � ������� �������.",
		"3.������ � ������� ��������.",
		"4.��������� � ������� ����." };
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
			std::cout << "����� �� �������.\n";
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
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 4) {
		system("cls");
		std::cout << "     ���� ������ � �������\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.������ � ������� ���������.\n"
			"2.������ � ������� �������.\n"
			"3.������ � ������� ��������.\n"
			"4.��������� � ������� ����.\n";
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
			std::cout << "������ �����!!\n";
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
	std::string Menu[] = { "\t���� ������",
							"",
							"",
							"1.������ � ����������.",
							"2.������ � �������.",
							"3.����� �� �������." };
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
			std::cout << "����� �� �������.\n";
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
				std::cout << "\n����� �� �������.\n";
				User::fileOutputReg(vecReg);
				User::fileOutputUser(vecAcc);
				Shop::fileOutput(vecShop);
				Order::fileOutput(vecOrd);
				Client::fileOutput(vecClient);
				exit(0);
				break;
			}
			default:
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else
	int menu = 0;
	while (menu != 3) {
		system("cls");
		std::cout << "\t\t ���� ������\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.������ � ����������.\n" //1.�������� ������ �� �����������
			"2.������ � �������.\n"
			"3.����� �� �������.\n";
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
			std::cout << "\n����� �� �������.\n";
			User::fileOutputReg(vecReg);
			User::fileOutputUser(vecAcc);
			Shop::fileOutput(vecShop);
			Order::fileOutput(vecOrd);
			Client::fileOutput(vecClient);
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "������ �����!!\n";
			break;
		}
	}
#endif // KEYBOARD
}

void AccMenu(std::vector<User>& vecReg, std::vector<User>& vecUser, std::string& login) {
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\t���� ������ � ����������",
							"",
							"",
							"1.�������� ������ �� �����������.",
							"2.�������� ������� �������.",
							"3.�������� ������� �������.",
							"4.������� ������ ��� ����� ������� ������.",
							"5.��������� � ������� ����." };

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
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 5) {
		system("cls");
		std::cout << "\t���� ������ � ����������\n"
			<< "=============================================\n\n";
		std::cout << "1.�������� ������ �� �����������.\n"
			"2.�������� ������� �������.\n"
			"3.�������� ������� �������.\n"
			"4.������� ������ ��� ����� ������� ������.\n"
			"5.��������� � ������� ����.\n";
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
			std::cout << "������ �����!!\n";
			break;
		}
	}
#endif // KEYBOARD
}

void User::fileInputReg(std::vector<User>& vecUser) {
	std::ifstream f_in(fileReg);

	if (!f_in.is_open()) {
		std::cout << "\n������ �������� �����!" << std::endl;
		exit(0);
	}
	else {
		User n;
		while (f_in >> n) {//������ �� ����� � ������
			if (vecUser.size() >= MAX_VECTOR_SIZE && vecUser[149].getLogin() != "None") {
				std::cout << "\n\n���������� ����������� ������!!!.\n";
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
		std::cout << "\n������ �������� �����!" << std::endl;
		exit(0);
	}
	else {
		User n;
		while (f_in >> n) {//������ �� ����� � ������
			if (vecUser.size() >= MAX_VECTOR_SIZE && vecUser[149].getLogin() != "None") {
				std::cout << "\n\n���������� ����������� ������!!!.\n";
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
		std::cout << "\n������ �������� �����!" << std::endl;
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
		std::cout << "\n������ �������� �����!" << std::endl;
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
	User << "admin " << 16559146482384667732 << ' ' << 1; //���������� ����� ��������� �������� ������
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
	std::string Menu[] = { "����� ����������!",
							"",
							"",
						   "1.����� � �������.",
						   "2.������� �������.",
						   "3.�����." };
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
			std::cout << "����� �� �������.\n";
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
				std::cout << "����� �� �������.\n";
				isG = false;
				break;
			}
			default:
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else
	std::cout << "\t����� ����������!" << std::endl
		<< "1.����� � �������." << std::endl
		<< "2.������� �������." << std::endl
		<< "3.�����." << std::endl;
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
		std::cout << "����� �� �������.\n";
		break;
	default:
		std::cout << "������ �����!\n";
		break;
	}

#endif // KEYBOARD
	return {};
}

int User::sign_in(std::string& login) {  //���� � �������
	std::ifstream acc(fileAcc);
	if (!acc.is_open()) {
		User::createAdmin();
	}
	acc.close();
	acc.open(fileAcc);
	int try_ = 0; // ���������� �������(�������� 3)
	bool user = false;
	User obj;
	std::string _login, _password; int _role; //1 - �����, 0 - ������������
	system("cls");
	while (true) {
		std::cout << "\t�����������" << std::endl;
		std::cout << "==============================" << std::endl << std::endl;
		std::cout << "������� �����:" << std::endl;
		//if (try_ == 0) getchar();
		getline(std::cin, _login);
		obj.setLogin(_login);
		std::cout << "������� ������:" << std::endl;
		star(obj);
		std::hash<std::string> salt;
		obj.setPassword(std::to_string(salt(obj.getPassword()))); //�������� ��������� ������

		while (acc >> _login && acc >> _password && acc >> _role) {
			if (_login == obj.getLogin() && _password == obj.getPassword()) { //������ � ������� ����� - ������� �� ����� �������� �� �����
				user = true;
				break;
			}
		}


		if (user) { //���� ����� � ������ ������� ��������� � ����
			login = obj.getLogin();
			if (_role == 1) {
				return 1; //��� ������
			}
			else {
				return 0; //��� ������������
			}
		}
		else {
			acc.clear(); //������� ��������� �� ������ �����
			acc.seekg(0);
			try_++;
			system("cls");
			std::cout << "������ ��� ����� ������������!!!\n\n";
			if (try_ == 1) std::cout << "� ��� �������� " << 3 - try_ << " �������!!!\n\n"; // �������� 2 �������
			else std::cout << "� ��� �������� " << 3 - try_ << " �������!!!\n\n"; // �������� 1 �������
			if (try_ == 3) {           //�������� ������
				std::cout << "\n������ �����!!!\n";
				exit(0);
			}
		}
	}
}

void star(User& obj) {
	obj.setPassword("");
	int ch = 0;
	while (true) {              // ������ ������ ��� ����� �� ��������� (*)
		ch = _getch();        // �������� ��� ������� ������� � ����������.
		if (ch == 13) {         // ��������� Enter �� ���������� �����.
			break;         // ���������� �����.
		}
		if (ch == 27) {   // Esc - ����� ���������
			exit(0);
		}
		if (ch == 8) {    //Backspace
			std::cout << (char)8 << ' ' << char(8); //�������� ������� �� ���� ������� �����, ����� ������� �
													// ����� �������� ������� ����� (��� ������� Backspace
													// ������ ����� ���������, � ������ ������������).
			if (!obj.getPassword().empty()) //���� ������ pass �� �������� ������, �� �� ��
									//����� ������� ��������� ������ (����� ����������� �������.
				obj.getPassword().erase(obj.getPassword().length() - 1); // ��������� ������� ��������� ������ �� ������ pass
		}
		else {
			std::cout << '*';            // ������ �������� �� *
			obj.plusPasswordSymb((char)ch);       // ��� �� ������ ����� -> ������.
		}
	}
}

void registrMenu(std::vector<User>& vecAcc, std::vector<User>& vecReg) {

	if (vecReg.empty()) {
		system("cls");
		std::cout << "�������� ��� ����������� ���.\n\n";
		system("pause");
	}
	else {
#ifdef KEYBOARD

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursorVisible(hStdOut, false, 100);
		std::string Menu[] = { "���� ������ � ������������",
								"",
								"",
							   "1.���������� ������� �� �����������.",
							   "2.��������� � ������� ����." };
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
					std::cout << "������ �����!\n";
					break;
				}
			}
		}

#else
		int menu = 0;
		while (menu != 2) {
			system("cls");
			std::cout << "\t���� ������ � ������������\n"
				<< "==========================================\n\n";
			std::cout << "1.���������� ������� �� �����������.\n"
				<< "2.��������� � ������� ����.\n";
			Check::checkInt(menu);
			if (vecReg.empty() && menu == 1) {
				system("cls");
				std::cout << "�������� ��� ����������� ���.\n\n";
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
						std::cout << "������ �����!!\n";
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
	std::cout << "�������� ����� ���� ��� ���������: ";
	int pos;
	Check::checkInt(pos);
	std::cout << "1. ����������� �����������.\n"
		<< "2. ��������� �����������.\n";
	Check::checkInt(reg);
	switch (reg) {
	case 1:
		system("cls");
		finishReg(vecAcc, vecReg, pos);
		break;
	case 2:
		system("cls");
		std::cout << "�������� ������ ������!\n"
			<< "����������� ��������(y/n): ";
		getchar();
		Check::checkDel(val);
		if (val == "n" || val == "N") {
			std::cout << "\n�������� ��������!\n\n";
			break;
		}
		else {
			vecReg.erase(vecReg.begin() + pos - 1);
			AccessDelete();
			break;
		}
	default:
		std::cout << "������ �����!!\n";
		break;
	}
}

void registration(std::vector<User>& vecAcc, std::vector<User>& vecReg, std::string typeReg) {
	User obj;
	int try_ = 0;
	bool bLogin = false;
	system("cls");
	while (try_ != 3) {
		std::cout << "������� �����: " << std::endl;
		getline(std::cin, obj.login);
		if (obj.login.size() < 3) {
			std::cout << std::endl << "����������� ����� ������ 4 �������." << std::endl;
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
			std::cout << "������ ����� ��� �����.\n";
			try_++;
			bLogin = false;
		}
		else {
			break;
		}
		if (try_ == 3) {
			std::cout << "��������� ������� �����������\n";
		}
	}

	if (try_ != 3) {
		try_ = 0;
		enterRegPass(try_, vecAcc, obj);
		if (try_ == 3) {
			std::cout << std::endl << "��������� ������� �����������.\n";
		}
		else {
			std::cout << std::endl << "������� ���� ������� ��������(0 - ������������, 1 - �����):\n";
			Check::checkWork(obj.role);

			std::string file = "registration.txt";
			std::ofstream fReg(file, std::ios_base::out | std::ios_base::app);
			User::printFile(obj, fReg);
			std::cout << "����������� ���������.\n";
			vecReg.push_back(obj);
			fReg.close();
			if (typeReg == "reg") {
				std::cout << "�������� ������������� ����������� �������!\n";
			}
		}
	}
}

void enterRegPass(int& try_, std::vector<User>& vecAcc, User& obj) {
	User _obj;
	bool bPassword = false;
	while (try_ != 3) {
		std::cout << "������� ������: " << std::endl;
		UserPassword(obj);
		if (obj.getPassword().size() <= 3) {
			std::cout << std::endl << "����������� ����� ������ 4 �������.\n";
			try_++;
			continue;
		}
		std::cout << std::endl << "��������� ������: " << std::endl;
		UserPassword(_obj);

		if (_obj.getPassword().size() <= 3) {
			std::cout << std::endl << "����������� ����� ������ 4 �������.\n";
			try_++;
			continue;
		}

		if (obj.getPassword() != _obj.getPassword()) {
			std::cout << std::endl << "������ �� ���������!\n";
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
			std::cout << std::endl << "������ ������ �� ��������.\n";
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
				std::cout << std::endl << "������ �����(�������� ������ ������)." << std::endl;
				break;
				error = true;
			}
		}
	} while (error);
}

void delAcc(std::vector<User>& vecAcc, std::string& login) {
	if (vecAcc.size() == 0) std::cout << std::endl << "������ ����." << std::endl << std::endl;
	else {
		std::cout << "������� ������ ���������� ����.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecAcc.size() || num < 0) std::cout << "\n�������� ���� ������!\n";
			else if (vecAcc[num].getLogin() == login) {
				std::cout << "\t������\n�� �� ������ ������� ����������� �������.\n	";
				break;
			}
			else {
				std::string val;
				std::cout << "\n�� �������� ������� ����(y/n): \n";
				getchar();
 				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\n�������� ��������!\n\n";
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

void printConsole(std::vector<User> vecAcc) { //����� � �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 40, y = 4;
	std::cout << std::endl << std::endl;
	std::cout << std::setw(82) << "=========================================\n";
	std::cout << std::setw(82) << "|              �����          ����      |\n";
	for (auto i = 0U; i < vecAcc.size(); i++) {
		GoToXY(hStdOut, x, y++);
		printf("|%2d. %15s %14s     |\n", i + 1, vecAcc[i].login.c_str(), (vecAcc[i].role == 1) ? "�����" : "�����.");
	}
	std::cout << std::setw(83) << "=========================================\n\n";
}

User::~User() = default;