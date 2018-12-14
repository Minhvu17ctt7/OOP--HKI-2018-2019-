#include "gr.h"
struct DIST2
{
	bool m_check;
	int m_value;
	int m_parent;
};
class PRIM :public GRAPH
{
public:
	void agottithmPrim();
};