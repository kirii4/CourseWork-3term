#pragma once

#include "Client.h"
#include "Check.h"
#include <iostream>
#include <iomanip>
#include "Date.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include "Transaction.h"

#define MAX_VECTOR_SIZE 150 //Максимальная размерность вектора
#define fileOrder "order.txt"
#define fileShop "shop.txt"
#define fileProduct "food.txt"

class Product;
class Shop;

class Order
{
	std::string ID;
	std::string login;
	std::string address;
	double price = 0;
	std::vector<Product> product;
	Date date;
	static inline int count = 0;
public:

	Order();

	void setID(std::string ID);
	void setProduct(Product product);
	void setLogin(std::string login);
	void setAddress(std::string address);

	std::string getID();
	std::vector<Product>& getProduct();
	Date getDate();
	std::string getLogin();
	std::string getAddress();
	static int getCount();

	void clearProduct();

	Order(const Order& obj);
	Order& operator=(const Order& obj);

	static void print(std::vector<Order>& vecOrd);
	static void add(Client& account, Order& order, std::vector<Shop>& vecShop);
	static void del(std::vector<Order>& vecOrd);
	static void edit(std::vector<Order>& vecOrd);
	static void find(std::vector<Order>& vecOrd);

	static void printBasket(Order& order);
	static void editBasket(Order& order, std::vector<Shop>& vecShop);
	static void fileInputBasket(Order& order, std::string& login);
	static void fileOutputBasket(Order& order);
	static void createID(Order& order, Client& account);
	static void addBasket(Order& order, std::vector<Shop>& vecShop);
	static void delBasket(Order& order);

	static void printSoloOrder(Order& order, int& k);
	static bool checkIDOrder(std::string ID, std::vector<Order>& vecOrc);

	friend std::ostream& operator<<(std::ostream& os, Order& obj);
	friend std::istream& operator>>(std::istream& is, Order& obj);

	static void DataMenu(std::vector<Order>& vecOrd);

	static void fileInput(std::vector<Order>& vecOrd);
	static void fileOutput(std::vector<Order>& vecOrd);

	void add(const Order& order);

	~Order();
};

class Product
{
protected:
	double price;
	std::string ID;
	std::string name;
public:
	Product();
	Product(const Product& obj);

	void setPrice(double price);
	void setID(std::string ID);
	void setName(std::string name);

	double getPrice();
	std::string getID();
	std::string getName();

	static void print(std::vector<Product>& vecShop);
	static void add(std::vector<Product>& vecShop);
	static void del(std::vector<Product>& vecShop);
	static void edit(std::vector<Product>& vecShop);
	static void findMenu(std::vector<Product>& vecShop);
	static void findID(std::vector<Product>& vecShop);
	static void findName(std::vector<Product>& vecShop);
	static void sortMenu(std::vector<Product>& vecShop);

	static void printSoloProduct(Product& product, int& k);
	static bool checkIDProduct(std::string ID, std::vector<Product>& vecProduct);

	static void IDSort(std::vector<Product>& vecProduct);
	static void AlphSort(std::vector<Product>& vecProduct);
	static void priceSort(std::vector<Product>& vecProduct);

	friend std::ostream& operator<<(std::ostream& os, Product& obj);
	friend std::istream& operator>>(std::istream& is, Product& obj);
	Product& operator=(const Product& obj);

	static void DataMenu(std::vector<Product>& vecProduct);
	static void BasketDataMenu(std::vector<Product>& vecProduct);

	~Product();
};

class Shop
{
	std::string shopName;
	std::vector<Product> product;
public:
	Shop();
	Shop(std::string shopName);
	
	void setProduct(Product product);
	std::string getShopName();
	std::vector<Product>& getProduct();
	void setShopName(std::string name);

	void clearProduct();

	Shop(const Shop& obj);
	Shop& operator=(const Shop& obj);

	friend std::ostream& operator<<(std::ostream& os, Shop& obj);
	friend std::istream& operator>>(std::istream& is, Shop& obj);

	static void DataMenu(std::vector<Shop>& vecShop);

	static void print(std::vector<Shop>& vecShop);
	static void add(std::vector<Shop>& vecShop);
	static void del(std::vector<Shop>& vecShop);
	static void edit(std::vector<Shop>& vecShop);
	static void find(std::vector<Shop>& vecShop);

	static bool checkShopName(std::string& name, std::vector<Shop>& vecShop);
	static void printSoloShop(Shop& shop, int& k);

	static void fileInput(std::vector<Shop>& vecOrd);
	static void fileOutput(std::vector<Shop>& vecOrd);

	~Shop();
};