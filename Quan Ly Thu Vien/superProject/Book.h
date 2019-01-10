#ifndef __BOOK_H__
#define __BOOK_H__
#include "Date.h"
#include <string>
class BOOK
{
protected:
	std::string m_code_book, m_title_book, m_author,m_status;
	int m_price;
public:
	BOOK();
	~BOOK();
	friend std::ostream& operator<<(std::ostream& os, BOOK);
	friend std::istream& operator>>(std::istream&, BOOK&);
	std::string getCodeBook();
	void setCode(std::string);
	void setName(std::string);
	void setAuthor(std::string);
	void setStatus(std::string);
	void setPrice(int);
};

class FOREIGNBOOK :public BOOK
{
private:
	int m_ISBN;
public:
	FOREIGNBOOK();
	~FOREIGNBOOK();
	friend std::ostream& operator<<(std::ostream& os, FOREIGNBOOK);
	friend std::istream& operator>>(std::istream&, FOREIGNBOOK& );
int getISBN();
void setISBN(int);
};
#endif