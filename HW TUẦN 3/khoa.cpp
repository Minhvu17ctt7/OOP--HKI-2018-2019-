#include "khoa.h"
void Khoa::setMaKhoa(std::string MK)
{
	maKhoa = MK;
}
std::string Khoa::getMaKhoa()
{
	return maKhoa;
}
void Khoa::setTenKhoa(std::string ten)
{
	tenKhoa = ten;
}
std::string Khoa::gettenKhoa()
{
	return tenKhoa;
}
void Khoa::setNamThanhLap(int year)
{
	namThanhLap = year;
}
int Khoa::getNamThanhLap()
{
	return namThanhLap;
}