#include "Order.h"

Order::Order() : ID("None")
{
}

void Order::setID(std::string ID)
{
	this->ID = ID;
}

void Order::setProduct(Product product)
{
	this->product.push_back(product);
}

void Order::setLogin(std::string login)
{
	this->login = login;
}

void Order::setAddress(std::string address)
{
	this->address = address;
}

std::string Order::getID()
{
	return ID;
}

std::vector<Product>& Order::getProduct()
{
	return product;
}

Date Order::getDate()
{
	return date;
}

std::string Order::getLogin()
{
	return login;
}

std::string Order::getAddress()
{
	return address;
}

int Order::getCount()
{
	return count;
}

void Order::clearProduct()
{
	product.clear();
}

Order::Order(const Order& obj)
{
	this->ID = obj.ID;
	this->login = obj.login;
	this->address = obj.address;
	this->product = obj.product;
	this->date = obj.date;
}

Order& Order::operator=(const Order& obj)
{
	if (this != &obj) {
		this->ID = obj.ID;
		this->login = obj.login;
		this->address = obj.address;
		this->product = obj.product;
		this->date = obj.date;
	}
	return *this;
}

void Order::print(std::vector<Order>& vecOrd)
{
	system("cls");
	std::cout << std::endl << std::endl;
	std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl;
	std::cout << std::setw(101) << "|      ID     |   Логин  |       Адрес         Дата                 Содержание  |" << std::endl;
	std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl;
	for (auto& order : vecOrd) {
		printf("%20s|%10s.  |%9s |  %13s %4s.%s.%s %25s|\n", "", order.getID().c_str(), order.getLogin().c_str(),
			order.getAddress().c_str(), order.getDate().getDay().c_str(), order.getDate().getMonth().c_str(),
			order.getDate().getYear().c_str(), (order.getProduct().size() != 0) ? order.getProduct()[0].getName().c_str() : "None");
		for (int i = 1; i < order.getProduct().size(); i++) {
			std::cout << std::setw(21) << "|" << std::setw(14) << "|" << std::setw(11) << "|" << std::setw(54) << order.getProduct()[i].getName() << "|" << std::endl;;
		}
		std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl;
	}
}

void Order::add(Client& account, Order& order, std::vector<Shop>& vecShop) {
	std::string name;
	if (order.getAddress() == "None" && account.getAddress() != "None") {
		order.setAddress(account.getAddress());
	}
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню заказа еды",
							"",
							"",
							"1.Просмотреть корзину.",
							"2.Редактировать корзину.",
							"3.Просмотреть магазины.",
							"4.Выход." };
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
				if (order.getID() == "") {
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
				}
				else Order::printBasket(order);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Order::editBasket(order, vecShop);
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecShop.size() == 0) {
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
				}
				else {
					Shop::print(vecShop);
					std::cout << "Введите название магазина: ";
					std::cin >> name;
					if (!Shop::checkShopName(name, vecShop)) {
						auto it = std::find_if(vecShop.begin(), vecShop.end(),
							[name](Shop shop) { return shop.getShopName() == name; });
						Product::BasketDataMenu((*it).getProduct());
					}
					else std::cout << "Ошибка ввода." << std::endl;
				}
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
		std::cout << "\t Меню заказа еды\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.Просмотреть корзину.\n"
			"2.Редактировать корзину.\n"
			"3.Просмотреть магазины.\n"
			"4.Выход.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (order.getID() == "") {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
			}
			else Order::printBasket(order);
			system("pause");
			break;
		case 2:
			system("cls");
			Order::editBasket(order, vecShop);
			break;
		case 3:
			system("cls");
			if (vecShop.size() == 0) {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
			}
			else {
				Shop::print(vecShop);
				std::cout << "Введите название магазина: ";
				std::cin >> name;
				if (!Shop::checkShopName(name, vecShop)) {
					auto it = std::find_if(vecShop.begin(), vecShop.end(),
						[name](Shop shop) { return shop.getShopName() == name; });
					Product::BasketDataMenu((*it).getProduct());
				}
				else std::cout << "Ошибка ввода." << std::endl;
			}
			break;
		case 4:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "\nОшибка ввода!!\n";
			break;
		}
	}
#endif // KEYBOARD
}

void Order::del(std::vector<Order>& vecOrd)
{
	if (vecOrd.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		Order::print(vecOrd);
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecOrd.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				getchar();
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else {
					vecOrd[num].clearProduct();
					vecOrd.erase(vecOrd.begin() + num);
					AccessDelete();
					break;
				}
			}
		}
	}
}

void Order::edit(std::vector<Order>& vecOrd)
{
	std::cout << "Изменить:\n"
		"1.Список товаров.\n"
		"2.Назад.\n";
	int menu;
	Check::checkInt(menu);
	if (menu != 2) {
		std::cout << "Текущее значение: ";
		switch (menu) {
		case 1:
			/*std::cout << account.getSurname() << ".\n"
				<< "Введите новое значение: ";
			getchar();
			Check::checkString(surname);
			account.setSurname(surname);
			break;*/
		default:
			std::cout << "Ошибка ввода!!\n";
			break;
		}
		AccessEdit();
	}
}

void Order::find(std::vector<Order>& vecOrd)
{
	std::cout << "Введите ID заказа: ";
	std::string ID;
	getchar();
	//Check::checkID(ID);
	getline(std::cin, ID);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0; i < vecOrd.size(); i++) {
		if (vecOrd[i].getID().find(ID) != std::string::npos) {
			printSoloOrder(vecOrd[i], k);
		}
	}
	if (k == 0) {
		std::cout << "Заказы по запрошенному ID не найдены!\n";
	}
}

void Order::printBasket(Order& order)
{
	system("cls");
	std::cout << std::endl << std::endl;
	std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl;
	std::cout << std::setw(101) << "|      ID     |   Логин  |       Адрес         Дата                 Содержание  |" << std::endl;
	std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl;
	printf("%20s|%10s.  |%9s |  %13s %4s.%s.%s %24s|\n", "", order.getID().c_str(), order.getLogin().c_str(),
		order.getAddress().c_str(), order.getDate().getDay().c_str(), order.getDate().getMonth().c_str(),
		order.getDate().getYear().c_str(), (order.getProduct().size() != 0) ? order.getProduct()[0].getName().c_str() : "None");
	for (int i = 1; i < order.getProduct().size(); i++) {
		std::cout << std::setw(21) << "|" << std::setw(14) << "|" << std::setw(11) << "|" << std::setw(54) << order.getProduct()[i].getName() << "|" << std::endl;;
	}
	std::cout << std::setw(101) << "+-------------+----------+------------------------------------------------------+" << std::endl << std::endl;
	double sum = 0;
	for (auto& i : order.getProduct())
		sum += i.getPrice();
	std::cout << std::setw(39) << "Итоговая стоимость:" << std::setw(58) << sum << " BYN" << std::endl << std::endl;
}

void Order::editBasket(Order& order, std::vector<Shop>& vecShop)
{
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "\tМеню редактирования корзины",
							"",
							"",
							"1.Добавить товар.",
							"2.Удалить товар.",
							"3.Выход из корзины." };
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
				Order::addBasket(order, vecShop);
				system("pause");
				aT = 3;
				break;
			}
			case 2:
			{
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Order::delBasket(order);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
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
	std::string name;
	while (menu != 3) {
		system("cls");
		std::cout << "\t Меню редактирования корзины\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.Добавить товар.\n"
			"2.Удалить товар.\n"
			"3.Выход.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Order::addBasket(order, vecShop);
			system("pause");
			break;
		case 2:
			system("cls");
			Order::delBasket(order);
			system("pause");
			break;
		case 3:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "\nОшибка ввода!!\n";
			break;
		}
	}
#endif // KEYBOARD
}

void Order::fileInputBasket(Order& order, std::string& _login)
{
	std::ifstream f_in(fileOrder);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		std::string ID, login, address, day, month, year;
		while (f_in >> ID >> login >> address >> day >> month >> year) {//Запись из файла в вектор
			Product prod;

			if (login[login.size() - 1] == '_') {
				login.erase(login.end() - 1);
				if (login == _login) {
					order.setID(ID);
					order.setLogin(login);
					std::replace(address.begin(), address.end(), '_', ' ');
					order.setAddress(address);
					order.getDate().setDay(day);
					order.getDate().setMonth(month);
					order.getDate().setYear(year);
				}
				continue;
			}
			if (login == _login) {
				order.setID(ID);
				order.setLogin(login);
				std::replace(address.begin(), address.end(), '_', ' ');
				order.setAddress(address);
				order.getDate().setDay(day);
				order.getDate().setMonth(month);
				order.getDate().setYear(year);
				while (f_in >> prod) {
					std::string val = prod.getName();
					std::replace(val.begin(), val.end(), '_', ' ');
					prod.setName(val);
					if (prod.getName()[prod.getName().size() - 1] == ' ') {
						std::string val = prod.getName();
						val.erase(val.end() - 1);
						prod.setName(val);
						order.setProduct(prod);
						break;
					}
					else order.setProduct(prod);
				}
			}
			else while (f_in >> prod) {
				if (prod.getName()[prod.getName().size() - 1] == '_') {
					break;
				}
			}
		}
	}
	f_in.close();
}

void Order::fileOutputBasket(Order& order)
{
	std::vector<Order> vecOrd;
	Order::fileInput(vecOrd);

	bool isHere = false;
	for (int i = 0; i < vecOrd.size(); i++) {
		if (vecOrd[i].getLogin() == order.getLogin()) 
		{
			if (order.getAddress() != "None" && vecOrd[i].getAddress() == "None") {
				vecOrd[i].setAddress(order.getAddress());
			}
			vecOrd[i].clearProduct();
			isHere = true;
			for (auto& j : order.getProduct()) {
				std::string val = j.getName();
				std::replace(val.begin(), val.end(), ' ', '_');
				j.setName(val);
				vecOrd[i].setProduct(j);
			}
		}
	}
	Order::fileOutput(vecOrd);

	if (!isHere) {
		std::ofstream fout(fileOrder, std::ios_base::app);
		if (!fout.is_open()) {
			std::cout << "\nОшибка открытия файла!" << std::endl;
			exit(1);
		}
		else {
			fout.seekp(0, std::ios_base::end);
			fout << order.getID() << ' ' << order.getLogin();
			if (order.getProduct().size() == 0) { fout << "_ "; }
			else fout << " ";
			std::string str(order.getAddress());
			std::replace(str.begin(), str.end(), ' ', '_');
			order.setAddress(str);
			fout << order.getAddress() << ' ' << order.getDate().getDay() << ' ' << order.getDate().getMonth() << ' ' << order.getDate().getYear();
			fout << std::endl;
			for (int j = 0; j < order.getProduct().size(); j++) {
				if (j == order.getProduct().size() - 1) {
					std::string val = order.getProduct()[j].getName() + "_";
					order.getProduct()[j].setName(val);
				}
				fout << order.getProduct()[j] << std::endl;
			}
		}
		fout.close();
	}
}

void Order::createID(Order& order, Client& account)
{
	std::vector<Order> vecOrd;
	Order::fileInput(vecOrd);
	int val = rand() % 50000;
	std::string ID = std::to_string(val);
	while (!Order::checkIDOrder(ID, vecOrd)) { // ! - найден
		val = rand() % 50000;
		ID = std::to_string(val);
	}
	if (ID.size() == 1) ID = "0000" + ID;
	if (ID.size() == 2) ID = "000" + ID;
	if (ID.size() == 3) ID = "00" + ID;
	if (ID.size() == 4) ID = "0" + ID;
	order.setID(ID);
	order.setLogin(account.getLogin());
	order.setAddress(account.getAddress());
}

void Order::addBasket(Order& order, std::vector<Shop>& vecShop)
{
	std::string name;
	if (vecShop.size() == 0) { //проверка на непустоту списка магазинов
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		Shop::print(vecShop);
		std::cout << "Введите название магазина: ";
		std::cin >> name;
		if (!Shop::checkShopName(name, vecShop)) {
			auto it = std::find_if(vecShop.begin(), vecShop.end(),
				[name](Shop shop) { return shop.getShopName() == name; }); //поиск магазина по названию
			Product::print((*it).getProduct());
			std::cout << "Введите ID или название товара для добавления в корзину: ";
			std::cin >> name;
			auto itProd = std::find_if((*it).getProduct().begin(), (*it).getProduct().end(), [name](Product prod) {
				return prod.getID().find(name) != std::string::npos || prod.getName().find(name) != std::string::npos;
				}); //поиск товара по ID или названию
			if (itProd == (*it).getProduct().end()) {
				std::cout << "Товар не найден." << std::endl;
			}
			else {
				std::string val;
				std::cout << "Вы собираетесь добавить " << (*itProd).getName() << '.' << std::endl;
				std::cout << "\nВы согласны(y/n): \n";
				getchar();
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nДобавление отменено!\n\n";
				}
				else {
					order.setProduct((*itProd)); //Добавляем продукт в наш заказ
					AccessAdd();
				}
			}
		}
		else std::cout << "Ошибка ввода." << std::endl;
	}
}

void Order::delBasket(Order& order)
{
	system("cls");
	if (order.getProduct().size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		std::cout << "Содержимое корзины:" << std::endl;
		for (int i = 0; i < order.getProduct().size(); i++) {
			std::cout << i + 1 << ". " << order.getProduct()[i].getName() << ' ' << order.getProduct()[i].getPrice() << " BYN" << std::endl;
		}
		std::cout << "Введите номер элемента для удаления: ";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= order.getProduct().size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				getchar();
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else {
					std::vector<Product> vecProduct = order.getProduct();
					vecProduct.erase(vecProduct.begin() + num);
					order.clearProduct();
					for (auto& i : vecProduct) {
						order.setProduct(i);
					}
					AccessDelete();
					break;
				}
			}
		}
	}
}

void Order::printSoloOrder(Order& order, int& k)
{
	k++;
	printf("|%10s.  |%9s |  %13s %4s.%s.%s %25s|\n", order.getID().c_str(), order.getLogin().c_str(),
		order.getAddress().c_str(), order.getDate().getDay().c_str(), order.getDate().getMonth().c_str(),
		order.getDate().getYear().c_str(), (order.getProduct().size() != 0) ? order.getProduct()[0].getName().c_str() : "None");
	for (int i = 1; i < order.getProduct().size(); i++) {
		std::cout << "|" << std::setw(79) << order.getProduct()[i].getName() << "|" << std::endl;;
	}
}

bool Order::checkIDOrder(std::string ID, std::vector<Order>& vecOrd)
{
	bool check = false;
	for (auto i = 0; i < vecOrd.size(); i++) {
		if (vecOrd[i].getID() == ID) {
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

std::ostream& operator<<(std::ostream& os, Order& obj)
{
	os << obj.ID << ' ' << obj.login << ' ' << obj.address << ' ' << obj.date << std::endl;
	for (auto i : obj.product) {
		os << i << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Order& obj)
{
	is >> obj.ID >> obj.login >> obj.address >> obj.date;
	Product val;
	while (!is.eof()) {
		is >> val;
		obj.product.push_back(val);
	}
	return is;
}

void Order::DataMenu(std::vector<Order>& vecOrd)
{
#ifdef KEYBOARD
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "    Меню работы с данными заказов",
							"",
							"",
							"1.Просмотреть все доступные заказы.",
							"2.Удалить заказ.",
							"3.Вернуться в главное меню." };
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
				if (vecOrd.size() == 0) {
					system("cls");
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
				}
				else {
					Order::print(vecOrd);
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
				Order::del(vecOrd);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
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
	while (menu != 3) {
		system("cls");
		std::cout << "\tМеню работы с данными заказов.\n";
		std::cout << "===========================================\n\n";
		std::cout << "1.Просмотреть все доступные заказы.\n"
			//"2.Редактировать данные заказа.\n"
			"2.Удалить заказ.\n"
			"3.Вернуться в главное меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			Order::print(vecOrd);
			system("pause");
			break;
			/*case 2:
				system("cls");
				Order::edit(vecOrd);
				break;*/
		case 2:
			system("cls");
			Order::del(vecOrd);
			system("pause");
			break;
		case 3:
			system("cls");
			break;
		}
	}

#endif // KEYBOARD
}

void Order::fileInput(std::vector<Order>& vecOrd)
{
	std::ifstream f_in(fileOrder);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		std::string ID, login, address, day, month, year;
		while (f_in >> ID >> login >> address >> day >> month >> year) {//Запись из файла в вектор
			Order order;
			Product prod;
			if (vecOrd.size() >= MAX_VECTOR_SIZE) {
				std::cout << "\n\nПревышение размерности списка!!!.\n";
				break;
			}
			if (login[login.size() - 1] == '_') {
				login.erase(login.end() - 1);
				order.setID(ID);
				order.setLogin(login);
				order.setAddress(address);
				order.getDate().setDay(day);
				order.getDate().setMonth(month);
				order.getDate().setYear(year);
				vecOrd.push_back(order);
				continue;
			}
			order.setID(ID);
			order.setLogin(login);
			std::replace(address.begin(), address.end(), '_', ' ');
			order.setAddress(address);
			order.getDate().setDay(day);
			order.getDate().setMonth(month);
			order.getDate().setYear(year);
			while (f_in >> prod) {
				if (prod.getName()[prod.getName().size() - 1] == '_') {
					std::string val = prod.getName();
					val.erase(val.end() - 1);
					prod.setName(val);
					order.setProduct(prod);
					break;
				}
				else order.setProduct(prod);
			}
			vecOrd.push_back(order);
		}
	}
	f_in.close();
}

void Order::fileOutput(std::vector<Order>& vecOrd)
{
	std::ofstream fout(fileOrder, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		for (auto i = 0; i < vecOrd.size(); i++) {
			fout << vecOrd[i].getID() << ' ' << vecOrd[i].getLogin();
			if (vecOrd[i].getProduct().size() == 0) { fout << "_ "; }
			else fout << " ";
			std::string str(vecOrd[i].getAddress());
			std::replace(str.begin(), str.end(), ' ', '_');
			vecOrd[i].setAddress(str);
			fout << vecOrd[i].getAddress() << ' ' << vecOrd[i].getDate().getDay() << ' ' << vecOrd[i].getDate().getMonth() << ' ' << vecOrd[i].getDate().getYear();
			fout << std::endl;
			for (int j = 0; j < vecOrd[i].getProduct().size(); j++) {
				if (j == vecOrd[i].getProduct().size() - 1) {
					std::string val = vecOrd[i].getProduct()[j].getName() + "_";
					vecOrd[i].getProduct()[j].setName(val);
				}
				fout << vecOrd[i].getProduct()[j] << std::endl;
			}
		}
	}
	fout.close();
}

void Order::add(const Order& obj)	
{
	this->ID = obj.ID;
	this->login = obj.login;
	this->address = obj.address;
	this->product = obj.product;
	this->date = obj.date;
}

Order::~Order()
{
	this->product.clear();
}
