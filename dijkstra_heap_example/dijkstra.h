#include <iostream>
#include <list>
#include <queue>
#define INF 0x3f3f3f3f
typedef std::pair<int, int> Ipair;
class GRAPH
{
private:
	size_t m_size;
	std::list<Ipair> *adj;
public:
	GRAPH(size_t);
	void add_node(int, int, int);
	void dijkstra(int begin,int fish);
};
struct GREATER
{
	bool operator()(Ipair, Ipair);
};
struct DIST
{
	size_t m_value;
	int m_pre;
};