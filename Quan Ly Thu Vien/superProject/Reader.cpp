#include "Reader.h"
READER::READER()
{
}
READER::~READER()
{
}
std::istream& operator>>(std::istream& is, READER& reader)
{
	fflush(stdin);
	std::cout << " Nhap Ten Doc Gia : ";
	std::getline(is, reader.m_reader_name);
	fflush(stdin);
	std::cout << " Nhap Ma Doc Gia : ";
	std::getline(is, reader.m_reader_code);
	fflush(stdin);
	std::cout << "Nhap Dia Chi : ";
	std::getline(is, reader.m_address);
	std::cout << " \t Nhap Ngay Sinh : \n";
	is >> reader.m_birthday;
	return is;
}
void READER::setName(std::string name)
{
	m_reader_name = name;
}
void READER::setCode(std::string code)
{
	m_reader_code = code;
}
void READER::setAddress(std::string address)
{
	m_address = address;
}
void READER::setBirthday(DATE date)
{
	m_birthday = date;
}
std::string READER::getReaderCode()
{ 
	return m_reader_code;
}

CHILDREADER::CHILDREADER()
{
}
CHILDREADER::~CHILDREADER()
{
}
std::istream& operator>>(std::istream& is, CHILDREADER& reader)
{
	READER *parent = static_cast<READER *>(&reader);
	is >> *parent;
	fflush(stdin);
	std::cout << " Nhap Ten Nguoi Dai Dien : ";
	std::getline(is, reader.m_name_representative);
	fflush(stdin);
	std::cout << "Nhap SDT Nguoi Dai Dien : ";
	std::getline(is, reader.m_number_phone);
	return is;
}
std::ostream& operator<<(std::ostream& os, CHILDREADER reader)
{
	os << ',';
	os << "x" <<','<< reader.m_reader_name << ',' << reader.m_reader_code << ',' << reader.m_birthday << ',' << reader.m_address << ',' << reader.m_number_phone << ',' << reader.m_name_representative;
	return os;
}
void CHILDREADER::setNameRepresent(std::string name)
{
	m_name_representative = name;
}
void CHILDREADER::setPhone(std::string phone)
{
	m_number_phone = phone;
}

ADULTREADER::ADULTREADER()
{
}
ADULTREADER::~ADULTREADER()
{
}
std::istream& operator>>(std::istream& is, ADULTREADER& reader)
{
	READER *parent = static_cast<READER *>(&reader);
	is >> *parent;
	fflush(stdin);
	std::cout << " Nhap CMND : ";
	std::getline(is, reader.m_identity_card);
	fflush(stdin);
	std::cout << "Nhap SDT : ";
	std::getline(is, reader.m_number_phone);
	return is;
}
std::ostream& operator<<(std::ostream& os, ADULTREADER reader)
{ 
	os << "x" << ',' <<','<< reader.m_reader_name << ',' << reader.m_reader_code << ',' << reader.m_birthday << ',' << reader.m_address << ',' << reader.m_number_phone << ',' <<','<<reader.m_identity_card;
	return os;
}
void ADULTREADER::setIdentity(std::string identity)
{
	m_identity_card = identity;
}
void ADULTREADER::setPhone(std::string phone)
{
	m_number_phone = phone;
}
std::string ADULTREADER::getIdentity()
{ 
	return m_identity_card;
}