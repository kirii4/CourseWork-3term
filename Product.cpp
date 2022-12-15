//#include "Product.h"
#include "Order.h"

Product::Product()
{
	this->name = "None";
	this->ID = "None";
	this->price = 0;
}

Product::Product(const Product& obj)
{
	this->ID = obj.ID;
	this->name = obj.name;
	this->price = obj.price;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setID(std::string ID)
{
	this->ID = ID;
}

void Product::setName(std::string name)
{
	this->name = name;
}

double Product::getPrice()
{
	return price;
}

std::string Product::getID()
{
	return ID;
}

std::string Product::getName()
{
	return name;
}

Product& Product::operator=(const Product& obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->ID = obj.ID;
		this->price = obj.price;
	}
	return *this;
}

void Product::DataMenu(std::vector<Product>& vecProduct)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "     ���� ������ � �������������",
							"",
							"",
							"1.����������� �����������.\n",
							"2.�������� �����.",
							"3.������� �����.",
							"4.�������������� ������.",
							"5.����� ������.",
							"6.���������� ������������.",
							"7.��������� � ����." };
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecProduct.size() == 0) {
					system("cls");
					std::cout << std::endl << "������ ����." << std::endl << std::endl;
				}
				else {
					Product::print(vecProduct);
				}
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::add(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::del(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 4:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecProduct.size() == 0) {
					std::cout << std::endl << "������ ����." << std::endl << std::endl;
				}
				else {
					Product::print(vecProduct);
					Product::edit(vecProduct);
				}
				system("pause");
				aT = 3;
				break;
			case 5:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::findMenu(vecProduct);
				system("pause");
				aT = 3;
				break;
			case 6:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::sortMenu(vecProduct);
				system("pause");
				aT = 3;
				break;
			case 7:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 7) {
		system("cls");
		std::cout << "\t���� ������ � �������������\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.����������� �����������.\n"
			"2.�������� �����.\n"
			"3.������� �����.\n"
			"4.�������������� ������.\n"
			"5.����� ������.\n"
			"6.���������� ������������.\n"
			"7.��������� � ����.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecProduct.size() == 0) {
				std::cout << std::endl << "������ ����." << std::endl << std::endl;
			}
			else {
				Product::print(vecProduct);
			}
			system("pause");
			break;
		case 2:
			system("cls");
			Product::add(vecProduct);
			system("pause");
			break;
		case 3:
			system("cls");
			Product::del(vecProduct);
			system("pause");
			break;
		case 4:
			system("cls");
			if (vecProduct.size() == 0) {
				std::cout << std::endl << "������ ����." << std::endl << std::endl;
			}
			else {
				Product::print(vecProduct);
				Product::edit(vecProduct);
			}
			system("pause");
			break;
		case 5:
			system("cls");
			Product::findMenu(vecProduct);
			system("pause");
			break;
		case 6:
			system("cls");
			Product::sortMenu(vecProduct);
			system("pause");
			break;
		case 7:
			system("cls");
			isG = false;
			break;
		default:
			system("cls");
			std::cout << "������ �����!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Product::BasketDataMenu(std::vector<Product>& vecProduct)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\t���� ������ � �������������",
							"",
							"",
							"1.����������� �����������.",
							"2.����� ������.",
							"3.C��������� ������������.",
							"4.��������� � ����." };
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecProduct.size() == 0) {
					std::cout << std::endl << "������ ����." << std::endl << std::endl;
				}
				else {
					Product::print(vecProduct);
				}
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::findMenu(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::sortMenu(vecProduct);
				system("pause");
				break;
			}
			case 4:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
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
		std::cout << "\t���� ������ � �������������\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.����������� �����������.\n"
			"2.����� ������.\n"
			"3.���������� ������������.\n"
			"4.��������� � ����.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecProduct.size() == 0) {
				std::cout << std::endl << "������ ����." << std::endl << std::endl;
			}
			else {
				Product::print(vecProduct);
			}
			system("pause");
			break;
		case 2:
			system("cls");
			Product::findMenu(vecProduct);
			system("pause");
			break;
		case 3:
			system("cls");
			Product::sortMenu(vecProduct);
			system("pause");
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

void Product::print(std::vector<Product>& s)
{
	system("cls");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 30, y = 4;
	std::cout << std::endl;
	std::cout << std::setw(91) << "+-----------------------------------------------------------+" << std::endl;
	std::cout << std::setw(91) << "|      ID                 ��������              ����        |" << std::endl;
	std::cout << std::setw(91) << "+-----------------------------------------------------------+" << std::endl;
	for (auto i = 0; i < s.size(); i++) {
		GoToXY(hStdOut, x, y++);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("|%10s   %21s  %16.2lf BYN   |\n",
			s[i].getID().c_str(), s[i].getName().c_str(), s[i].getPrice());
	}
	std::cout << std::setw(91) << "+-----------------------------------------------------------+" << std::endl << std::endl << std::endl;
}

void Product::add(std::vector<Product>& vecProduct)
{
	system("cls");
	if (vecProduct.size() >= MAX_VECTOR_SIZE) std::cout << "���������� ����������� ������!!!\n";
	else {
		std::string ID, name;
		double price;
		std::cout << "������� ID ������ (5 �����): \n";
		bool val = true;
		do {
			getchar();
			Check::checkID(ID);
			if (Product::checkIDProduct(ID, vecProduct)) {
				val = false;
			}
			else {
				std::cout << "������ ����� ��� ������� � ����.\n";
			}
		} while (val);
		Product s;
		std::cout << "������� �������� ������: ";
		Check::checkString(name);
		std::cout << "������� ���� (BYN):\n";
		Check::checkDouble(price);
		s.setID(ID);
		s.setName(name);
		s.setPrice(price);
		vecProduct.push_back(s);
		AccessAdd();
	}
}

void Product::del(std::vector<Product>& vecProduct)
{
	if (vecProduct.size() == 0) std::cout << std::endl << "������ ����." << std::endl << std::endl;
	else {
		Product::print(vecProduct);
		std::cout << "������� ������ ���������� ����.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecProduct.size() || num < 0) std::cout << "\n�������� ���� ������!\n";
			else {
				std::string val;
				std::cout << "\n�� �������� ������� ����(y/n): \n";
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\n�������� ��������!\n\n";
					break;
				}
				else {
					vecProduct.erase(vecProduct.begin() + num);
					AccessDelete();
					break;
				}
			}
		}
	}
}

void Product::findMenu(std::vector<Product>& vecProduct)
{
	system("cls");
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "   ���� ������",
							"",
							"",
							"1.����� �� ID.",
							"2.����� �� ��������.",
							"3.��������� � ����." };
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
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				findID(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				findName(vecProduct);
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
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 3) {
		system("cls");
		std::cout << "\t\t���� ������\n"
			<< "=============================================\n\n";
		std::cout << "1.����� �� ID.\n"
			"2.����� �� ��������.\n"
			"3.��������� � ����.\n";

		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			findID(vecProduct);
			system("pause");
			break;
		case 2:
			system("cls");
			findName(vecProduct);
			system("pause");
			break;
		case 3:
			break;
		default:
			system("cls");
			std::cout << "������ �����!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Product::findID(std::vector<Product>& vecProduct) {
	system("cls");
	std::cout << "������� ID ������: ";
	std::string ID;
	//Check::checkID(ID);
	getline(std::cin, ID);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0; i < vecProduct.size(); i++) {
		if (vecProduct[i].getID().find(ID) != std::string::npos) {
			printSoloProduct(vecProduct[i], k);
		}
	}
	if (k == 0) {
		std::cout << "������ �� ������������ ID �� �������!\n";
	}
}

void Product::findName(std::vector<Product>& vecProduct) {
	system("cls");
	std::cout << "������� �������� ������: ";
	std::string name;
	//Check::checkString(name);
	getchar();
	getline(std::cin, name);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0U; i < vecProduct.size(); i++) {
		if (vecProduct[i].getName().find(name) != std::string::npos) {
			printSoloProduct(vecProduct[i], k);
		}
	}
	if (k == 0) {
		std::cout << "������ �� ������������ �������� �� �������!\n";
	}
}

void Product::sortMenu(std::vector<Product>& vecProduct)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\t���� ����������",
							"",
							"",
							"1.������������� �� ������ ������.",
							"2.������������� �� ��������.",
							"3.������������� �� ���� (�����������).",
							"4.��������� � ����." };
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
				Product::IDSort(vecProduct);
				std::cout << "���������� �� ������ ������.";
				GoToXY(hStdOut, x, 2);
				Product::print(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::AlphSort(vecProduct);
				std::cout << "���������� �� ��������.";
				GoToXY(hStdOut, x, 2);
				Product::print(vecProduct);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Product::priceSort(vecProduct);
				std::cout << "���������� �� ����(�����������).";
				GoToXY(hStdOut, x, 2);
				Product::print(vecProduct);
				system("pause");
				break;
			}
			case 4:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				isG = false;
				break;
			default:
				std::cout << "������ �����!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	std::cout << "\t���� ����������\n"
		<< "==================================\n\n";
	while (menu != 4) {
		std::cout << "1.������������� �� ������ ������.\n"
			"2.������������� �� ��������.\n"
			"3.������������� �� ���� (�����������).\n"
			"4.��������� � ����.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Product::IDSort(vecProduct);
			std::cout << "\t\t" << "���������� �� ������ ������." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 2:
			system("cls");
			Product::AlphSort(vecProduct);
			std::cout << "\t\t" << "���������� �� ��������." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 3:
			system("cls");
			Product::priceSort(vecProduct);
			std::cout << "\t\t" << "���������� �� ����(�����������)." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 4:
			system("cls");
			break;
		default:
			std::cout << "\n������ �����!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Product::printSoloProduct(Product& product, int& k)
{
	k++;
	printf("|%5s.  %-23s  %16.2lf BYN |\n",
		product.getID().c_str(), product.getName().c_str(), product.getPrice());
}

bool Product::checkIDProduct(std::string ID, std::vector<Product>& vecProduct)
{
	bool check = false;
	for (auto i = 0U; i < vecProduct.size(); i++) {
		if (vecProduct[i].getID() == ID) {
			check = true;
		}
	}
	if (check) {
		return false;
	}
	else {
		return true;
	}
}

void Product::IDSort(std::vector<Product>& vecProduct)
{
	if (vecProduct.size() == 0) {
		std::cout << std::endl << "������ ����." << std::endl << std::endl;
	}
	else {
		std::sort(vecProduct.begin(), vecProduct.end(), [](Product prod1, Product prod2) {
			return prod1.getID() < prod2.getID();
			});
	}
}

void Product::AlphSort(std::vector<Product>& vecProduct)
{
	if (vecProduct.size() == 0) {
		std::cout << std::endl << "������ ����." << std::endl << std::endl;
	}
	else {
		std::sort(vecProduct.begin(), vecProduct.end(), [](Product prod1, Product prod2) {
			return prod1.getName() < prod2.getName();
			});
	}
}

void Product::priceSort(std::vector<Product>& vecProduct)
{
	if (vecProduct.size() == 0) {
		std::cout << std::endl << "������ ����." << std::endl << std::endl;
	}
	else {
		std::sort(vecProduct.begin(), vecProduct.end(), [](Product prod1, Product prod2) {
			return prod1.getPrice() < prod2.getPrice();
			});
	}
}

void Product::edit(std::vector<Product>& vecProduct)
{
	if (vecProduct.size() == 0) {
		std::cout << std::endl << "������ ����." << std::endl << std::endl;
	}
	else {
		std::cout << "������� ID �������� ��� ���������.\n";
		bool val = true;
		std::string ID;
		do {
			getchar();
			Check::checkID(ID);
			if (!Product::checkIDProduct(ID, vecProduct)) {
				val = false;
			}
			else {
				std::cout << "������ ����� �� ������.\n";
			}
		} while (val);
		std::cout << "��������:\n"
			"1.ID.\n"
			"2.��������.\n"
			"3.����.\n";
		int menu;
		std::string name;
		double price;
		auto it = std::find_if(vecProduct.begin(), vecProduct.end(), [ID](Product product) { return product.getID() == ID; });
		Check::checkInt(menu);
		std::cout << "������� ��������: ";
		switch (menu) {
		case 1: //��������� �������
			std::cout << (*it).getID() << ".\n"
				<< "������� ����� ��������: ";
			Check::checkID(ID);
			(*it).setID(ID);
			break;
		case 2: //��������� ����� 
			std::cout << (*it).getName() << ".\n"
				<< "������� ����� ��������: ";
			getchar();
			Check::checkString(name);
			(*it).setName(name);
			break;
		case 3: //��������� �������� 
			std::cout << (*it).getPrice() << ".\n"
				<< "������� ����� ��������: ";
			Check::checkDouble(price);
			(*it).setPrice(price);
			break;
		default:
			std::cout << "������ �����!!\n";
			break;
		}
		AccessEdit();
	}
}

Product::~Product()
{

}

std::ostream& operator<<(std::ostream& os, Product& obj)
{
	os << obj.ID << ' ' << obj.name << ' ' << obj.price;
	return os;
}

std::istream& operator>>(std::istream& is, Product& obj)
{
	is >> obj.ID >> obj.name >> obj.price;
	return is;
}
