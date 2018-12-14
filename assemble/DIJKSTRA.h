#include "gr.h"
struct DIST
{
	int m_value;
	int m_parent;
};
class dijkstra:public GRAPH
{
public:
	void agorithmDijkstra();
};