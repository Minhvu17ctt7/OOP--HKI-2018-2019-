#include "DIJKSTRA.h"
void dijkstra::agorithmDijkstra()
{
	std::fstream fileIn;
	fileIn.open("input.txt");
	if (!fileIn)
	{
		std::cout << "\n\n\t\t!!! CANT OPEN FILE !!!\n";
		return ;
	}
	int apex, edge, apex_begin, apex_finish, temp1, temp2, temp3;
	fileIn >> apex;
	fileIn >> edge;
	fileIn >> apex_begin;
	fileIn >> apex_finish;
	m_weight = new std::list<Ipair>[apex];
	m_size = apex;
	for (int i = 0; i < edge; i++)
	{
		fileIn >> temp1;
		fileIn >> temp2;
		fileIn >> temp3;
		add_node(temp1, temp2, temp2);
	}
	fileIn.close();

	DIST temp_dist;
	temp_dist.m_parent = -1;
	temp_dist.m_value = INF;
	std::vector<DIST> dist(m_size, temp_dist);
	std::priority_queue<Ipair, std::vector<Ipair>, GREATER> min_heap;
	min_heap.push(std::make_pair(apex_begin, 0));
	dist[apex_begin].m_value = 0;
	while (!min_heap.empty())
	{
		int first_min_heap = min_heap.top().first;
		min_heap.pop();
		std::list<Ipair>::iterator i;
		for (i = m_weight[first_min_heap].begin(); i != m_weight[first_min_heap].end(); i++)
		{
			int destinations = (*i).first;
			int weight = (*i).second;
			if (dist[destinations].m_value > dist[first_min_heap].m_value + weight)
			{
				dist[destinations].m_value = dist[first_min_heap].m_value + weight;
				dist[destinations].m_parent = first_min_heap;
				min_heap.push(std::make_pair(destinations, dist[destinations].m_value));
			}
		}
	}
	std::cout << dist[apex_finish].m_value << " : \n";
	std::cout << apex_finish;
	int parent = dist[apex_finish].m_parent;
	while (parent != -1)
	{
		std::cout << "<-" << parent;
		parent = dist[parent].m_parent;
	}
}