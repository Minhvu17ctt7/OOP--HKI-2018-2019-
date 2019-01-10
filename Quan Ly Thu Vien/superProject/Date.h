#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#include <fstream>
class DATE
{
private:
	int m_date, m_month, m_year;
public:
	DATE();
	~DATE();
	DATE(int, int, int);
	int getDate();
	int getMonth();
	int getYear();
	friend std::istream& operator>>(std::istream&, DATE &);
	friend std::ostream& operator<<(std::ostream&, DATE);
	DATE& operator=(const DATE&);
	int countDate(DATE);
};
#endif