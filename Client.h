#pragma once
#include "Inicials.h"
#include "Check.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_VECTOR_SIZE 150 //Максимальная размерность вектора
#define fileClient "client.txt"

class Client : public Inicials
{
	std::string login;
	std::string Address;
	std::string phoneNumber;
	std::string bankCard;
public:
	Client();

	Client(const Client& obj);
	Client& operator=(const Client& obj);

	static void DataMenu(std::vector<Client>& vecClient);

	void setAddress(std::string Address);
	void setPhoneNumber(std::string phoneNumber);
	void setBankCard(std::string bankCard);
	void setLogin(std::string login);

	void print(int& i) override;

	static void myAccount(Client& account);
	static void accFileInput(Client& account, std::string& login);
	static void accFileOutput(Client& account);
	static void printAcc(Client& account);
	static void editAcc(Client& account);
	static void clearLine(std::string& login);
	
	static void print(std::vector<Client>& vecClient);
	static void del(std::vector<Client>& vecClient);
	static void edit(std::vector<Client>& vecClient);
	static void findMenu(std::vector<Client>& vecClient);
	static void findInicials(std::vector<Client>& vecClient);
	static void findAddress(std::vector<Client>& vecClient);
	static void sortMenu(std::vector<Client>& vecClient);

	static void alphSort(std::vector<Client>& vecClient);
	static void addressSort(std::vector<Client>& vecClient);
	static void loginSort(std::vector<Client>& vecClient);
	static void phoneNumberSort(std::vector<Client>& vecClient);

	std::string getAddress();
	std::string getPhoneNumber();
	std::string getBankCard();
	std::string getLogin();

	friend std::ostream& operator<<(std::ostream& os, Client& obj);
	friend std::istream& operator>>(std::istream& is, Client& obj);

	static void fileInput(std::vector<Client>& vecClient);
	static void fileOutput(std::vector<Client>& vecClient);

	~Client();
};

