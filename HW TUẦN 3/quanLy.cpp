#include "quanLy.h"
void quanLy::nhapKhoa()
{
	Khoa a;
	int selection;
	do{
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45)<<"NHAP KHOA\n\n";
		std::cout << "================================================================================\n\n";
		std::string mKhoa, tKhoa;
		int nThanhLap, dem, size = K.size();
		//kiểm tra xem mã khoa có trùng lặp hay không
		do{
			fflush(stdin);
			std::cout << "\t\t\tNhap ma khoa  :  ";
			std::getline(std::cin, mKhoa);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			dem = 0;
			for (int i = 0; i < size; i++)
			{
				if (mKhoa == K[i].getMaKhoa())
				{
					dem++;
					break;
				}
			}
			if (dem != 0)
			{
				std::cout << "\t\t!!! MA KHOA DA TON TAI!!!\n\t    !!!VUI LONG NHAP LAI MA KHOA MOI!!!\n\n";
			}
		} while (dem != 0);
		a.setMaKhoa(mKhoa);
		//kiểm tra xem tên khoa có trùng lặp hay không
		do{
			fflush(stdin);
			std::cout << "\t\t\tNhap ten Khoa  :  ";
			std::getline(std::cin, tKhoa);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			dem = 0;
			for (int i = 0; i < size; i++)
			{
				if (tKhoa == K[i].gettenKhoa())
				{
					dem++;
					break;
				}
			}
			if (dem != 0)
			{
				std::cout << "\t\t!!! TEN KHOA DA TON TAI!!!\n\t    !!!VUI LONG NHAP LAI TEN KHOA MOI!!!\n\n";
			}
		} while (dem != 0);
		a.setTenKhoa(tKhoa);
		std::cout << "\t\t\tNhap nam thanh lap  :  ";
		std::cin >> nThanhLap;
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setNamThanhLap(nThanhLap);
		K.push_back(a);
		do{
			std::cout << " \t\tBan Co Muon Nhap Them Khoa Hay Khong?\n";
			std::cout << "\t\t\t1. CO.\n";
			std::cout << "\t\t\t0. KHONG.\n";
			std::cout << "\n\tNhap lua chon cua ban  :  ";;
			std::cin >> selection;
			if (selection > 1 || selection < 0)
			{
				std::cout << "\n\n\t\t!!! LUA CHON KHONG HOP LE!!!\n\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!\n\n";
				std::cout << "--------------------------------------------------------------------------------\n\n";
			}
		} while (selection > 1 || selection < 0);
	} while (selection == 1);
}
void quanLy::nhapMonHoc()
{
	std::string maMH, makh, tenMH;
	int tinC, selection;
	//vòng lặp cho phép nhập nhiều môn học

	do{
		system("cls");
		monHoc a;
		//in ra danh sách các mã khoa để người dùng nhập các mã khoa đã có sẵn
		std::cout << "================================================================================\n\n";
		std::cout <<std::setw(45)<< "NHAP MON HOC\n\n";
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(25) << " MA KHOA " << std::setw(22) << " TEN KHOA \n";
		int size = K.size();
		for (int i = 0; i < size; i++)
		{
			std::cout  << std::setw(23) << K[i].getMaKhoa() << std::setw(20) << K[i].gettenKhoa() << std::endl;
		}
		std::cout << "\n================================================================================\n\n";
		int dem = 0;
		//vòng lặp để nhâp mã khoa
		//Nếu mã khoa nhập không có thì yêu cầu nhập lại mã khoa
		do{
			fflush(stdin);
			std::cout << "\t\t\tNhap ma khoa ( mon hoc nay thuoc khoa nao ) :  ";
			std::getline(std::cin, makh);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			for (int i = 0; i < size; i++)
			{
				if (makh == K[i].getMaKhoa())
				{
					dem++;
					break;
				}
			}
			if (dem == 0)
			{
				std::cout << "\t\t!!!KHONG CO MA KHOA NAY!!!\n\t      !!!VUI LONG NHAP LAI MA KHOA!!!\n\n";
				std::cout << "--------------------------------------------------------------------------------\n\n";
			}
		} while (dem == 0);
		a.setMaKhoa(makh);
		fflush(stdin);
		std::cout << " \t\t\tNhap ma mon hoc : ";
		std::getline(std::cin, maMH);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setMaMonHoc(maMH);
		fflush(stdin);
		std::cout << "\t\t\tNhap ten mon hoc : ";
		std::getline(std::cin, tenMH);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setTenMonHoc(tenMH);
		std::cout << "\t\t\tNhap so tin chi : ";
		std::cin >> tinC;
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setTinChi(tinC);
		mHoc.push_back(a);
		//vòng lặp hỏi có muốn tiếp tục nhập môn học hay không ?
		do{
			std::cout << " \t\tBan Co Muon Nhap Them Mon Hoc Hay Khong?\n";
			std::cout << "\t\t\t1. CO.\n";
			std::cout << "\t\t\t0. KHONG.\n";
			std::cout << "\n\tNhap lua chon cua ban : ";;
			std::cin >> selection;
			if (selection > 1 || selection < 0)
			{
				std::cout << "\n\n\t\t!!! LUA CHON KHONG HOP LE!!!\n\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!\n\n";
				std::cout << "--------------------------------------------------------------------------------\n\n";
			}
		} while (selection > 1 || selection < 0);
	} while (selection == 1);
}
void quanLy::nhapHocPhan()
{
	hocPhan a;
	std::string maMH, maHP,tenGV;
	int nam,hocki, selection;
	//vòng lặp cho phép nhập nhiều học phần
	do{
		//in ra danh sách các mã học phần để người dùng nhập các mã học phần đã có sẵn
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << "NHAP HOC PHAN\n\n";
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(25) << " MA MON HOC" << std::setw(22) << " TEN MON HOC \n";
		int size = mHoc.size();
		for (int i = 0; i < size; i++)
		{
			std::cout << std::setw(23) << mHoc[i].getMaMonHoc() << std::setw(20) << mHoc[i].getTenMonHoc() << std::endl;
		}
		std::cout << "\n================================================================================\n\n";
		int dem;
		//vòng lặp để nhâp mã mon hoc
		//Nếu mã mon hoc nhập không có thì yêu cầu nhập lại mã khoa
		do{
			fflush(stdin);
			std::cout << "\t\tNhap ma mon hoc ( hoc phan nay thuoc mon hoc nao ) :  ";
			std::getline(std::cin, maMH);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			dem = 0;
			for (int i = 0; i < size; i++)
			{
				if (maMH == mHoc[i].getMaMonHoc())
				{
					dem++;
					break;
				}
			}
			if (dem == 0)
			{
				std::cout << "\t\t!!!KHONG CO MA MON HOC NAY!!!\n\t      !!!VUI LONG NHAP LAI MA MON HOC!!!";
				std::cout << "\n--------------------------------------------------------------------------------\n\n";
			}
		} while (dem == 0);
		a.setMaMonHoc(maMH);
		fflush(stdin);
		std::cout << "\t\t\tNhap ma hoc phan : ";
		std::getline(std::cin, maHP);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setMaHocPhan(maHP);
		fflush(stdin);
		std::cout << "\t\t\tNhap giao vien : ";
		std::getline(std::cin, tenGV);
		a.setGiaoVien(tenGV);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		std::cout << "\t\t\tNhap nam : ";
		std::cin >> nam;
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setNam(nam);
		std::cout << "\t\t\tNhap hoc ki : ";
		std::cin >> hocki;
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		a.setHocKi(hocki);
		hPhan.push_back(a);
		//vòng lặp hỏi có muốn tiếp tục nhập học phần hay không ?
		do{
			std::cout << " \t\tBan Co Muon Nhap Them Hoc Phan Hay Khong?\n";
			std::cout << "\t\t\t1. CO.\n";
			std::cout << "\t\t\t0. KHONG.\n";
			std::cout << "--------------------------------------------------------------------------------\n\n";
			std::cout << "\n\tNhap lua chon cua ban : ";;
			std::cin >> selection;
			if (selection > 1 || selection < 0)
			{
				std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			}
		} while (selection > 1 || selection < 0);
	} while (selection == 1);
}
void quanLy::nhapSinhVien()
{
	sinhVien a;
	std::string maSV, makh, tenSV;
	int Nam, selection;
	//vòng lặp cho phép nhập nhiều sinh viên 
	do{
		//in ra danh sách các mã khoa để người dùng nhập các mã khoa đã có sẵn
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << "NHAP SINH VIEN\n\n";
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(25) << " MA KHOA " << std::setw(22) << " TEN KHOA \n";
		int size = K.size();
		for (int i = 0; i < size; i++)
		{
			std::cout << std::setw(23) << K[i].getMaKhoa() << std::setw(20) << K[i].gettenKhoa() << std::endl;
		}
		std::cout << "\n================================================================================\n\n";
		int dem ;
		//vòng lặp để nhâp mã khoa
		//Nếu mã khoa nhập không có thì yêu cầu nhập lại mã khoa
		do{
			fflush(stdin);
			std::cout << "\t\tNhap ma khoa (sinh vien thuoc khoa nao) :  ";
			std::getline(std::cin, makh);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			dem = 0;
			for (int i = 0; i < size; i++)
			{
				if (makh == K[i].getMaKhoa())
				{
					dem++;
					break;
				}
			}
			if (dem == 0)
			{
				std::cout << "\t\t!!!KHONG CO MA KHOA NAY!!!\n\n\t      !!!VUI LONG NHAP LAI MA KHOA!!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			}
		} while (dem == 0);
		a.setMaKhoa(makh);
	fflush(stdin);
	std::cout << " \t\t\tNhap ten sinh vien : "; 
	std::getline(std::cin, tenSV);
	a.setTenSinhVien(tenSV);
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	//kiểm tra xem tên khoa có trùng lặp hay không
	do{
		fflush(stdin);
		std::cout << " \t\t\tNhap ma sinh vien : ";
		std::getline(std::cin, maSV);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		dem = 0;
		for (int i = 0; i < sVien.size(); i++)
		{
			if (maSV == sVien[i].getMaSinhVien())
			{
				dem++;
				break;
			}
		}
		if (dem != 0)
		{
			std::cout << "\t\t!!! MA SINH VIEN DA TON TAI!!!\n\t    !!!VUI LONG NHAP LAI MA SINH VIEN MOI!!!";
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
		}
	} while (dem != 0);
	a.setMaSinhVien(maSV);
	std::cout << "\t\t\tNhap nam sinh : ";
	std::cin >> Nam;
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	a.setNam(Nam);
	sVien.push_back(a);
	//vòng lặp hỏi có muốn tiếp tục nhập học phần hay không ?
	do{
		std::cout << " \t\tBan Co Muon Nhap Them Sinh Vien Hay Khong?\n";
		std::cout << "\t\t\t1. CO.\n";
		std::cout << "\t\t\t0. KHONG.\n";
		std::cout << "--------------------------------------------------------------------------------\n\n";
		std::cout << "\n\tNhap lua chon cua ban : ";
		std::cin >> selection;
		if (selection > 1 || selection < 0)
		{
			std::cout << "\n\n\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
			std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
		}
	} while (selection > 1 || selection < 0);
	} while (selection == 1);
}
void quanLy::nhapKetQua()
{
	ketQua a;
	std::string maSV, maHP;
	float diem;
	int  selection;
	//vòng lặp cho phép nhập nhiều sinh viên 
	do{
		//in ra danh sách các mã sinh viên để người dùng nhập các mã mã sinh viên đã có sẵn
		system("cls");
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(45) << "NHAP KET QUA\n\n";
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(25) << " MA SINH VIEN " << std::setw(22) << " TEN SINH VIEN \n";
		int size = sVien.size();
		for (int i = 0; i < size; i++)
		{
			std::cout << std::setw(24) << sVien[i].getMaSinhVien() << std::setw(22) << sVien[i].getTenSinhVien() << std::endl;
		}
		std::cout << "\n================================================================================\n\n";

		int dem = 0;
		//vòng lặp để nhâp mã khoa
		//Nếu mã khoa nhập không có thì yêu cầu nhập lại mã khoa
		do{
			fflush(stdin);
			std::cout << "\n\t\tNhap ma sinh vien ( sinh vien can nhap diem) :  ";
			std::getline(std::cin, maSV);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			for (int i = 0; i < size; i++)
			{
				if (maSV == sVien[i].getMaSinhVien())
				{
					dem++;
					break;
				}
			}
			if (dem == 0)
			{
				std::cout << "\n\t\t!!!KHONG CO MA SINH VIEN NAY!!!\n\t      !!!VUI LONG NHAP LAI MA SINH VIEN!!!";
				std::cout << "\n--------------------------------------------------------------------------------\n\n";
			}
		} while (dem == 0);
		a.setMaSinhVien(maSV);
		std::cout << "================================================================================\n\n";
		std::cout << std::setw(35) << " MA HOC PHAN\n";
		int size2 = hPhan.size();
		for (int i = 0; i < size2; i++)
		{
			std::cout << std::setw(30) << hPhan[i].getMaHocPhan() << std::endl;
		}
		std::cout << "\n================================================================================\n\n";
		int dem2 = 0;
		//vòng lặp để nhâp mã khoa
		//Nếu mã khoa nhập không có thì yêu cầu nhập lại mã khoa
		do{
			fflush(stdin);
			std::cout << "\n\t\tNhap ma hoc phan can nhap diem :  ";
			std::getline(std::cin, maHP);
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			for (int i = 0; i < size2; i++)
			{
				if (maHP == hPhan[i].getMaHocPhan())
				{
					dem2++;
					break;
				}
			}
			if (dem2 == 0)
			{
				std::cout << "\n\n\t\t!!!KHONG CO MA HOC PHAN NAY!!!\n\t      !!!VUI LONG NHAP LAI MA HOC PHAN!!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			}
		} while (dem2 == 0);
		a.setMaHocPhan(maHP);
		std::cout << "\n\t\tNhap diem cho hoc phan nay : ";
		std::cin >> diem;
		a.setDiem(diem);
		std::cout << "\n--------------------------------------------------------------------------------\n\n";
		kQua.push_back(a);
		//vòng lặp hỏi có muốn tiếp tục nhập kết quả hay không ?
		do{
			std::cout << " \n\n\t\tBan Co Muon Nhap Them Ket Qua Hay Khong?\n";
			std::cout << "\t\t\t1. CO.\n";
			std::cout << "\t\t\t0. KHONG.\n";
			std::cout << "--------------------------------------------------------------------------------\n\n";
			std::cout << "\n\tNhap lua chon cua ban : ";;
			std::cin >> selection;
			if (selection > 1 || selection < 0)
			{
				std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
				std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			}
		} while (selection > 1 || selection < 0);
	} while (selection == 1);
}
void quanLy::xemBangDiem(std::string MSSV)
{
	std::vector<int> array1, array2;
	int size1 = kQua.size();
	//Tìm các kết quả 
	for (int i = 0; i < size1; i++)
	{
		if (MSSV == kQua[i].getMaSinhVien())
		{
			array1.push_back(i);
		}
	}
	//Tìm các mã học phần
	for (int i = 0; i < array1.size(); i++)
	{
		for (int j = 0; j <hPhan.size(); j++)
		{
			if (kQua[array1[i]].getMaHocPhan() == hPhan[j].getMaHocPhan())
			{
				array2.push_back(j);
			}
		}
	}
	//tìm tên sinh vien
	for (int i = 0; i < sVien.size(); i++)
	{
		if (MSSV == sVien[i].getMaSinhVien())
		{
			std::cout << "--------------------------------------------------------------------------------\n\n";
			std::cout <<std::setw(45)<< sVien[i].getTenSinhVien()<<"\n\n";
			break;
		}
	}
	std::cout  << std::setw(24) << "MA HOC PHAN" << std::setw(22) <<"DIEM" << std::endl;
	//in ra ket qua cua sinh vien
	for (int i = 0; i < array1.size(); i++)
	{
		std::cout << std::setw(22) << hPhan[array2[i]].getMaHocPhan() << std::setw(20) << kQua[array1[i]].getDiem() << "\n";
	}
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	system("pause");
}
void quanLy::xuatSinhVien()
{ 
	for (int h = 0; h < sVien.size();h++)
	{ 
		std::cout << std::setw(45) << sVien[h].getTenSinhVien();
		std::cout << "\n\n" << std::setw(10) << "MSSV" << std::setw(10) << "Nam" << std::setw(20) << "Khoa";
		std::vector<int> array1, array2;
		int size1 = kQua.size();
		//Tìm các kết quả 
		for (int i = 0; i < size1; i++)
		{
			if (sVien[h].getMaSinhVien() == kQua[i].getMaSinhVien())
			{
				array1.push_back(i);
			}
		}
		//Tìm các mã học phần
		for (int i = 0; i < array1.size(); i++)
		{
			for (int j = 0; j <hPhan.size(); j++)
			{
				if (kQua[array1[i]].getMaHocPhan() == hPhan[j].getMaHocPhan())
				{
					array2.push_back(j);
				}
			}
		}
		//Tim khoa cua sinh vien
		int chiSoKhoa;
		for (int i = 0; i < K.size(); i++)
		{ 
			if (sVien[h].getMaKhoa() == K[i].getMaKhoa())
			{
				chiSoKhoa = i;
				break;
			}
		}
		//in ra ket qua cua sinh vien
		for (int i = 0; i < array1.size(); i++)
		{
			std::cout << std::setw(22) << hPhan[array2[i]].getMaHocPhan();
		}
		std::cout << "\n" << std::setw(10) << sVien[h].getMaSinhVien() << std::setw(10) << sVien[h].getNam() << std::setw(20) << K[chiSoKhoa].gettenKhoa();
		for (int i = 0; i < array1.size(); i++)
		{
			std::cout << std::setw(22) << kQua[array1[i]].getDiem() ;
		}
		std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
	}
}
template <class T> 
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void quanLy::xuatDanhSachDiemCao()
{
	std::vector<float> mangDiem;
	std::vector<int> thuTu;
	//Vòng for tính tổng điêm của các sinh viên
	for (int h = 0; h < sVien.size(); h++)
	{
		std::cout << std::setw(45) << sVien[h].getTenSinhVien();
		std::vector<int> array1, array2, array3;
		int size1 = kQua.size();
		//Tìm các kết quả 
		for (int i = 0; i < size1; i++)
		{
			if (sVien[h].getMaSinhVien() == kQua[i].getMaSinhVien())
			{
				array1.push_back(i);
			}
		}
		//Tìm các mã học phần
		for (int i = 0; i < array1.size(); i++)
		{
			for (int j = 0; j < hPhan.size(); j++)
			{
				if (kQua[array1[i]].getMaHocPhan() == hPhan[j].getMaHocPhan())
				{
					array2.push_back(j);
				}
			}
		}
		//tìm môn học thông qua mã học phần
		for (int i = 0; i < array2.size(); i++)
		{
			for (int j = 0; j < mHoc.size(); j++)
			{
				if (hPhan[array2[i]].getMaMonHoc() == mHoc[i].getMaMonHoc())
				{
					array3.push_back(j);
				}
			}
		}
		//tính tổng điểm của sinh viên thứ h
		float sum=0;
		int tongTinChi=0;
		for (int i = 0; i < array1.size(); i++)
		{
			sum += kQua[array1[i]].getDiem()*hPhan[array3[i]].getTinChi();
			tongTinChi += hPhan[array3[i]].getTinChi();
		}
		sum = sum / tongTinChi;
		mangDiem.push_back(sum);
	}
	//gán thứ tự từng sinh viên ứng với từng phần tử
	for (int i = 0; i < sVien.size(); i++)
	{
		thuTu.push_back(i );
	}
	//Sắp xếp thứ tự điểm của sinh viên qua tổng điểm 
	//Chỉ sắp xếp trến mảng thuTu
	for (int i = 0; i < sVien.size()-1; i++)
	{
		for (int j = i + 1; j < sVien.size(); j++)
		{
			if (mangDiem[i] < mangDiem[j])
			{
				swap(mangDiem[i], mangDiem[j]);
				swap(thuTu[i], thuTu[j]);
			}
		}
	}

	//Xuat top sinh vien co diem cao
	std::cout << std::setw(20) << "\n\nSTT" << std::setw(15) << "MSSV" << std::setw(25) << "Ho Va Ten" << std::setw(15) << "Tong Diem\n";
	if (sVien.size() < 10)
	{
		for (int i = 0; i < sVien.size(); i++)
		{
			std::cout << std::setw(20) << i + 1 << std::setw(15) << sVien[thuTu[i]].getMaSinhVien() << std::setw(25) << sVien[thuTu[i]].getTenSinhVien()<< std::setw(15) << mangDiem[i]<<"\n";
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::setw(20) << i + 1 << std::setw(15) << sVien[thuTu[i]].getMaSinhVien() << std::setw(25) << sVien[thuTu[i]].getTenSinhVien() << std::setw(15) << mangDiem[i] << "\n";
		}
	}
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	system("pause");
}
void quanLy::menu()
{ 
	int selection,selection2;

	do{
		system("cls");
		std::cout << "\n================================================================================\n\n";
		std::cout << std::setw(45) << " MENU \n\n";
		std::cout << "\t\t\t\t1 . Nhap  \n";
		std::cout << "\t\t\t\t2 . Xuat Danh Sach Sinh Vien\n";
		std::cout << "\t\t\t\t3 . Tim Diem Sinh Vien \n";
		std::cout << "\t\t\t\t4 . Xuat Danh Sach Sinh Vien Co Tong Diem Cao\n";
		std::cout << "\t\t\t\t0 . Thoat\n";
		std::cout << "\n================================================================================\n\n";
		std::cout << "\t\t\t Nhap lua chon : ";
		std::cin >> selection;
		std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
		if (selection<0 || selection>4)
		{
			std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
			std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			system("pause");
		}

		else if (selection == 0)
		{
			std::cout << "\t\t\t    Cam On Ban\n";
		}
		else if (selection == 1)
		{
			do{
				system("cls");
				std::cout << "================================================================================\n\n";
				std::cout << std::setw(45) << " 1. NHAP \n\n";
				std::cout << "================================================================================\n\n";
				std::cout << "\t\t\t Quy Trinh Nhap Sinh Vien \n\n";
				std::cout << "LUU Y QUY TRINH: Nhap khoa -> Nhap Mon Hoc -> Nhap Hoc Phan -> Nhap SinhVien -> Nhap Ket Qua \n\n ";
				std::cout << "================================================================================\n\n";
				std::cout << "\t\t\t\t1 . Nhap Khoa  \n";
				std::cout << "\t\t\t\t2 . Nhap Mon Hoc \n";
				std::cout << "\t\t\t\t3 . Nhap Hoc Phan \n";
				std::cout << "\t\t\t\t4 . Nhap Sinh Vien \n";
				std::cout << "\t\t\t\t5 . Nhap Ket Qua \n";
				std::cout << "\t\t\t\t0 . Quay Lai MENNU\n";
				std::cout << "\n================================================================================\n\n";
				std::cout << "\t\t\t Nhap lua chon : ";
				std::cin >> selection2;
				if (selection2<0 || selection2>5)
				{
					std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					system("pause");
				}
				else if (selection2 == 1)
				{
					nhapKhoa();
				}
				else if (selection2 == 2)
				{
					if (K.size() == 0)
					{
						std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						std::cout << "\t\t!!! CHUA CO THONG TIN VE KHOA !!!\n\t     !!!VUI LONG NHAP KHOA TRUOC KHI NHAP MON HOC!!!";
						std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					}
					else nhapMonHoc();

					system("pause");
				}
				else if (selection2 == 3)
				{
					if (K.size() == 0 || mHoc.size() == 0)
					{
						if (K.size() == 0)
						{
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
							std::cout << "\t\t!!! CHUA CO THONG TIN VE KHOA !!!\n\t     !!!VUI LONG NHAP KHOA TRUOC KHI NHAP HOC PHAN!!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}
						if (mHoc.size() == 0)
						{
							std::cout << "\t\t!!! CHUA CO THONG TIN VE MON HOC !!!\n\t     !!!VUI LONG NHAP MON HOC TRUOC KHI NHAP HOC PHAN!!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}
					}
					else nhapHocPhan();

					system("pause");
				}
				else if (selection2 == 4)
				{
					if (K.size() == 0)
					{
						std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						std::cout << "\t\t!!! CHUA CO THONG TIN VE KHOA !!!\n\t     !!!VUI LONG NHAP KHOA TRUOC KHI NHAP SINH VIEN!!!";
						std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
					}
					else nhapSinhVien();

					system("pause");
				}
				else if (selection2 == 5)
				{
					if (sVien.size() == 0 || hPhan.size() == 0 || K.size() == 0 || mHoc.size() == 0)
					{
						if (K.size() == 0)
						{
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
							std::cout << "\t\t!!! CHUA CO THONG TIN VE KHOA !!!\n\t     !!!VUI LONG NHAP KHOA TRUOC KHI NHAP KET QUA!!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}
						if (mHoc.size() == 0)
						{
							std::cout << "\t\t!!! CHUA CO THONG TIN VE MON HOC !!!\n\t     !!!VUI LONG NHAP MON HOC TRUOC KHI NHAP KET QUA!!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}

						if (sVien.size() == 0)
						{
							std::cout << "\t\t!!! CHUA CO THONG TIN VE SINH VIEN !!!\n\t     !!!VUI LONG NHAP SINH VIEN TRUOC KHI NHAP KET QUA!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}
						if (hPhan.size() == 0)
						{
							std::cout << "\t\t!!! CHUA CO THONG TIN VE HOC PHAN !!!\n\t     !!!VUI LONG NHAP HOC PHAN TRUOC KHI NHAP KET QUA!!!";
							std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
						}
					}
					else nhapKetQua();

					system("pause");
				}
			} while (selection2 != 0);
		}
		else if (selection == 2)
		{
			system("cls");
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 2. XUAT DANH SACH SINH VIEN \n\n";
			std::cout << "================================================================================\n\n";
			if (sVien.size() == 0)
			{
				std::cout << "\t\t\t CHUA CO SINH VIEN \n\n";
			}
			else xuatSinhVien();

			system("pause");

		}
		else if (selection==3)
		{
			std::string MSSV;
			int dem;
			system("cls");
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 3. XEM DIEM SINH VIEN \n\n";
			std::cout << "================================================================================\n\n";
			do{
				fflush(stdin);
				std::cout << "\t\t   Nhap MSSV cau sinh vien can xem diem : ";
				std::getline(std::cin, MSSV);
				std::cout << "\n--------------------------------------------------------------------------------\n\n";
				dem = 0;
				for (int i = 0; i < sVien.size(); i++)
				{
					if (MSSV == sVien[i].getMaSinhVien())
					{
						dem++;
						break;
					}
				}
				if (dem == 0)
				{
					std::cout << "\n\n\t\t!!!KHONG TIM THAY MSSV NAY!!!\n\n\t      !!!VUI LONG NHAP LAI MSSV!!!";
					std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
				}
			} while (dem == 0);
			xemBangDiem(MSSV);
		}
		else
		{
			system("cls");
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(38) << "4 . Xuat Danh Sach Sinh Vien Co Tong Diem Cao\n";
			std::cout << "================================================================================\n\n";
			if (sVien.size() == 0)
			{
				std::cout << "\t\t\t CHUA CO SINH VIEN \n\n";
			}
			else xuatDanhSachDiemCao();

			system("pause");
		}
	} while (selection != 0);
}