#include "hocPhan.h"
void hocPhan::setMaHocPhan(std::string MHP)
{
	maHocPhan = MHP;
}
std::string hocPhan::getMaHocPhan()
{
	return maHocPhan;
}
void hocPhan::setHocKi(int HK)
{
	hocKi = HK;
}
int hocPhan::getHocKi()
{
	return hocKi;
}
void hocPhan::setNam(int year)
{
	Nam = year;
}
int hocPhan::getNam()
{
	return Nam;
}
void hocPhan::setGiaoVien(std::string GV)
{
	giaoVien = GV;
}
std::string hocPhan:: getGiaoVien()
{
	return giaoVien;
}