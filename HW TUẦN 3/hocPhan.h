#ifndef __HOCPHAN_H__
#define __HOCPHAN_H__
#include "monHoc.h"
class hocPhan :public monHoc
{
protected:
	std::string maHocPhan;
private:
	int hocKi;
	int Nam;
	std::string giaoVien;
public:
	void setMaHocPhan(std::string);
	std::string getMaHocPhan();
	void setHocKi(int);
	int getHocKi();
	void setNam(int);
	int getNam();
	void setGiaoVien(std::string);
	std::string getGiaoVien();
};
#endif