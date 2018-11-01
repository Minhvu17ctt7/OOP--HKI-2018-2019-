#ifndef __KHOA_H__
#define __KHOA_H__
#include <iostream>
#include <string>
class Khoa
{ 
protected:
	std::string maKhoa;
private:
	std::string tenKhoa;
	int namThanhLap;
public:
	void setMaKhoa(std::string);
	std::string getMaKhoa();
	void setTenKhoa(std::string);
std::string gettenKhoa();
void setNamThanhLap(int);
int getNamThanhLap();
};
#endif