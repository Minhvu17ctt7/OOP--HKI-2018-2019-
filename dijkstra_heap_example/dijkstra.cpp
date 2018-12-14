#include "dijkstra.h"
GRAPH::GRAPH(size_t n)
{
	m_size = n;
	adj = new std::list<Ipair>[n];
}
void GRAPH::add_node(int a, int b, int c)
{
	adj[a].push_back(std::make_pair(b, c));
	adj[b].push_back(std::make_pair(a, c));
}
bool GREATER::operator()(Ipair a, Ipair b)
{
	return a.first > b.first;
}
void GRAPH::dijkstra(int begin,int fish)
{
	std::vector<DIST> dist;
	for (size_t i = 0; i < m_size; i++)
	{
		DIST a;
		a.m_pre = -1;
		a.m_value = INF;
		dist.push_back(a);
	} 
	std::priority_queue<Ipair, std::vector<Ipair>, GREATER> pq;
	pq.push(std::make_pair(begin, 0));
	dist[begin].m_value = 0;
	std::list<Ipair>::iterator i;
	while (!pq.empty())
	{
		int a = pq.top().first;
		pq.pop();
		for (i = adj[a].begin(); i != adj[a].end(); i++)
		{
			int b = (*i).first;
			int weight = (*i).second;
			if (dist[b].m_value > weight + dist[a].m_value)
			{
				dist[b].m_value = weight + dist[a].m_value;
				dist[b].m_pre = a;
				pq.push(std::make_pair(b, dist[b].m_value));
			}
		}
	}
	std::cout << begin << " - " << fish << " : " << dist[fish].m_value<<"\n";
	int temp = dist[fish].m_pre;
	std::cout << temp << "\n";
	std::cout << fish;
	while (temp != -1)
	{
		std::cout << "<-" << temp;
		temp = dist[temp].m_pre;
	}
}