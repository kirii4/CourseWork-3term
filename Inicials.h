#pragma once

#include <string>
#include <fstream>

class Inicials {
protected:
	std::string name;
	std::string surname;
	std::string patronymic;
public:
	Inicials(std::string name = "None", std::string surname = "None", std::string patronymic = "None");

	void setName(std::string name);
	void setSurname(std::string surname);
	void setPatronymic(std::string patronymic);

	virtual void print(int& i) = 0;

	virtual std::string getName();
	std::string getSurname();
	std::string getPatronymic();

	Inicials& operator=(const Inicials& obj);

	friend std::ostream& operator<<(std::ostream& os, Inicials& obj);
	friend std::istream& operator>>(std::istream& is, Inicials& obj);

	~Inicials();
};