#include "BookCard.h"
BOOKCARD::BOOKCARD()
{
}
BOOKCARD::~BOOKCARD()
{
}
std::istream& operator>>(std::istream& is, BOOKCARD& book_card)
{
	fflush(stdin);
	std::cout << "Nhap Ten Doc Gia muon sach : ";
	std::getline(is, book_card.m_reader);
	fflush(stdin);
	std::cout << "Nhap Ma Doc Gia : ";
	std::getline(is, book_card.m_code_reader);
	fflush(stdin);
	std::cout << " Nhap Ten Sach can muon : ";
	std::getline(is, book_card.m_name_book);
	fflush(stdin);
	std::cout << "Nhap Ma Sach : ";
	std::getline(is, book_card.m_code_book);
	fflush(stdin);
	int selection; 
	do{
		std::cout << " Loai Sach :  1.Ngoai Van   2.Tieng Viet ";
		std::cout << "\n\t Nhap Lua Chon: ";
		std::cin >> selection;
		if (selection<1 || selection>2)
		{
			std::cout << "\n\t\t KHONG HOP LE .VUI LONG NHAP LAI\n";
		}
	} while (selection<1 || selection>2);
	if (selection == 1)
	{
		book_card.m_type_book = "Ngoai Van";
	}
	else book_card.m_type_book = "Tieng Viet";
	if (book_card.m_type_book == "Ngoai Van")
	{
		std::cout << " Nhap Ma ISBN : ";
		is >> book_card.m_ISBN;
	}
	std::cout << " \tNhap ngay muon : \n";
	is >> book_card.m_date_lend;
	std::cout << "\tNhap Ngay Tra : \n";
	is >> book_card.m_date_pay;
	fflush(stdin);
	std::cout << "Ghi Chu : ";
	std::getline(is, book_card.m_note);
	return is;
}
std::ostream& operator<<(std::ostream& os, BOOKCARD lend_card)
{
	os << lend_card.m_code_reader << ',' << lend_card.m_reader << ',' << lend_card.m_code_book << ',' << lend_card.m_name_book << ',' << lend_card.m_type_book;
	if (lend_card.m_type_book == "Ngoai Van")
	{
		os << ',' << lend_card.m_ISBN;
	}
	else os << ',';
	os << ',' << lend_card.m_date_lend << ',' <<lend_card.m_date_pay << ',' << lend_card.m_note;
	return os;
}
void BOOKCARD::setReader(std::string reader)
{
	m_reader = reader;
}
void BOOKCARD::setCode(std::string code)
{
	m_code_reader = code;
}
void BOOKCARD::setNameBook(std::string name)
{
	m_name_book = name;
}
void BOOKCARD::setCodeBook(std::string code)
{
	m_code_book = code;
}
void BOOKCARD::setType(std::string type)
{
	m_type_book = type;
}
void BOOKCARD::setNote(std::string note)
{
	m_note = note;
}
void BOOKCARD::setDateLend(DATE date)
{
	m_date_lend = date;
}
void BOOKCARD::setDatePay(DATE date)
{
	m_date_pay = date;
}
void BOOKCARD::setISBN(int a)
{
	m_ISBN = a;
}
std::string BOOKCARD::getCodeReadaer()
{
	return m_code_reader;
}
std::string BOOKCARD::getCodeBook()
{
	return m_code_book;
}
DATE BOOKCARD::getDateLend()
{
	return m_date_lend;
}
DATE BOOKCARD::getDatePay()
{
	return m_date_pay;
}
std::string  BOOKCARD::getReader()
{
	return m_reader;
}
std::string BOOKCARD::getType()
{
	return m_type_book;
}