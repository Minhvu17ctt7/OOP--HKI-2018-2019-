#ifndef __SINHVIEN_H__
#define __SINHVIEN_H__
#include "khoa.h"
class sinhVien :public Khoa
{
protected:
	std::string maSinhVien;
private:
	std::string tenSinhVien;
	int Nam;
public:
	void setMaSinhVien(std::string);
	std::string getMaSinhVien();
	void setTenSinhVien(std::string);
	std::string getTenSinhVien();
	void setNam(int);
	int getNam();
};
#endif