#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include "Book.h"
#include "BookCard.h"
#include "Reader.h"
#include <vector>
#include <iomanip>
class LIBRARY
{
private:
	std::vector<CHILDREADER> m_array_child_reader;
	std::vector<ADULTREADER> m_array_adult_reader;
	std::vector<BOOKCARD> m_array_book_card;
	std::vector<BOOK> m_array_VN_book;
	std::vector<FOREIGNBOOK> m_array_foreign_book;
public:
	LIBRARY();
	~LIBRARY();
	void inputArrayReader();
	void inputArrayLendCard();
	void inputArrayBook();

	void inputCard();
	void inputBookVN();
	void inputForeignBook();
	void inputChildreader();
	void inputAdultReader();
	
	void outputReader();
	void outputCard();
	void outputBook();

	int deleteReader(std::string);
	int deleteBook(std::string);
	int editReader(std::string);
	int editBook(std::string);
	int countMoney();
	void menu();
};
#endif