#include <iostream>
#include <list>
#include <queue>
#define INF 0x3f3f3f3f
typedef std::pair<int, int> Ipair;
class GRAPH
{
private:
	int m_size;
	std::list<Ipair> *m_adj;
public:
	GRAPH(int);
	void add_node(int, int, int);
	void prim(int);
};
struct GREATER
{
	bool operator()(Ipair, Ipair);
};
struct DIST
{
	bool check;
	int m_value;
	int m_parent;
};