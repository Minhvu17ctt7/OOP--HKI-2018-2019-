#ifndef __QUANLY_H__
#define __QUANLY_H__
#include "dieuKien.h"
#include "hocPhan.h"
#include "ketQua.h"
#include "khoa.h"
#include "monHoc.h"
#include "sinhVien.h"
#include <vector>
#include <iomanip>
class quanLy
{
private :
	std::vector<Khoa> K;
	std::vector<dieuKien> dKien;
	std::vector<hocPhan> hPhan;
	std::vector<ketQua> kQua;
	std::vector<monHoc> mHoc;
	std::vector<sinhVien> sVien;
public:
	void nhapKhoa();
	void nhapSinhVien();
	void nhapHocPhan();
	void nhapKetQua();
	void nhapMonHoc();
	void nhapDieuKien();
	void menu();
	void xemBangDiem(std::string);
	void xuatSinhVien();
	void xuatDanhSachDiemCao();

};
#endif