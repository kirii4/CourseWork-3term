#pragma once

#include <string>
#include <ctime>
#include <fstream>

class Date
{
protected:
	std::string day;
	std::string month;
	std::string year;
public:
	Date();
	Date(const Date& date);
	Date& operator=(const Date& obj);

	std::string getDay();
	std::string getMonth();
	std::string getYear();

	void setDay(std::string day);
	void setMonth(std::string month);
	void setYear(std::string year);

	friend std::ostream& operator<<(std::ostream& os, Date& obj);
	friend std::istream& operator>>(std::istream& is, Date& obj);

	~Date();
};

