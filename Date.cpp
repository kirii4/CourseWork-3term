#include "Date.h"

Date::Date()
{
    time_t seconds = time(NULL);
    tm timeinfo;
    localtime_s(&timeinfo, &seconds);
    this->year = std::to_string(timeinfo.tm_year + 1900);
    this->day = (timeinfo.tm_mday < 10) ? "0" + std::to_string(timeinfo.tm_mday) : std::to_string(timeinfo.tm_mday);
    this->month = (timeinfo.tm_mon + 1 < 10) ? "0" + std::to_string(timeinfo.tm_mon + 1) : std::to_string(timeinfo.tm_mon + 1);
}

Date::Date(const Date& date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date& Date::operator=(const Date& obj)
{
    if (this != &obj) {
        this->day = obj.day;
        this->month = obj.month;
        this->year = obj.year;
    }
    return *this;
}

std::string Date::getDay()
{
	return day;
}

std::string Date::getMonth()
{
	return month;
}

std::string Date::getYear()
{
	return year;
}

void Date::setDay(std::string day)
{
    this->day = day;
}

void Date::setMonth(std::string month)
{
    this->month = month;
}

void Date::setYear(std::string year)
{
    this->year;
}

Date::~Date()
{

}

std::ostream& operator<<(std::ostream& os, Date& obj)
{
    os << obj.day << ' ' << obj.month << ' ' << obj.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& obj)
{
    is >> obj.day >> obj.month >> obj.year;
    return is;
}