#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
class string
{
private:
	char* m_data;
	size_t m_size;
	size_t m_capacity;
	
public:
	static const size_t npos = -1;
	string();
	string(const string &);
	string(const string& str,size_t,size_t);
	string(const char*);
	string(const char*, size_t);
	string(size_t, char);
	template <class InputIterator>
	string(InputIterator first, InputIterator last);
	string(char*, char*);
	~string();

	string& operator= (const string&);
	string& operator= (const char*);
	string& operator= (char c);
	char& operator[] (size_t);
	const char& operator[] (size_t) const;
	char & at(size_t pos);
	const char & at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	friend std::ostream& operator<< (std::ostream&, const string&);
	//capacity
	size_t size() const;
	size_t length() const;
	size_t max_size() const;
	void resize(size_t );
	void resize(size_t, char);
	size_t capacity() const;
	void reserve(size_t );
	void clear();
	bool empty() const;
	void shrink_to_fit();
	//iterator
	char* begin();
	const char* begin() const;
	char* end();
	const char* end() const;
	char* rbegin();
	const char* rbegin() const;
	char* rend();
	const char* rend() const;
	char* cbegin();
	char* cend();
	//Modifiers
	string& operator+= (const string& str);
	string& operator+= (const char* s);
	string& operator+= (char c);
	string& append(const string&);
	string& append(const string&, size_t, size_t);
	string& append(const char*);
	string& append(const char*, size_t);
	string& append(size_t , char);
	string& append(char*, char*);
	void push_back(char);
	string& assign(const string&);
	string& assign(const string&, size_t, size_t);
	string& assign(const char*);
	string& assign(const char*, size_t);
	string& assign(size_t, char);
	string& assign(char*,char*);
	string& insert(size_t, const string&);
	string& insert(size_t, const string&, size_t, size_t);
	string& insert(size_t, const char*);
	string& insert(size_t, const char*, size_t);
	string& insert(size_t, size_t, char);
	void insert(char*, size_t, char);
	char* insert (char*, char);
	void insert(char*,char*,char*);
	string& erase(size_t , size_t );
	char* erase(char*);
		char* erase(char*,char*);
	string& replace(size_t pos, size_t len, const string& str);
	string& replace(size_t pos, size_t len, const string& str,size_t subpos, size_t sublen);
	string& replace(size_t pos, size_t len, const char* s);
	string& replace(size_t pos, size_t len, const char* s, size_t n);
   string& replace(size_t pos, size_t len, size_t n, char c);
   string& replace(char*, char*,char*, char*);
   void swap(string& str);
   void pop_back();
   //String operations
   const char* c_str() const;
   const char* data() const;
   size_t copy(char*, size_t, size_t) const;
   size_t find(const string&, size_t) const;
   size_t find(const char*, size_t) const;
  size_t find(const char*, size_t, size_t) const;
	size_t find(char, size_t) const;
	size_t rfind(const string&, size_t ) const;
	size_t rfind(const char*, size_t) const;
	size_t rfind(const char*, size_t, size_t) const;
	size_t rfind(char, size_t ) const;
	size_t find_first_of(const string&, size_t ) const;
	size_t find_first_of(const char* , size_t ) const;
	size_t find_first_of(const char* , size_t, size_t) const;
	size_t find_first_of(char, size_t) const;
	size_t find_last_of(const string& , size_t) const;
	size_t find_last_of(const char*, size_t) const;
	size_t find_last_of(const char*, size_t, size_t) const;
	size_t find_last_of(char, size_t) const;
	size_t find_first_not_of(const string&, size_t) const;
	size_t find_first_not_of(const char*, size_t) const;
	size_t find_first_not_of(const char*, size_t, size_t) const;
	size_t find_first_not_of(char, size_t) const;
	size_t find_last_not_of(const string&, size_t) const;
	size_t find_last_not_of(const char*, size_t) const;
	size_t find_last_not_of(const char*, size_t, size_t) const;
	size_t find_last_not_of(char, size_t) const;
	string substr(size_t , size_t ) const;
	int compare(const string& ) const;
	int compare(size_t, size_t, const string&) const;
	int compare(size_t, size_t, const string&, size_t, size_t) const;
	int compare(const char*) const;
	int compare(size_t, size_t, const char*) const;
	int compare(size_t, size_t, const char*, size_t) const;

	friend string operator+ (const string& , const string&);
	friend string operator+ (const string& , const char* );
	friend string operator+ (const char*  , const string&);
    friend string operator+ (const string& , char          );
	friend string operator+ (char, const string& );
	friend bool operator== (const string&, const string&);
	friend bool operator== (const char* , const string&);
	friend bool operator== (const string&, const char*);
	friend bool operator!= (const string&, const string&);
	friend bool operator!= (const char* , const string&);
	friend bool operator!= (const string&, const char*);
	friend bool operator<  (const string&, const string&);
	friend bool operator<  (const char*, const string&);
	friend bool operator<  (const string&, const char*);
	friend bool operator<= (const string&, const string&);
	friend bool operator<= (const char* , const string&);
	friend bool operator<= (const string&, const char*);
	friend bool operator>  (const string&, const string&);
	friend bool operator>  (const char*, const string&);
	friend bool operator>  (const string&, const char* );
	friend bool operator>= (const string&, const string&);
	friend bool operator>= (const char*, const string&);
	friend bool operator>= (const string&, const char*);
	friend std::istream& operator>> (std::istream&, string&);
	friend std::istream& getline(std::istream&, string&);
	friend std::istream& getline(std::istream&, string&,char);
};
#endif