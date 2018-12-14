#include "prim.h"
GRAPH::GRAPH(int n)
{
	m_size = n;
	m_adj = new std::list<Ipair>[n];
}
void GRAPH::add_node(int a, int b, int c)
{
	m_adj[a].push_back(std::make_pair(b, c));
	m_adj[b].push_back(std::make_pair(a, c));
}
bool GREATER::operator() (Ipair a, Ipair  b)
	{
		return a.first>b.first;
	}
void GRAPH::prim(int begin)
{
	std::priority_queue<Ipair, std::vector<Ipair>, GREATER> p;
	DIST temp1;
	temp1.check = false;
	temp1.m_parent = -1;
	temp1.m_value = INF;
	std::vector<DIST> dist(m_size, temp1);

	p.push(std::make_pair(begin, 0));
	dist[begin].m_value = 0;
	while (!p.empty())
	{
		int a = p.top().first;
		p.pop();
		dist[a].check = true;
		std::list<Ipair>::iterator i;
		for (i = m_adj[a].begin(); i != m_adj[a].end(); i++)
		{
			int b = (*i).first;
			int weigth = (*i).second;
			if (dist[b].check == false && dist[b].m_value > weigth)
			{
				dist[b].m_value = weigth;
				dist[b].m_parent = a;
				p.push(std::make_pair(b, dist[b].m_value));
			}
		}
	}
	for (size_t i = 1; i < m_size; i++)
	{
		std::cout << dist[i].m_parent << " - " << i<<"\n";
	}
}