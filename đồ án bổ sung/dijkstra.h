#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <list>
#include <fstream>
#define  MAX 10000
#define INF 0x3f3f3f3f
typedef std::pair<int, int> Ipair;
class DIJKSTRA
{
private:
	std::list<Ipair> m_graph[MAX];
public:
	int addEdge(int, int, int);
	int deleteEdge(int, int);
	int agorithmDijkstra(int, int);
	void menu();
};
struct GREATER
{
	bool operator()(Ipair, Ipair);
};
struct DIST
{
	int m_value;
	int m_parent;
};
#endif