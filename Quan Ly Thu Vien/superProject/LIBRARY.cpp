#include "Library.h"
LIBRARY::LIBRARY()
{
}
LIBRARY::~LIBRARY()
{
}
int Astoi(std::string s)
{
	int l1 = s.length();
	int num1 = 0;
	for (int i = l1 - 1; i >= 0; --i){
		num1 += (int)(s[i] - '0') * pow(10, l1 - i - 1);
	}
	return num1;
}
void LIBRARY::inputArrayReader()
{
	std::fstream file_reader;
	file_reader.open("Reader.csv");
	if (!file_reader)
	{
		std::cout << " File no exist\n";
	}
	else
	{
		std::string str;
		std::getline(file_reader, str);
		while (!file_reader.eof())
		{
			ADULTREADER temp1;
			CHILDREADER temp2;
			std::string reader_name, reader_code, address, phone;
			std::string date, month, year;
			std::string check, check2;
			std::getline(file_reader, check, ',');
			std::getline(file_reader, check2, ',');
			std::getline(file_reader, reader_name, ',');
			if (reader_name == "")
			{
				break;
			}
			if (check == "x")
			{
				std::string identity;
				char c;
				std::getline(file_reader, reader_code, ',');
				std::getline(file_reader, date, '/');
				std::getline(file_reader, month, '/');
				std::getline(file_reader, year, ',');
				std::getline(file_reader, address, ',');
				std::getline(file_reader, phone, ',');
				std::getline(file_reader, check, ',');
				std::getline(file_reader, identity);
				DATE birthday(Astoi(date), Astoi(month), Astoi(year));
				temp1.setName(reader_name);
				temp1.setCode(reader_code);
				temp1.setBirthday(birthday);
				temp1.setAddress(address);
				temp1.setPhone(phone);
				temp1.setIdentity(identity);
				m_array_adult_reader.push_back(temp1);
			}
			else
			{
				std::string representative;
				char c;
				std::getline(file_reader, reader_code, ',');
				std::getline(file_reader, date, '/');
				std::getline(file_reader, month, '/');
				std::getline(file_reader, year, ',');
				std::getline(file_reader, address, ',');
				std::getline(file_reader, phone, ',');
				std::getline(file_reader, representative,',');
				std::getline(file_reader, check);
				DATE birthday(Astoi(date), Astoi(month), Astoi(year));
				temp2.setName(reader_name);
				temp2.setCode(reader_code);
				temp2.setBirthday(birthday);
				temp2.setAddress(address);
				temp2.setPhone(phone);
				temp2.setNameRepresent(representative);
				m_array_child_reader.push_back(temp2);
			}
		}
	}
	file_reader.close();
}
void LIBRARY::inputArrayLendCard()
{
	std::fstream file;
	file.open("LendCard.csv");
	if (!file)
	{
		std::cout << " File no exist\n";
	}
	else
	{
		std::string str;
		std::getline(file, str);
		while (!file.eof())
		{
			BOOKCARD temp;
			std::string reader_name, reader_code, book_name, book_code, note, type, ISBN;
			std::string date, month, year;
			std::string check;
			std::getline(file, reader_code, ',');
			std::getline(file, reader_name, ',');
			if (reader_name == "")
			{
				break;
			}
				std::getline(file, book_code, ',');
				std::getline(file, book_name, ',');
				std::getline(file, type, ',');
				std::getline(file, ISBN, ',');
				std::getline(file, date, '/');
				std::getline(file, month, '/');
				std::getline(file, year, ',');
				DATE date_lend(Astoi(date), Astoi(month), Astoi(year));
				std::getline(file, date, '/');
				std::getline(file, month, '/');
				std::getline(file, year, ',');
				DATE date_pay(Astoi(date), Astoi(month), Astoi(year));
				std::getline(file, note);
				DATE birthday(Astoi(date), Astoi(month), Astoi(year));
				temp.setReader(reader_name);
				temp.setCode(reader_code);
				temp.setCodeBook(book_code);
				temp.setNameBook(book_name);
				temp.setType(type);
				if (type == "Ngoai Van")
				{
					temp.setISBN(Astoi(ISBN));
				}
				temp.setDateLend(date_lend);
				temp.setDatePay(date_pay);
				temp.setNote(note);
				m_array_book_card.push_back(temp);
		}
	}
	file.close();
}
void LIBRARY::inputArrayBook()
{
	std::fstream file;
	file.open("Book.csv");
	if (!file)
	{
		std::cout << " File no exist\n";
	}
	else
	{
		std::string str;
		std::getline(file, str);
		while (!file.eof())
		{
			BOOK temp1;
			FOREIGNBOOK temp2;
			std::string name, code, type, author, price, status, ISBN;
			std::string check;
			std::getline(file, type, ',');
			if (type == "")
			{
				break;
			}
			if (type!="Ngoai Van")
			{
				std::getline(file, name, ',');
				std::getline(file, code, ',');
				std::getline(file, author, ',');
				std::getline(file, price, ',');
				std::getline(file, status, ',');
				std::getline(file, check);
				temp1.setName(name);
				temp1.setCode(code);
				temp1.setAuthor(author);
				temp1.setStatus(status);
				temp1.setPrice(Astoi(price));
				m_array_VN_book.push_back(temp1);
			}
			else
			{
				std::getline(file, name, ',');
				std::getline(file, code, ',');
				std::getline(file, author, ',');
				std::getline(file, price, ',');
				std::getline(file, status, ',');
				std::getline(file, ISBN);
				temp2.setName(name);
				temp2.setCode(code);
				temp2.setAuthor(author);
				temp2.setStatus(status);
				temp2.setPrice(Astoi(price));
				temp2.setISBN(Astoi(ISBN));
				m_array_foreign_book.push_back(temp2);
			}
		}
	}
	file.close();
}
void LIBRARY::inputAdultReader()
{
	ADULTREADER a;
	int count;
	do
	{ 
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << " 2. THEM DOC GIA (TUOI > 14 ) \n\n";
		std::cout << "================================================================================\n\n";
		 count= 0;
		std::cin >> a;
		int size1 = m_array_adult_reader.size();
		int size2 = m_array_child_reader.size();
		for (int i = 0; i < size1; i++)
		{ 
			if (a.getReaderCode() == m_array_adult_reader[i].getReaderCode())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA DOC GIA DA BI TRUNG LAP !!!\n\t\t    !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
		for (int i = 0; i < size1; i++)
		{
			if (a.getIdentity() == m_array_adult_reader[i].getIdentity())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! CMND DOC GIA DA BI TRUNG LAP !!!\n\t\t    !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
		for (int i = 0; i < size2; i++)
		{
			if (a.getReaderCode() == m_array_child_reader[i].getReaderCode())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA DOC GIA DA BI TRUNG LAP !!!\n\t\t    !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
	} while (count != 0);
	m_array_adult_reader.push_back(a);
	outputReader();
}
void LIBRARY::inputChildreader()
{
	CHILDREADER a;
	int count;
	do
	{
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << " 2. THEM DOC GIA (TUOI < 14 ) \n\n";
		std::cout << "================================================================================\n\n";
		count = 0;
		std::cin >> a;
		int size1 = m_array_adult_reader.size();
		int size2 = m_array_child_reader.size();
		for (int i = 0; i < size1; i++)
		{
			if (a.getReaderCode() == m_array_adult_reader[i].getReaderCode())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA DOC GIA DA BI TRUNG LAP !!!\n\t\t    !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
		for (int i = 0; i < size2; i++)
		{
			if (a.getReaderCode() == m_array_child_reader[i].getReaderCode())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA DOC GIA DA BI TRUNG LAP !!!\n\t\t    !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
	} while (count != 0);
	m_array_child_reader.push_back(a);
	outputReader();
}
void LIBRARY::inputBookVN()
{
	BOOK a;
	int count;
	do{
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << " 1. THEM SACH (TIENG VIET) \n\n";
		std::cout << "================================================================================\n\n";
		std::cin >> a;
		count = 0;
		int size1 = m_array_foreign_book.size();
		int size2 = m_array_VN_book.size();
		for (int i = 0; i < size1; i++)
		{
			if (a.getCodeBook() == m_array_VN_book[i].getCodeBook())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA SACH DA BI TRUNG LAP !!!\n\t     !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
			if (a.getCodeBook() == m_array_foreign_book[i].getCodeBook())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA SACH DA BI TRUNG LAP !!!\n\t     !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
		}
	} while (count != 0);
	m_array_VN_book.push_back(a);
	outputBook();
}
void LIBRARY::inputForeignBook()
{
	FOREIGNBOOK a;
	int count;
	do{
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << " 1. THEM SACH ( NGOAI VAN ) \n\n";
		std::cout << "================================================================================\n\n";
		count = 0;
		std::cin >> a;
		int size1 = m_array_foreign_book.size();
		int size2 = m_array_VN_book.size();
		for (int i = 0; i < size1; i++)
		{
			if (a.getCodeBook() == m_array_VN_book[i].getCodeBook())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA SACH DA BI TRUNG LAP !!!\n\t     !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
			if (a.getCodeBook() == m_array_foreign_book[i].getCodeBook())
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA SACH DA BI TRUNG LAP !!!\n\t     !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				system("pause");
				count++;
				break;
			}
			if (a.getISBN() == m_array_foreign_book[i].getISBN());
			{
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!! MA ISBN DA BI TRUNG LAP !!!\n\t     !!!  VUI LONG NHAP LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				count++;
				break;
			}
		}
	} while (count != 0);
	m_array_foreign_book.push_back(a);
	outputBook();
}
void LIBRARY::inputCard()
{
	BOOKCARD a;
	int count;
	do{
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << " 3. THEM PHIEU MUON/TRA \n\n";
		std::cout << "================================================================================\n\n";
		count = 0;
		std::cin >> a;
		int size1 = m_array_adult_reader.size();
		int size2 = m_array_child_reader.size();
		int size3 = m_array_VN_book.size();
		int size4 = m_array_foreign_book.size();
		int count1=0 , count2=0, count3=0, count4=0;
		for (int i = 0; i < size3; i++)
		{
			if (a.getCodeBook() == m_array_VN_book[i].getCodeBook())
			{
				count3++;
				break;
			}
		}
			for (int i = 0; i < size4; i++)
			{
				if (a.getCodeBook() == m_array_foreign_book[i].getCodeBook())
				{
					count4++;
					break;
				}
			}
			if (count4 == 0 && count3==0)
			{
				std::cout << "4";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				std::cout << "\t\t!!!  SACH NAY KHONG CO TRONG THU VIEN !!!\n\t     !!!  VUI LONG KIEM TRA LAI !!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				count++;
				system("pause");
			}
		for (int i = 0; i < size1; i++)
		{
			if (a.getCodeReadaer() == m_array_adult_reader[i].getReaderCode())
			{
				count1++;
				break;
			}
		}
		for (int i = 0; i < size2; i++)
		{
			if (a.getCodeReadaer() == m_array_child_reader[i].getReaderCode())
			{
				count2++;
				break;
			}
		}
		if (count2 == 0 && count1==0)
		{
			std::cout << "2";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			std::cout << "\t\t!!!DOC GIA KHONG PHAI THANH VIEN CUA THU VIEN!!!\n\t       !!!  VUI LONG KIEM TRA LAI !!!";
			std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			count++;
			system("pause");
		}
	} while (count != 0);
	m_array_book_card.push_back(a);
	outputCard();
}

void LIBRARY::outputReader()
{
	int size1 = m_array_adult_reader.size();
	int size2 = m_array_child_reader.size();
	std::ofstream file;
	file.open("Reader.csv", std::ios::out);
	if (!file)
	{
		std::cout << " Khong Mo Duoc File\n";
	}
	else
	{
		file << "DOC GIA NGUOI LON" << ',' << "DOC GIA TRE EM" << ',' << "HO VA TEN" << ',' << "MA DOC GIA" << ',' << "NGAY SINH" << ',' << "DIA CHI" << ',' << "SDT" << ',' << "TEN NGUOI DAI DIEN" << ',' << "CMND\n";

		for (int i = 0; i < size1; i++)
		{
			file << m_array_adult_reader[i] << "\n";
		}
		for (int i = 0; i < size2; i++)
		{
			file << m_array_child_reader[i] << "\n";
		}
	}
	file.close();
}
void LIBRARY::outputCard()
{
	int size = m_array_book_card.size();
	std::ofstream file;
	file.open("BookCard.csv", std::ios::out);
	if (!file)
	{
		std::cout << " Khong Mo Duoc File\n";
	}
	else
	{
		file << "MA DOC GIA"<<','<<"HO VA TEN" << ',' << "MA SACH" << ',' << "TEN SACH" << ',' << "THE LOAI" << ',' << "ISBN" << ',' << "NGAY MUON" << ',' << "NGAY TRA" << ',' << "GHI CHU\n";
		for (int i = 0; i < size; i++)
		{
			file << m_array_book_card[i] << "\n";
		}
	}
	file.close();
}
void LIBRARY::outputBook()
{
	int size1 = m_array_VN_book.size();
	int size2 = m_array_foreign_book.size();
	std::ofstream file;
	file.open("Book.csv", std::ios::out);
	if (!file)
	{
		std::cout << " Khong Mo Duoc File\n";
	}
	else
	{
		file << "THE LOAI" << ',' << "TEN SACH" << ',' << "MA SACH" << ',' << "TAC GIA" << ',' << "GIA" << ',' << "TRANG THAI" << ',' << "ISBN\n";
		for (int i = 0; i < size1; i++)
		{
			file << m_array_VN_book[i] << "\n";
		}
		for (int i = 0; i < size2; i++)
		{
			file << m_array_foreign_book[i] << "\n";
		}
	}
	file.close();
}
int LIBRARY::deleteBook(std::string code)
{
	bool check = false;
	int size1 = m_array_VN_book.size();
	int size2 = m_array_foreign_book.size();
	for (int i = 0; i < size1; i++)
	{
		if (m_array_VN_book[i].getCodeBook() == code)
		{
			m_array_VN_book.erase(m_array_VN_book.begin()+i);
			check = true;
			break;
		}
	}
	if (check == false)
	{
		for (int i = 0; i < size2; i++)
		{
			if (m_array_foreign_book[i].getCodeBook() == code)
			{
				m_array_foreign_book.erase(m_array_foreign_book.begin() + i);
				check = true;
				break;
			}
		}
	}
	if (check == false)
	{
		return 0;
	}
	outputBook();
	return 1;
}
int LIBRARY::deleteReader(std::string code)
{
	bool check = false;
	int size1 = m_array_adult_reader.size();
	int size2 =m_array_child_reader.size();
	for (int i = 0; i < size1; i++)
	{
		if (m_array_adult_reader[i].getReaderCode() == code)
		{
			m_array_adult_reader.erase(m_array_adult_reader.begin() + i);
			check = true;
			break;
		}
	}
	if (check == false)
	{
		for (int i = 0; i < size2; i++)
		{
			if (m_array_child_reader[i].getReaderCode() == code)
			{
				m_array_child_reader.erase(m_array_child_reader.begin() + i);
				check = true;
				break;
			}
		}
	}
	if (check == false)
	{
		return 0;
	}
	outputReader();
	return 1;
}
int LIBRARY::editBook(std::string code)
{
	bool check = false;
	int size1 = m_array_VN_book.size();
	int size2 = m_array_foreign_book.size();
	for (int i = 0; i < size1; i++)
	{
		if (m_array_VN_book[i].getCodeBook() == code)
		{
			BOOK a;
			std::cin >> a;
			m_array_VN_book[i] = a;
			check = true;
			break;
		}
	}
	if (check == false)
	{
		for (int i = 0; i < size2; i++)
		{
			if (m_array_foreign_book[i].getCodeBook() == code)
			{
				FOREIGNBOOK a;
				std::cin >> a;
				m_array_foreign_book[i] = a;
				check = true;
				break;
			}
		}
	}
	if (check == false)
	{
		return 0;
	}
	outputBook();
	return 1;
}
int LIBRARY::editReader(std::string code)
{
	bool check = false;
	int size1 = m_array_adult_reader.size();
	int size2 = m_array_child_reader.size();
	for (int i = 0; i < size1; i++)
	{
		if (m_array_adult_reader[i].getReaderCode() == code)
		{
			ADULTREADER a;
			std::cin >> a;
			m_array_adult_reader[i] = a;
			check = true;
			break;
		}
	}
	if (check == false)
	{
		for (int i = 0; i < size2; i++)
		{
			if (m_array_child_reader[i].getReaderCode() == code)
			{
				CHILDREADER a;
				std::cin >> a;
				m_array_child_reader[i] = a;
				check = true;
				break;
			}
		}
	}
	if (check == false)
	{
		return 0;
	}
	outputReader();
	return 1;
}
int LIBRARY::countMoney()
{
	int count = 0;
	int size = m_array_book_card.size();
	for (int i = 0; i < size; i++)
	{
		DATE date_lend = m_array_book_card[i].getDateLend();
		DATE date_pay = m_array_book_card[i].getDatePay();
		int date=date_pay.countDate(date_lend);
		if (date>7)
		{
			int money = 0;
			std::string type = m_array_book_card[i].getType();
			if (type == "Ngoai Van")
			{
				 money = (date - 7) * 20000;
			}
			else  money = (date - 7) * 10000;
			std::cout << "\t " << m_array_book_card[i].getCodeReadaer() << "    " << m_array_book_card[i].getReader() << "     " << money << "VND\n";
			count++;
		}
	}
	if (count == 0)
	{
		return 0;
	}
	return 1;
}
void LIBRARY::menu()
{
	int selection;
	inputArrayBook();
	inputArrayLendCard();
	inputArrayReader();
	do{
		system("cls");
		std::cout << "\n================================================================================\n\n";
		std::cout << std::setw(45) << " THU VIEN \n\n";
		std::cout << "\t\t\t\t1 . THEM SACH  \n";
		std::cout << "\t\t\t\t2 . THEM DOC GIA\n";
		std::cout << "\t\t\t\t3 . THEM PHIEU MUON/TRA \n";
		std::cout << "\t\t\t\t4 . XOA\n";
		std::cout << "\t\t\t\t5 . CHINH SUA\n";
		std::cout << "\t\t\t\t6 . PHAT TIEN\n";
		std::cout << "\t\t\t\t0 . Thoat\n";
		std::cout << "\n================================================================================\n\n";
		std::cout << "\t\t\t Nhap lua chon : ";
		std::cin >> selection;
		std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
		if (selection<0 || selection>6)
		{
			std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
			std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			system("pause");
		}

		else if (selection == 0)
		{
			std::cout << "\t\t\t    Cam On Ban\n";
		}
		else if (selection == 1)
		{
			int selection2;
			do{
				system("cls");
				std::cout << "\n================================================================================\n\n";
				std::cout << std::setw(45) << " THEM SACH \n\n";
				std::cout << "\t\t\t\t1 . TIENG VIET  \n";
				std::cout << "\t\t\t\t2 . NGOAI VAN\n";
				std::cout << "\t\t\t\t0 . TRO LAI  \n";
				std::cout << "\n================================================================================\n\n";
				std::cout << "\t\t\t Nhap lua chon : ";
				std::cin >> selection2;
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				if (selection2<0 || selection2>2)
				{
					std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					system("pause");
				}
				else if (selection2 == 1)
				{
					inputBookVN();
				}
				else if (selection2 == 2)
				{
					inputForeignBook();
				}
			} while (selection2 != 0);
		}
		else if (selection == 2)
		{
			int selection2;
			do{
				system("cls");
				std::cout << "\n================================================================================\n\n";
				std::cout << std::setw(45) << " THEM DOC GIA \n\n";
				std::cout << "\t\t\t\t1 . TUOI < 14  \n";
				std::cout << "\t\t\t\t2 . TUOI >14 \n";
				std::cout << "\t\t\t\t0 . TRO LAI  \n";
				std::cout << "\n================================================================================\n\n";
				std::cout << "\t\t\t Nhap lua chon : ";
				std::cin >> selection2;
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				if (selection2<0 || selection2>2)
				{
					std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					system("pause");
				}
				else if (selection2 == 1)
				{
					inputChildreader();
				}
				else if (selection2 == 2)
				{
					inputAdultReader();
				}
			} while (selection2 != 0);
		}
		else if (selection == 3)
		{
			inputCard();
		}
		else if (selection == 4)
		{
			int selection2;
			do{
				system("cls");
				std::cout << "\n================================================================================\n\n";
				std::cout << std::setw(45) << " 4. XOA \n\n";
				std::cout << "\t\t\t\t1 . XOA SACH  \n";
				std::cout << "\t\t\t\t2 . XOA DOC GIA\n";
				std::cout << "\t\t\t\t0 . TRO LAI  \n";
				std::cout << "\n================================================================================\n\n";
				std::cout << "\t\t\t Nhap lua chon : ";
				std::cin >> selection2;
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				if (selection2<0 || selection2>2)
				{
					std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					system("pause");
				}
				else if (selection2 == 1)
				{
					system("cls");
					std::cout << "================================================================================\n\n";
					std::cout << std::setw(45) << " 4. XOA SACH \n\n";
					std::cout << "================================================================================\n\n";
					std::string code;
					fflush(stdin);
					std::cout << " Nhap ma sach can xoa : ";
					std::getline(std::cin, code);
					int check = deleteBook(code);
					if (check == 0)
					{
						std::cout << "\n\t\t KHONG TIM THAY SACH\n\n";
					}
					else std::cout << " \n\t\tXOA THANH CONG";
					system("pause");
				}
				else if (selection2 == 2)
				{
					system("cls");
					std::cout << "================================================================================\n\n";
					std::cout << std::setw(45) << " 4. XOA DOC GIA \n\n";
					std::cout << "================================================================================\n\n";
					std::string code;
					fflush(stdin);
					std::cout << "\tNhap ma doc gia can xoa : ";
					std::getline(std::cin, code);
					int check = deleteReader(code);
					if (check == 0)
					{
						std::cout << "\n\t\t KHONG TIM THAY DOC GIA\n\n";
					}
					else std::cout << " \n\t\tXOA THANH CONG";
					system("pause");
				}
			} while (selection2 != 0);
		}
		else if (selection == 5)
		{
			int selection2;
			do{
				system("cls");
				std::cout << "\n================================================================================\n\n";
				std::cout << std::setw(45) << " 5. CHINH SUA \n\n";
				std::cout << "\t\t\t\t1 . CHINH SUA SACH  \n";
				std::cout << "\t\t\t\t2 . CHINH SUA DOC GIA\n";
				std::cout << "\t\t\t\t0 . TRO LAI  \n";
				std::cout << "\n================================================================================\n\n";
				std::cout << "\t\t\t Nhap lua chon : ";
				std::cin >> selection2;
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				if (selection2<0 || selection2>2)
				{
					std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					system("pause");
				}
				else if (selection2 == 1)
				{
					system("cls");
					std::cout << "================================================================================\n\n";
					std::cout << std::setw(45) << " 5. CHINH SUA SACH \n\n";
					std::cout << "================================================================================\n\n";
					std::string code;
					fflush(stdin);
					std::cout << "\t Nhap ma sach can chinh sua: ";
					std::getline(std::cin, code);
					int check = editBook(code);
					if (check == 0)
					{
						std::cout << "\n\t\t KHONG TIM THAY SACH\n\n";
					}
					else std::cout << " \n\t\tXOA THANH CONG";
					system("pause");
				}
				else if (selection2 == 2)
				{
					system("cls");
					std::cout << "================================================================================\n\n";
					std::cout << std::setw(45) << " 5. CHINH SUA DOC GIA \n\n";
					std::cout << "================================================================================\n\n";
					std::string code;
					fflush(stdin);
					std::cout << "\t Nhap ma doc gia can chinh sua : ";
					std::getline(std::cin, code);
					int check = editReader(code);
					if (check == 0)
					{
						std::cout << "\n\t\t KHONG TIM THAY DOC GIA\n\n";
					}
					else std::cout << " \n\t\tXOA THANH CONG";
					system("pause");
				}
			} while (selection2 != 0);
		}
		else if (selection == 6)
		{
			system("cls");
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 6 . PHAT TIEN \n\n";
			std::cout << "================================================================================\n\n";
			int check = countMoney();
			if (check == 0)
			{
				std::cout << "\n\t\t KHONG CO TRUONG HOP PHAT TIEN\n\n";
			}
			system("pause");
		}
	} while (selection != 0);
}