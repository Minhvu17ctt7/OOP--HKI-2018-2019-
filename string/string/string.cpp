#include "string.h"
//string::string
size_t countSize(const char* s)
{
	size_t size=0;
	char c;
	for (size_t i = 0,c = s[0]; c != '\0'; i++, c = s[i])
	{
		size++;
	}
	return size;
}
string::string()
{
	m_data = new char;
	m_data[0] = '\0';
	m_size = 0;
	m_capacity = 15;
}
string::string(const string &str)
{
	size_t size = str.size();
	m_capacity = 15;
	m_size = size;
	while (m_capacity < size)
		m_capacity += 15;
	m_data = new char[size+1];
	for (size_t i = 0; i < size; i++)
		m_data[i] = str[i];
	m_data[size] = '\0';
}
string::string(const string& str,size_t pos, size_t len)
{
	m_capacity = 15;
	m_size = len;
	while (m_capacity < len)
		m_capacity += 15;
	m_data = new char[m_size+1];
	for (size_t i = 0; i < len; i++)
		m_data[i] = str[pos + i];
	m_data[m_size] = '\0';
}
string::string(const char* s)
{
	size_t size = countSize(s);
	m_capacity = 15;
	m_size = size;
	while (m_capacity < size)
		m_capacity += 15;
	m_data = new char[size+1];
	for (size_t i = 0; i < size; i++)
		m_data[i] = s[i];
	m_data[size] = '\0';
}
string::string(const char* s, size_t n)
{
	m_capacity = 15;
	m_size = n;
	while (m_capacity < n)
		m_capacity += 15;
	m_data = new char[n+1];
	for (size_t i = 0; i < n; i++)
		m_data[i] = s[i];
	m_data[n] = '\0';
}
string::string(size_t n, char c)
{
	m_capacity = 15;
	m_size = n;
	while (m_capacity < n)
		m_capacity += 15;
	m_data = new char[n+1];
	for (size_t i = 0; i < n; i++)
		m_data[i] =c;
	m_data[n] = '\0';
}
template <class InputIterator>
string::string(InputIterator first, InputIterator last)
{
	size_t size_s = 0;
	InputIterator temp = first;
	while (temp != last)
	{
		size_s++;
		temp++;
	}
	size_s++;
	m_size = size_s;
	while (m_capacity < m_size)
		m_capacity += 15;
	m_data = new char[m_size + 1];
	temp = first;
	for (size_t i = 0; i < m_size;i++)
		m_data[i] = *(first+i);
	m_data[m_size] = '\0';
}
string::string(char* begin, char* finish)
{
	size_t size= 0;
	for (char* i = begin; i != finish; i++)
	{
		size++;
	}
	m_capacity = 15;
	m_size = size;
	while (m_capacity < size)
		m_capacity += 15;
	m_data = new char[size + 1];
	size_t index = 0;
	for (char* i = begin; i != finish; i++)
	{
		m_data[index] = *i;
		index++;
	}
}
//string::~string
string::~string()
{
	delete[]m_data;
}
//string::append
string& string::append(const string& str)
{
	size_t size = m_size + str.size();
	while (m_capacity < size)
		m_capacity += 15;
	string temp(*this);
	int temp2 = m_size;
	m_size = size;
	m_data = new char[m_size + 1];
	for (size_t i = 0; i < temp2; i++)
		m_data[i] = temp[i];
	for (size_t i = 0; i < str.size(); i++)
		m_data[temp2 + i] = str[i];
	m_data[size] = '\0';
	return *this;
}
string& string::append(const string& str, size_t subpos, size_t sublen)
{
	
	string temp(str, subpos, sublen);
	return append(temp);
}
string& string::append(const char* s)
{
	string temp(s);
	return append(temp);
}
string& string::append(const char* s, size_t n)
{
	string temp(s, n);
	return append(temp);
}
string& string:: append(size_t n, char c)
{
	string temp(n, c);
	return append(temp);
}
string& string::append(char* first, char* last)
{
	string temp(first, last);
	return append(temp);
}
char& string::front()
{
	return m_data[0];
}
const char& string::front() const
{
	return m_data[0];
}
//iterator
char* string::begin()
{
	return &m_data[0];
}
const char* string::begin() const
{
	return &m_data[0];
}
char* string::end()
{
	return &m_data[m_size - 1];
}
const char* string::end() const
{
	return &m_data[m_size - 1];
}
char* string::rbegin()
{
	return &m_data[m_size-1];
}
const char* string::rbegin() const
{
	return &m_data[m_size-1];
}
char* string::rend()
{
	return &m_data[0];
}
const char* string::rend() const
{
	return &m_data[0];
}
char* string::cbegin()
{
	return &m_data[0];
}
char* string::cend()
{
	return &m_data[m_size - 1];
}
//operator = 
string& string::operator= (const string& str)
{
	size_t size = str.size();
	while (m_capacity < size)
		m_capacity += 15;
	m_size = size;
	m_data = new char[size];
	for (size_t i = 0; i < size; i++)
		m_data[i] = str[i];
	return *this;
}
string& string::operator= (const char* s)
{
	size_t size = countSize(s);
	while (m_capacity < size)
		m_capacity += 15;
	m_size = size;
	m_data = new char[size+1];
	for (size_t i = 0; i < size; i++)
		m_data[i] = s[i];
	m_data[size] = '\0';
	return *this;
}
string& string::operator= (char c)
{
	m_size = 1;
	m_data = new char[2];
	m_data[0] = c;
	m_data[1] = '\0';
	return *this;
}
const char& string::operator[] (size_t pos) const
{
	return m_data[pos];
}
char& string::operator[](size_t pos)
{
	return m_data[pos];
}
char& string::at(size_t pos)
{
	return m_data[pos];
}
const char & string::at(size_t pos) const
{
	return m_data[pos];
}
char& string::back()
{
	return m_data[m_size - 1];
}
const char& string::back() const
{
	return m_data[m_size - 1];
}
//capacity
size_t string::size() const
{
	return m_size;
}
size_t string::length() const
{
	return m_size;
}
size_t string::max_size() const
{
	return npos;
}
void string::resize(size_t n, char c)
{
	size_t s = size();
	string temp = *this;
	clear();
	m_data = new char[n];
	if (n < s)
	{
		string temp2(temp, 0, n - 1);
		*this = temp2;
	}
	else
	{
		string temp2 = temp;
		temp2.append(n - s,c);
		*this = temp2;
	}
}
void string::resize(size_t n)
{
	//resize(n, " ");
	size_t s = size();
	string temp = *this;
	clear();
	m_data = new char[n];
	if (n < s)
	{
		string temp2(temp, 0, n);
		*this = temp2;
	}
	else
	{
		string temp2 = temp;
		temp2.append(" ", n - s);
		*this = temp2;
	}
}
size_t string::capacity() const
{
	return m_capacity;
}
void string::reserve(size_t n = 0)
{
	if (n > m_size)
		m_capacity = n;
	else
	{
		string temp(*this, 0, n);
		clear();
		*this = temp;
		m_capacity = n;
	}
}
void string::clear()
{
	delete[] m_data;
	m_size = 0;
}
bool string::empty() const
{
	if (m_size == 0)
		return true;
	else return false;
}
void string::shrink_to_fit()
{
	m_capacity = m_size;
}
//Modifers
string& string::operator+= (const string& str)
{
	append(str);
	return *this;
}
string& string::operator+= (const char* s)
{
	append(s);
	return *this;
}
string& string::operator+= (char c)
{
	append(1,c);
	return *this;
}
void string::push_back(char c) 
{
	append(1, c);
}
string& string::assign(const string& str)
{
	clear();
	append(str);
	return *this;
}
string& string::assign(const string& str, size_t subpos, size_t sublen)
{
	clear();
	append(str, subpos, sublen);
	return *this;
}
string& string::assign(const char* s)
{
	clear();
	append(s);
	return *this;
}
string& string::assign(const char* s, size_t n)
{
	clear();
	append(s, n);
	return *this;
}
string& string::assign(size_t n, char c)
{
	clear();
	append(n, c);
	return *this;
}
string& string::assign(char* first, char* last)
{
	string temp(first, last);
	return assign(temp);
}
string& string::insert(size_t pos, const string& str)
{
	string temp(*this,0, pos); 
	string temp2(*this, pos, m_size-pos);
	temp.append(str);
	temp.append(temp2);
	*this = temp;
	return *this;
}
string& string::insert(size_t pos, const string& str, size_t subpos, size_t sublen)
{
	string temp(str, subpos, sublen);
	std::cout << temp;
	return insert(pos, temp);
}
string& string::insert(size_t pos, const char* s)
{
	string temp(s);
	return insert(pos, temp);
}
string& string::insert(size_t pos, const char* s, size_t n)
{
	string temp(s,n);
	return insert(pos, temp);
}
string& string::insert(size_t pos, size_t n, char c)
{
	string temp(n, c);
	return insert(pos, temp);
}
void string::insert(char* p, size_t n, char c)
{
	size_t count = 0;
	for (char* i = &m_data[0]; i != p; i++)
	{
		count++;
	}
	insert(count, n, c);
}
char* string::insert(char* p, char c)
{
	insert(p, 1, c);
	return p;
}
void string::insert(char* p, char* first, char* last)
{
	string temp(first, last);
	size_t count = 0;
	for (char* i = &m_data[0]; i != p; i++)
	{
		count++;
	}
	insert(count, temp);
}
string& string::erase(size_t pos, size_t len=npos)
{
	size_t temp_len = m_size < (pos + len) ? m_size - pos : len;
	string temp(*this,0, pos);
	string temp2(*this, pos + len,m_size - pos - len);
	temp.append(temp2);
	*this = temp;
	return *this;
}
char* string::erase(char* p)
{
	size_t count = 0;
	for (char* i = &m_data[0]; i != p; i++)
	{
		count++;
	}
	erase(count, 1);
	return p;
}
char* string::erase(char* first, char* last)
{
	size_t count = 0;
	for (char* i = &m_data[0]; i != first; i++)
	{
		count++;
	}
	size_t count2 = 0;
	for (char* i = first; i !=last; i++)
	{
		count2++;
	}
	erase(count, count2);
	return first;
}
string& string::replace(char* i1, char* i2, char* first, char* last)
{
	size_t count = 0;
	for (char* i = &m_data[0]; i != i1; i++)
	{
		count++;
	}
	size_t count2 = 0;
	for (char* i = i1; i != i2; i++)
	{
		count2++;
	}
	string temp(first, last);
	return replace(count, count2, temp);
}
string& string::replace(size_t pos, size_t len, const string& str)
{
	erase(pos, len);
    insert(pos, str);
	return *this;
}
string& string::replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen)
{
	string temp(str, subpos, sublen);
	replace(pos, len, temp);
	return *this;
}
string& string::replace(size_t pos, size_t len, const char* s, size_t n)
{
	string temp(s, n);
	replace(pos, len, temp);
	return *this;
}
string& string::replace(size_t pos, size_t len, const char* s)
{
	string temp(s);
	replace(pos, len, temp);
	return *this;
}
string& string::replace(size_t pos, size_t len, size_t n, char c)
{
	string temp(n, c);
	replace(pos, len, temp);
	return *this;
}
void string::swap(string& str)
{
	string temp = *this;
	*this = str;
	str = temp;
}
void string::pop_back()
{
	erase(m_size, 1);
}
//String operations
const char* string::c_str() const
{
	return m_data;
}
const char * string::data() const
{
	char *temp = new char[m_size];
	for (size_t i = 0; i < m_size; i++)
		temp[i] = m_data[i];
	return temp;
}
size_t string::copy(char* s, size_t len, size_t pos = 0) const
{
	size_t length = (pos + len) < m_size ? (pos + len) : m_size;
		for (size_t i = pos; i <=length; i++)
			s[i] = m_data[i];
		return len;
}
size_t string::find(const string& str, size_t pos = 0) const
{
	if (m_size < pos + str.size() - 1)
		return npos;
	else
	{
		size_t i= pos;
		while (i < m_size)
		{
			bool check = true;
			if (m_data[i] == str[0])
			{
				for (size_t j = 0; j < str.size(); j++)
				{
					if (m_data[i + j] != str[j])
					{
						check = false;
						break;
					}
				}
				if (check == true)
				{
					return i;
				}
			}
			i++;
		}
		return npos;
	}
}
size_t string::find(const char* s, size_t pos = 0) const
{
	string temp(s);
	return find(temp, pos);
}
size_t string::find(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return find(temp, pos);
}
size_t string::find(char c, size_t pos = 0) const
{
	string temp(1, c);
	return find(temp, pos);
}
size_t string::rfind(const string& str, size_t pos = npos) const
{
	size_t i = m_size < (pos + str.size()-1) ? 0 : pos;
		size_t index = npos;
		while (i < m_size)
		{
			bool check = true;
			if (m_data[i] == str[0])
			{
				for (size_t j = 0; j < str.size(); j++)
				{
					if (m_data[i + j] != str[j])
					{
						check = false;
						break;
					}
				}
				if (check == true)
				{
					index = i;
				}
			}
			i++;
		}
		return index;
}
size_t string::rfind(const char* s, size_t pos = npos) const
{
	string temp(s);
	return rfind(temp, pos);
}
size_t string::rfind(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return rfind(temp, pos);
}
size_t string::rfind(char c, size_t pos = npos) const
{
	string temp(1, c);
	return rfind(temp, pos);
}
size_t string::find_first_of(const string& str, size_t pos = 0) const
{
	if (m_size <= pos)
		return npos;
	else
	{
		for (size_t i = pos; i < m_size; i++)
		{
			if (str.find(m_data[i], 0) != npos)
			{
				return i;
			}
		}
		return npos;
	}
}
size_t string::find_first_of(const char* s, size_t pos = 0) const
{
	string temp(s);
	return find_first_of(temp, pos);
}
size_t string::find_first_of(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return find_first_of(temp, pos);
}
size_t string::find_first_of(char c, size_t pos = 0) const
{
	string temp(1, c);
	return find_first_of(temp, pos);
}
size_t string::find_last_of(const string& str, size_t pos = npos) const
{
	size_t begin = m_size < (pos + str.size() - 1) ? 0 : pos;
	size_t index = npos;
	for (int i = begin; i < m_size; i++)
	{
		if (str.find(m_data[i], 0) != npos)
		{
			index = i;
		}
	}
	return index;
}
size_t string::find_last_of(const char* s, size_t pos = npos) const
{
	string temp(s);
	return find_last_of(temp, pos);
}
size_t string::find_last_of(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return find_last_of(temp, pos);
}
size_t string::find_last_of(char c, size_t pos = npos) const
{
	string temp(1, c);
	return find_last_of(temp, pos);
}
size_t string::find_first_not_of(const string& str, size_t pos = 0) const
{
	if (m_size <= pos)
		return npos;
	for (size_t i = pos; i < m_size; i++)
	{
		if (str.find(m_data[i], 0) == npos)
		{
			return i;
		}
	}
	return npos;
}
size_t string::find_first_not_of(const char* s, size_t pos = 0) const
{
	string temp(s);
	return find_first_not_of(temp, pos);
}
size_t string::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return find_first_not_of(temp, pos);
}
size_t string::find_first_not_of(char c, size_t pos = 0) const
{
	string temp(1, c);
	return find_first_not_of(temp, pos);
}
size_t string::find_last_not_of(const string& str, size_t pos = npos) const
{
	size_t begin = m_size < (pos + str.size() - 1) ? 0 : pos;
	size_t index = npos;
	for (int i = begin; i < m_size; i++)
	{
		if (str.find(m_data[i], 0) == npos)
		{
			index = i;
		}
	}
	return index;
}
size_t string::find_last_not_of(const char* s, size_t pos = npos) const
{
	string temp(s);
	return find_last_not_of(temp, pos);
}
size_t string::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	string temp(s, n);
	return find_last_not_of(temp, pos);
}
size_t string::find_last_not_of(char c, size_t pos = npos) const
{
	string temp(1, c);
	return find_last_not_of(temp, pos);
}
string string::substr(size_t pos = 0, size_t len = npos) const
{
   size_t temp_len = m_size < (pos + len) ? m_size-pos:len;
	string temp(*this, pos, temp_len);
	return temp;
}
int string::compare(const string& str) const
{
	if (m_size>str.size())
		return -1;
	else if(m_size<str.size())
		return 1;
	else
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_data[i] < str[i])
				return -1;
			else if (m_data[i]>str[i])
				return 1;
		}
		return 0;
	}
}
int string::compare(size_t pos, size_t len, const string& str) const
{
	string temp1(*this, pos, len);
	return temp1.compare(str);
}
int string::compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const
{
	string temp2(str, subpos, sublen);
	return compare(pos,len,temp2);
}
int string::compare(const char* s) const
{
	string temp(s);
	return compare(temp);
}
int string::compare(size_t pos, size_t len, const char* s) const
{
	string temp(s);
	return compare(pos, len, temp);
}
int string::compare(size_t pos, size_t len, const char* s, size_t n) const
{
	string temp2(s, n);;
	return compare(pos,len,temp2);
}
string operator+ (const string& lhs, const string& rhs)
{
	string temp;
	temp.append(lhs);
	temp.append(rhs);
	return temp;
}
string operator+ (const string& lhs, const char*   rhs)
{
	string temp(rhs);
	return lhs + temp;
}
string operator+ (const char*   lhs, const string& rhs)
{
	string temp(lhs);
	return temp + rhs;
}
string operator+ (const string& lhs, char rhs)
{
	string temp(1, rhs);
	return lhs + temp;
}
string operator+ (char          lhs, const string& rhs)
{
	string temp(1, lhs);
	return temp + rhs;
}
bool operator== (const string& lhs, const string& rhs)
{
	int check=lhs.compare(rhs);
	if (check == 0)
		return true;
	else return false;
}
bool operator== (const char*   lhs, const string& rhs)
{
	int check = rhs.compare(lhs);
	if (check == 0)
		return true;
	else return false;
}
bool operator== (const string& lhs, const char*   rhs)
{
	int check = lhs.compare(rhs);
	if (check == 0)
		return true;
	else return false;
}
bool operator!= (const string& lhs, const string& rhs)
{
	if (lhs == rhs)
		return false;
	else return true;
}
bool operator!= (const char*   lhs, const string& rhs)
{
	if (lhs == rhs)
		return false;
	else return true;
}
bool operator!= (const string& lhs, const char*   rhs)
{
	if (lhs == rhs)
		return false;
	else return true;
}
bool operator<  (const string& lhs, const string& rhs)
{
	int check = lhs.compare(rhs);
	if (check == -1)
		return true;
	else return false;
}
bool operator<  (const char*   lhs, const string& rhs)
{
	int check = rhs.compare(lhs);
	if (check == 1)
		return true;
	else return false;
}
bool operator<  (const string& lhs, const char*   rhs)
{
	int check = lhs.compare(rhs);
	if (check == -1)
		return true;
	else return false;
}
bool operator<= (const string& lhs, const string& rhs)
{
	int check = lhs.compare(rhs);
	if (check == 1)
		return false;
	else return true;
}
bool operator<= (const char*   lhs, const string& rhs)
{
	int check = rhs.compare(lhs);
	if (check == 1)
		return false;
	else return true;
}
bool operator<= (const string& lhs, const char*   rhs)
{
	int check = lhs.compare(rhs);
	if (check == 1)
		return false;
	else return true;
}
bool operator>  (const string& lhs, const string& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
bool operator>  (const char*   lhs, const string& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
bool operator>  (const string& lhs, const char*   rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
bool operator>= (const string& lhs, const string& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
bool operator>= (const char*   lhs, const string& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
bool operator>= (const string& lhs, const char*   rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
std::ostream& operator<< (std::ostream& os, const string& str)
{
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		os << str[i];
	}
	return os;
}
std::istream& operator>> (std::istream& is, string& str)
{
	char temp[100];
	is >> temp;
	size_t size = 0;
	char temp2 = temp[0];
	str.clear();
	while (temp2 != '\0')
	{
		size++;
		temp2 = temp[size];
	}
	str.m_capacity = 15;
	str.m_size = size;
	while (str.m_capacity < size)
		str.m_capacity += 15;
	str.m_data = new char[size + 1];
	for (size_t i = 0; i < size; i++)
		str.m_data[i] = temp[i];
	str.m_data[size] = '\0';
	return is;
}
//std::istream& getline(std::istream& is, string& str)
//{
//	std::vector<char> temp;
//	char temp2;
//	is >> temp2;
//	while (temp2 != 13)
//	{
//		temp.push_back(temp2);
//		is >> temp2;
//		std::cout << temp2;
//	}
//	str.m_capacity = 15;
//	str.m_size = temp.size();
//	while (str.m_capacity < str.m_size)
//		str.m_capacity += 15;
//	str.m_data = new char[str.m_size + 1];
//	for (size_t i = 0; i < str.m_size; i++)
//		str.m_data[i] = temp[i];
//	str.m_data[str.m_size] = '\0';
//	return is;
//}
std::istream& getline(std::istream& is,string& str, char delim)
{
	char ch = is.peek();
	while (!is.eof() && (ch == ' ' || ch == '\n'))
	{
		is.get();
		ch = is.peek();
	}
	if (str.m_data != NULL)
	{
		str.clear();
	}
	char Str[100];
	size_t count = 0;
	while (!is.eof() && (ch != delim) && count < 100)
	{
		is.get();
		Str[count++] = ch;
		ch = is.peek();
	}
	str = new char[count + 1];
	memcpy(str.m_data, Str, sizeof(char)*count);
	str[count] = '\0';
	str.m_size = count;
	return is;
}
std::istream& getline(std::istream& is, string& str)
{
	char ch = is.peek();
	while (!is.eof() && (ch == ' ' || ch == '\n'))
	{
		is.get();
		ch = is.peek();
	}
	if (str.m_data != NULL)
	{
		str.clear();
	}
	char Str[100];
	size_t count = 0;
	while (!is.eof() && (ch != '\n') && count < 100)
	{
		is.get();
		Str[count++] = ch;
		ch = is.peek();
	}
	str = new char[count + 1];
	memcpy(str.m_data, Str, sizeof(char)*count);
	str[count] = '\0';
	str.m_size = count;
	return is;
}