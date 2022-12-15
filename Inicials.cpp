#include "Inicials.h"

Inicials::Inicials(std::string name, std::string surname, std::string patronymic)
{
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
}

void Inicials::setName(std::string name)
{
	this->name = name;
}

void Inicials::setSurname(std::string surname)
{
	this->surname = surname;
}

void Inicials::setPatronymic(std::string patronymic)
{
	this->patronymic = patronymic;
}

std::string Inicials::getName()
{
	return name;
}

std::string Inicials::getSurname()
{
	return surname;
}

std::string Inicials::getPatronymic()
{
	return patronymic;
}

Inicials& Inicials::operator=(const Inicials& obj)
{
	{
		if (this != &obj) {
			this->name = obj.name;
			this->surname = obj.surname;
			this->patronymic = obj.patronymic;
		}
		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, Inicials& obj) {
	os << obj.surname << ' ' << obj.name << ' ' << obj.patronymic;
	return os;
}

std::istream& operator>>(std::istream& is, Inicials& obj) {
	is >> obj.surname >> obj.name >> obj.patronymic;
	return is;
}

Inicials::~Inicials()
{

}