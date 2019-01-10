#ifndef __READER_H__
#define __READER_H__
#include "Date.h"
#include <string>
class READER
{
protected:
	std::string m_reader_name, m_reader_code, m_address;
	DATE m_birthday;
public:
	READER();
	~READER();
	friend std::istream& operator>>(std::istream&, READER&);
	void setName(std::string);
	void setCode(std::string);
	void setAddress(std::string);
	void setBirthday(DATE);
	std::string getReaderCode();
};

class CHILDREADER:public READER
{
private:
	std::string m_name_representative, m_number_phone;
public:
	CHILDREADER();
	~CHILDREADER();
	friend std::istream& operator>>(std::istream&, CHILDREADER&);
	friend std::ostream& operator<<(std::ostream&, CHILDREADER);
	void setNameRepresent(std::string);
	void setPhone(std::string);
};
class ADULTREADER :public READER
{
private:
	std::string m_identity_card, m_number_phone;
public:
	ADULTREADER();
	~ADULTREADER();
	friend std::istream& operator>>(std::istream&, ADULTREADER&);
	friend std::ostream& operator<<(std::ostream&, ADULTREADER);
	void setIdentity(std::string);
	void setPhone(std::string);
	std::string getIdentity();
};
#endif