#include "Date.h"
DATE::DATE()
{
}
DATE::~DATE()
{
}
DATE::DATE(int date, int month, int year)
{
	this->m_date = date;
	this->m_month = month;
	this->m_year = year;
}
bool checkLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else return 0;
}
bool checkDate(DATE a)
{
	int date = a.getDate();
	int month = a.getMonth();
	int year = a.getYear();
	if (date<1 || date>31 || month<1 || month>12)
		return 0;
	else
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (date > 30)
				return 0;
			else return 1;
		}
		if (month==2)
		{
			if (checkLeapYear(year) == 1)
			{
				if (date > 29)
					return 0;
				else return 1;
			}
			else
			{
				if (date > 28)
					return 0;
				else return 1;
			}
		}
		return 1;
	}
}
std::istream& operator>>(std::istream& is, DATE& date)
{
	bool check;
	do{
		std::cout << "Nhap ngay : ";
		is >> date.m_date;
		std::cout << "Nhap thang : ";
		is >> date.m_month;
		std::cout << "Nhap nam : ";
		is >> date.m_year;
		check = checkDate(date);
		if (check == 0)
		{
			std::cout << "\n\n\t\t Ngay khong hop le \n\t\t Vui Long Nhap Lai\n\n";
		}
	} while (check == 0);
	return is;
}
std::ostream& operator<<(std::ostream& os, DATE date)
{
	os << date.m_date << "/" << date.m_month << "/" << date.m_year;
	return os;
}
int DATE::getDate()
{
	return this->m_date;
}
int DATE::getMonth()
{
	return this->m_month;
}
int DATE::getYear()
{
	return this->m_year;
}
int DATE::countDate(DATE a)
{
	int date = a.getDate();
	int month = a.getMonth();
	int year = a.getYear();
	int sum_date = 0;
	while (this->m_year >= m_year)
	{
		if (year == this->m_year && month == this->m_month)
		{
			sum_date += this->m_date - date;
			break;
		}
		else
		{
			if (month == 4 || month == 6 || month == 9|| month == 11)
			{
						sum_date += 30 - date;
			}
			else if (month==2)
			{
					  int check = checkLeapYear(year);
					  if (check == 1)
						  sum_date += 29 - date;
					  else sum_date = 28 - date;
					  std::cout << month << " ";
			}
			else
			{
				sum_date += 31 - date;
			}
			}
			month++;
			date = 0;
			if (month == 13)
			{
				month = 1;
				year++;
			}
	}
	return sum_date;
}
DATE& DATE::operator=(const DATE &a)
{
	this->m_date = a.m_date;
	this->m_month = a.m_month;
	this->m_year = a.m_year;
	return *this;
}