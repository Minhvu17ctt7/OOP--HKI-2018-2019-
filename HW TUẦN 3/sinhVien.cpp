#include "sinhVien.h"
void sinhVien::setMaSinhVien(std::string MSV)
{
	maSinhVien = MSV;
}
std::string sinhVien::getMaSinhVien()
{
	return maSinhVien;
}
void sinhVien::setTenSinhVien(std::string ten)
{
	tenSinhVien = ten;
}
std::string sinhVien::getTenSinhVien()
{
	return tenSinhVien;
}
void sinhVien::setNam(int year)
{
	Nam = year;
}
int sinhVien::getNam()
{
	return Nam;
}