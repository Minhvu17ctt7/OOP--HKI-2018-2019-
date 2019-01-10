#ifndef __BOOKCARD_H__
#define __BOOKCARD_H__
#include "Date.h"
#include <string>
class BOOKCARD
{
protected:
	std::string m_reader, m_code_reader, m_name_book, m_code_book, m_type_book, m_note;
	DATE m_date_pay, m_date_lend;
	int m_ISBN;
public:
	BOOKCARD();
	~BOOKCARD();
	friend std::ostream& operator<<(std::ostream&, BOOKCARD);
	friend std::istream& operator>>(std::istream&, BOOKCARD&);
	void setReader(std::string);
	void setCode(std::string);
	void setISBN(int);
	void setNameBook(std::string);
	void setCodeBook(std::string);
	void setType(std::string);
	void setNote(std::string);
	void setDateLend(DATE);
	void setDatePay(DATE);
	std::string getReader();
	std::string getCodeReadaer();
	std::string getCodeBook();
	std::string getType();
	DATE getDateLend();
	DATE getDatePay();
};

#endif