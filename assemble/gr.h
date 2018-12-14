#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <list>
#include <queue>
#include <fstream>
#define INF 0x3f3f3f3f 
typedef std::pair<int, int> Ipair;
class GRAPH
{
protected:
	int m_size;
	std::list<Ipair> *m_weight;
public:
	void add_node(int,int,int);
};
struct GREATER
{
	bool operator()(Ipair, Ipair);
};
#endif