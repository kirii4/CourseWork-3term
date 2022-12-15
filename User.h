#pragma once
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Order.h"
#include "Client.h"
#include "Check.h"
#include <conio.h>

#define fileReg "registration.txt"
#define fileAcc "User.txt"
#define MAX_VECTOR_SIZE 150

class User
{
	std::string login;
	std::string password;
	int role;
public:
	std::string cashPassword;
	
	User();
	User(std::string login, std::string password, int role);

	User(const User& obj);
	User& operator=(const User& obj);

	friend std::istream& operator>>(std::istream& is, User& obj);
	friend std::ostream& operator<<(std::ostream& os, User& obj);

	void setLogin(const std::string login);
	void setPassword(const std::string password);
	void setRole(const int role);
	void plusPasswordSymb(char ch);

	std::string getLogin();
	std::string getPassword();
	int getRole();

	static void fileInputReg(std::vector<User>& vecUser);
	static void fileOutputReg(std::vector<User>& vecUser);
	static void fileInputUser(std::vector<User>& vecUser);
	static void fileOutputUser(std::vector<User>& vecUser);
	static void printFile(std::vector<User>& vecUser, std::ostream& fl);
	static void printFile(User& obj, std::ostream& fl);

	static int welcome();
	static int sign_in(std::string& login);
	static void createAdmin();
	static void userMenu(std::string& login); 
	static void adminMenu(std::string& login); 
	friend void AccMenu(std::vector<User>& vecReg, std::vector<User>& vecUser, std::string& login); 
	friend void DataMenu(std::vector<Shop>& vecShop, std::vector<Order>& vecOrd, std::vector<Client>& vecClient);
	friend void star(User& obj);
	friend void registration(std::vector<User>& vecUser, std::vector<User>& vecReg, std::string typeReg); 
	friend void enterRegPass(int& try_, std::vector<User>& vecUser, User& obj); 
	friend void UserPassword(User& obj); 
	friend void regWork(std::vector<User>& vecUser, std::vector<User>& vecReg);
	friend void registrMenu(std::vector<User>& vecUser, std::vector<User>& vecReg); 
	friend void printConsole(std::vector<User> vecReg);
	friend void finishReg(std::vector<User>& vecUser, std::vector<User>& vecReg, const int pos);  
	friend void delAcc(std::vector<User>& vecUser, std::string& login);

	~User();
};