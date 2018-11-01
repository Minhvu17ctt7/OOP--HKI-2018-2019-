#ifndef __KETQUA_H__
#define __KETQUA_H__
#include "hocPhan.h"
#include "sinhVien.h"
class ketQua :public hocPhan, public sinhVien
{
private:
	float Diem;
public:
	void setDiem(float);
	float getDiem();
};
#endif