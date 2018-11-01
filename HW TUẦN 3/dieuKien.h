#ifndef __DIEUKIEN_H__
#define __DIEUKIEN_H__
#include "monHoc.h"
class dieuKien :public monHoc
{
private:
	std::string maMonHocTruoc;
public:
	void setMaMonHocTruoc(std::string);
	std::string getMaMonHocTruoc();
};
#endif