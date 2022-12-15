//#include "Shop.h"
#include "Order.h"

Shop::Shop() : shopName("None") {}

Shop::Shop(std::string shopName)
{
	this->shopName = shopName;
}

void Shop::setProduct(Product product)
{
	this->product.push_back(product);
}

std::string Shop::getShopName()
{
	return shopName;
}

std::vector<Product>& Shop::getProduct()
{
	return product;
}

void Shop::setShopName(std::string name)
{
	this->shopName = name;
}

void Shop::clearProduct()
{
	product.clear();
}

Shop::Shop(const Shop& obj)
{
	this->shopName = obj.shopName;
	this->product = obj.product;
}

Shop& Shop::operator=(const Shop& obj)
{
	if (this != &obj) {
		this->shopName = obj.shopName;
		this->product = obj.product;
	}
	return *this;
}

void Shop::DataMenu(std::vector<Shop>& vecShop) {
	std::string name;
#ifdef KEYBOARD

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursorVisible(hStdOut, false, 100);
	std::string Menu[] = { "Меню данных о магазинах",
		"",
		"",
							"1.Просмотреть список магазинов.",
							"2.Добавить магазин.",
							"3.Удалить магазин.",
							"4.Корректировать данные.",
							"5.Поиск магазина.",
							"6.Работа с ассортиментами магазинов.",
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
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if (vecShop.size() == 0) {
					system("cls");
					std::cout << std::endl << "Список пуст." << std::endl << std::endl;
				}
				else {
					Shop::print(vecShop);
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
				Shop::add(vecShop);
				system("pause");
				aT = 3;
				break;
			}
			case 3:
			{
				system("cls");
				GoToXY(hStdOut, x, 0);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Shop::del(vecShop);
				system("pause");
				aT = 3;
				break;
			}
			case 4:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Shop::print(vecShop);
				Shop::edit(vecShop);
				system("pause");
				aT = 3;
				break;
			case 5:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				Shop::find(vecShop);
				system("pause");
				aT = 3;
				break;
			case 6:
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
						Product::DataMenu((*it).getProduct());
					}
					else std::cout << "Ошибка ввода." << std::endl;

				}
				system("pause");
				aT = 3;
				break;
			case 7:
				system("cls");
				GoToXY(hStdOut, x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				aT = 3;
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
		std::cout << "\tМеню данных о магазинах\n";
		std::cout << "=======================================\n\n";
		std::cout << "1.Просмотреть список магазинов.\n"
			"2.Добавить магазин.\n"
			"3.Удалить магазин.\n"
			"4.Корректировать данные.\n"
			"5.Поиск магазина.\n"
			"6.Работа с ассортиментами магазинов.\n"
			"7.Вернуться в меню.\n";
		Check::checkInt(menu);
		switch (menu) {
		case 1:
			system("cls");
			if (vecShop.size() == 0) {
				std::cout << std::endl << "Список пуст." << std::endl << std::endl;
			}
			else {
				Shop::print(vecShop);
			}
			system("pause");
			break;
		case 2:
			system("cls");
			Shop::add(vecShop);
			system("pause");
			break;
		case 3:
			system("cls");
			Shop::del(vecShop);
			system("pause");
			break;
		case 4:
			system("cls");
			Shop::print(vecShop);
			Shop::edit(vecShop);
			system("pause");
			break;
		case 5:
			system("cls");
			Shop::find(vecShop);
			system("pause");
			break;
		case 6:
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
					Product::DataMenu((*it).getProduct());
				}
				else std::cout << "Ошибка ввода." << std::endl;

			}
			system("pause");
			break;
		case 7:
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

void Shop::print(std::vector<Shop>& s)
{
	system("cls");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 40, y = 5;
	std::cout << std::endl << std::endl;
	std::cout << std::setw(59) << "+-----------------+" << std::endl;
	std::cout << std::setw(59) << "|      Название   |" << std::endl;
	std::cout << std::setw(59) << "+-----------------+" << std::endl;
	for (auto i = 0; i < s.size(); i++) {
		GoToXY(hStdOut, x, y++);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("|%3d.  %-8s   |\n",
			i + 1, s[i].getShopName().c_str());
	}
	std::cout << std::setw(59) << "+-----------------+" << std::endl;
}

void Shop::add(std::vector<Shop>& vecShop)
{
	system("cls");
	if (vecShop.size() >= MAX_VECTOR_SIZE) std::cout << "Превышение размерности списка!!!\n";
	else {
		std::string name;
		std::cout << "Введите название магазина: \n";
		bool val = true;
		do {
			Check::checkString(name);
			if (Shop::checkShopName(name, vecShop)) {
				val = false;
			}
			else {
				std::cout << "Данный магазин уже имеется в базе.\n";
			}
		} while (val);
		Shop s(name);
		vecShop.push_back(s);
		AccessAdd();
	}
}

void Shop::del(std::vector<Shop>& vecShop)
{
	system("cls");
	if (vecShop.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		Shop::print(vecShop);
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			Check::checkInt(num);
			num--;
			if (num >= vecShop.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else {
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				Check::checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else {
					vecShop.erase(vecShop.begin() + num);
					AccessDelete();
					break;
				}
			}
		}
	}
}

void Shop::find(std::vector<Shop>& vecShop)
{
	system("cls");
	std::cout << "Введите название магазина: ";
	std::string name;
	//Check::checkString(name);
	getline(std::cin, name);
	int k = 0;
	std::cout << std::endl;
	for (auto i = 0U; i < vecShop.size(); i++) {
		if (vecShop[i].getShopName().find(name) != std::string::npos) {
			printSoloShop(vecShop[i], k);

		}
	}
	if (k == 0) {
		std::cout << "Магазинов по запрошенному названию не найдено!\n";
	}
}

void Shop::edit(std::vector<Shop>& vecShop)
{
	if (vecShop.size() == 0) {
		std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	}
	else {
		std::cout << "Введите номер элемента для изменения.\n";
		int num_list;
		std::string name;
		Check::checkInt(num_list);
		while (!(num_list > 0 && num_list <= vecShop.size())) {
			std::cout << "Неверный ввод номера!\n";
			Check::checkInt(num_list);
		}
		std::cout << "Текущее значение: ";
		std::cout << vecShop[num_list - 1].getShopName() << ".\n"
			<< "Введите новое значение: ";
		getchar();
		Check::checkString(name);
		vecShop[num_list - 1].setShopName(name);
		AccessEdit();
	}
}

void Shop::fileInput(std::vector<Shop>& vecShop)
{
	std::ifstream f_in(fileShop);

	if (!f_in.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(0);
	}
	else {
		std::string name;
		while (f_in >> name) {//Запись из файла в вектор
			Shop n;
			Product prod;
			if (vecShop.size() >= MAX_VECTOR_SIZE) {
				std::cout << "\n\nПревышение размерности списка!!!.\n";
				break;
			}
			if (name[name.size() - 1] == '_') {
				name.erase(name.end() - 1);
				n.setShopName(name);
				vecShop.push_back(n);
				continue;
			}
			n.setShopName(name);
			while (f_in >> prod) {
				std::string name = prod.getName();
				std::replace(name.begin(), name.end(), '_', ' ');
				prod.setName(name);
				if (prod.getID()[prod.getID().size() - 1] == '_') {
					std::string val = prod.getID();
					val.erase(val.end() - 1);
					prod.setID(val);
					n.setProduct(prod);
					break;
				}
				else n.setProduct(prod);
			}
			vecShop.push_back(n);
		}
	}
	f_in.close();
	for (auto& i : vecShop) {
		std::string name = i.getShopName();
		std::replace(name.begin(), name.end(), '_', ' ');
		for (auto& j : i.getProduct()) {
			std::string _name = j.getName();
			std::replace(_name.begin(), _name.end(), '_', ' ');
		}
	}
}

void Shop::fileOutput(std::vector<Shop>& vecShop)
{
	std::ofstream fout(fileShop, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) {
		std::cout << "\nОшибка открытия файла!" << std::endl;
		exit(1);
	}
	else {
		for (auto& i : vecShop) {
			std::string name = i.getShopName();
			std::replace(name.begin(), name.end(), ' ', '_');
			for (auto& j : i.getProduct()) {
				std::string _name = j.getName();
				std::replace(_name.begin(), _name.end(), ' ', '_');
			}
		}
		for (auto i = 0; i < vecShop.size(); i++) {
			fout << vecShop[i].getShopName();
			if (vecShop[i].getProduct().size() == 0) { fout << '_'; }
			fout << std::endl;
			for (int j = 0; j < vecShop[i].getProduct().size(); j++) {
				std::string name = vecShop[i].getProduct()[j].getName();
				std::replace(name.begin(), name.end(), ' ', '_');
				vecShop[i].getProduct()[j].setName(name);
				if (j == vecShop[i].getProduct().size() - 1) vecShop[i].getProduct()[j].setID(vecShop[i].getProduct()[j].getID() + '_');
				fout << vecShop[i].getProduct()[j] << std::endl;
			}
		}
	}
	fout.close();
}

Shop::~Shop() {
	this->product.clear();
}

bool Shop::checkShopName(std::string& name, std::vector<Shop>& vecShop) {
	bool check = false;
	for (auto i = 0U; i < vecShop.size(); i++) {
		if (vecShop[i].getShopName().find(name) != std::string::npos) {
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

void Shop::printSoloShop(Shop& shop, int& k)
{
	printf("|%3d.  %-8s   |\n",
		++k, shop.getShopName().c_str());
}

std::ostream& operator<<(std::ostream& os, Shop& obj)
{
	os << obj.shopName << std::endl;
	for (auto& i : obj.product) {
		os << i << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Shop& obj)
{
	is >> obj.shopName;
	Product val;
	while (!is.eof()) {
		is >> val;
		obj.product.push_back(val);
	}
	return is;
}
