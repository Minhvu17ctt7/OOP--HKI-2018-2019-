#include "Book.h"
BOOK::BOOK()
{
}
BOOK::~BOOK()
{
}
std::istream& operator>>(std::istream& is, BOOK& book)
{
	fflush(stdin);
	std::cout << " Nhap Ten Sach : ";
	std::getline(is, book.m_title_book);
	fflush(stdin);
	std::cout << " Nhap Ma Sach : ";
	std::getline(is, book.m_code_book);
	fflush(stdin);
	std::cout << " Nhap Tac Gia : ";
	std::getline(is, book.m_author);
	std::cout << " Nhap Gia : ";
	is >> book.m_price;
	fflush(stdin);
	std::cout << " Nhap Trang Thai Sach : ";
	std::getline(is, book.m_status);
	return is;
}
std::ostream& operator<<(std::ostream& os, BOOK book)
{
	os  << "Tieng Viet" << ',' << book.m_title_book << ',' << book.m_code_book<< ',' << book.m_author << ',' << book.m_price << ',' << book.m_status;
	return os;
}
std::string BOOK::getCodeBook()
{
	return m_code_book;
}
void BOOK::setCode(std::string code)
{
	m_code_book = code;
}
void BOOK::setName(std::string name)
{
	m_title_book = name;
}
void BOOK::setAuthor(std::string author)
{ 
	m_author = author;
}
void BOOK::setStatus(std::string status)
{
	m_status = status;
}
void BOOK::setPrice(int price)
{ 
	m_price = price;
}

FOREIGNBOOK::FOREIGNBOOK()
{
}
FOREIGNBOOK::~FOREIGNBOOK()
{
}
std::istream& operator>>(std::istream& is, FOREIGNBOOK& book)
{
	BOOK *parent = static_cast<BOOK*> (&book);
	is >> *parent;
	std::cout << " Nhap Ma ISBN : ";
	is >> book.m_ISBN;
	return is;
}
std::ostream& operator<<(std::ostream& os, FOREIGNBOOK book)
{
	os << "Ngoai Van" << ',' << book.m_title_book << ',' << book.m_code_book<< ',' << book.m_author << ',' << book.m_price << ',' << book.m_status << ',' << book.m_ISBN;
	return os;
}
int FOREIGNBOOK::getISBN()
{
	return m_ISBN;
}
void FOREIGNBOOK::setISBN(int ISBN)
{ 
	m_ISBN = ISBN;
}