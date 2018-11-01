#ifndef __MONHOC_H__
#define __MONHOC_H__
#include "khoa.h"
class monHoc:public Khoa
{
protected:
	std::string maMonHoc;
private:
	std::string tenMonHoc;
	int tinChi;
public:
	void setMaMonHoc(std::string);
	std::string getMaMonHoc();
	void setTenMonHoc(std::string);
	std::string getTenMonHoc();
	void setTinChi(int);
	int getTinChi();
};
#endif