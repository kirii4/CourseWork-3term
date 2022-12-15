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
	std::string Menu[] = { "     Меню работы с ассортиментом",
							"",
							"",
							"1.Просмотреть ассортимент.\n",
							"2.Добавить товар.",
							"3.Удалить товар.",
							"4.Корректировать данные.",
							"5.Поиск товара.",
							"6.Сортировка ассортимента.",
							"7.Вернуться в меню." };
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
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	while (menu != 7) {
		system("cls");
		std::cout << "\tМеню работы с ассортиментом\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.Просмотреть ассортимент.\n"
			"2.Добавить товар.\n"
			"3.Удалить товар.\n"
			"4.Корректировать данные.\n"
			"5.Поиск товара.\n"
			"6.Сортировка ассортимента.\n"
			"7.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecProduct.size() == 0) {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
			std::cout << "Ошибка ввода!!\n";
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
	std::string Menu[] = { "\tМеню работы с ассортиментом",
							"",
							"",
							"1.Просмотреть ассортимент.",
							"2.Поиск товара.",
							"3.Cортировка ассортимента.",
							"4.Вернуться в меню." };
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
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else 

	int menu = 0;
	while (menu != 4) {
		system("cls");
		std::cout << "\tМеню работы с ассортиментом\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.Просмотреть ассортимент.\n"
			"2.Поиск товара.\n"
			"3.Сортировка ассортимента.\n"
			"4.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecProduct.size() == 0) {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
			std::cout << "Ошибка ввода!!\n";
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
	std::cout << std::setw(91) << "|      ID                 Название              Цена        |" << std::endl;
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
	if (vecProduct.size() >= MAX_VECTOR_SIZE) std::cout << "Превышение размерности списка!!!\n";
	else {
		std::string ID, name;
		double price;
		std::cout << "Введите ID товара (5 чисел): \n";
		bool val = true;
		do {
			getchar();
			Check::checkID(ID);
			if (Product::checkIDProduct(ID, vecProduct)) {
				val = false;
			}
			else {
				std::cout << "Данный товар уже имеется в базе.\n";
			}
		} while (val);
		Product s;
		std::cout << "Введите название товара: ";
		Check::checkString(name);
		std::cout << "Введите цену (BYN):\n";
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
	if (vecProduct.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		Product::print(vecProduct);
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecProduct.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
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
	std::string Menu[] = { "   Меню поиска",
							"",
							"",
							"1.Поиск по ID.",
							"2.Поиск по названию.",
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
		std::cout << "1.Поиск по ID.\n"
			"2.Поиск по названию.\n"
			"3.Вернуться в меню.\n";

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
			std::cout << "Ошибка ввода!!\n";
			break;
		}
	}

#endif // KEYBOARD
}

void Product::findID(std::vector<Product>& vecProduct) {
	system("cls");
	std::cout << "Введите ID товара: ";
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
		std::cout << "Товары по запрошенному ID не найдено!\n";
	}
}

void Product::findName(std::vector<Product>& vecProduct) {
	system("cls");
	std::cout << "Введите название товара: ";
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
		std::cout << "Товары по запрошенному названию не найдено!\n";
	}
}

void Product::sortMenu(std::vector<Product>& vecProduct)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню сортировки",
							"",
							"",
							"1.Отсортировать по номеру товара.",
							"2.Отсортировать по алфавиту.",
							"3.Отсортировать по цене (возрастание).",
							"4.Вернуться в меню." };
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
				std::cout << "Сортировка по номеру товара.";
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
				std::cout << "Сортировка по алфавиту.";
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
				std::cout << "Сортировка по цене(возрастание).";
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
				std::cout << "Ошибка ввода!\n";
				break;
			}
		}
	}

#else

	int menu = 0;
	std::cout << "\tМеню сортировки\n"
		<< "==================================\n\n";
	while (menu != 4) {
		std::cout << "1.Отсортировать по номеру товара.\n"
			"2.Отсортировать по алфавиту.\n"
			"3.Отсортировать по цене (возрастание).\n"
			"4.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Product::IDSort(vecProduct);
			std::cout << "\t\t" << "Сортировка по номеру товара." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 2:
			system("cls");
			Product::AlphSort(vecProduct);
			std::cout << "\t\t" << "Сортировка по алфавиту." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 3:
			system("cls");
			Product::priceSort(vecProduct);
			std::cout << "\t\t" << "Сортировка по цене(возрастание)." << std::endl << std::endl;
			Product::print(vecProduct);
			break;
		case 4:
			system("cls");
			break;
		default:
			std::cout << "\nОшибка ввода!!\n";
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
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::cout << "Введите ID элемента для изменения.\n";
		bool val = true;
		std::string ID;
		do {
			getchar();
			Check::checkID(ID);
			if (!Product::checkIDProduct(ID, vecProduct)) {
				val = false;
			}
			else {
				std::cout << "Данный товар не найден.\n";
			}
		} while (val);
		std::cout << "Изменить:\n"
			"1.ID.\n"
			"2.Название.\n"
			"3.Цену.\n";
		int menu;
		std::string name;
		double price;
		auto it = std::find_if(vecProduct.begin(), vecProduct.end(), [ID](Product product) { return product.getID() == ID; });
		Check::checkInt(menu);
		std::cout << "Текущее значение: ";
		switch (menu) {
		case 1: //изменение фамилии
			std::cout << (*it).getID() << ".\n"
				<< "Введите новое значение: ";
			Check::checkID(ID);
			(*it).setID(ID);
			break;
		case 2: //изменение имени 
			std::cout << (*it).getName() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(name);
			(*it).setName(name);
			break;
		case 3: //изменение отчества 
			std::cout << (*it).getPrice() << ".\n"
				<< "Введите новое значение: ";
			Check::checkDouble(price);
			(*it).setPrice(price);
			break;
		default:
			std::cout << "Ошибка ввода!!\n";
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
