#include "prim.h"
void PRIM::agottithmPrim()
{
	std::fstream file_in;
	file_in.open("input.txt");
	if (!file_in)
	{
		std::cout << "\n\t\tCANT OPEN FILE\n\n";
		return ;
	}
	int apex, edge, apex_begin, apex_finish, temp1, temp2, temp3;
	file_in >> apex;
	file_in >> edge;
	file_in >> apex_begin;
	file_in >> apex_finish;
	m_size = apex;
	m_weight = new std::list<Ipair>[m_size];
	for (size_t i = 0; i < apex; i++)
	{
		file_in >> temp1;
		file_in >> temp2; 
		file_in >> temp3;
		add_node(temp1, temp2, temp3);
	}
	file_in.close();

	std::priority_queue<Ipair, std::vector<Ipair>, GREATER> min_heap;
	DIST2 temp;
	temp.m_check = false;
	temp.m_parent = -1;
	temp.m_value = INF;
	std::vector<DIST2> dist(m_size, temp);

	dist[apex_begin].m_value = 0;
	min_heap.push(std::make_pair(apex_begin, 0));
	while (!min_heap.empty())
	{
		int first_min_heap = min_heap.top().first;
		min_heap.pop();
		dist[first_min_heap].m_check = true;
		std::list<Ipair>::iterator i;
		for (i = m_weight[first_min_heap].begin(); i != m_weight[first_min_heap].end(); i++)
		{
			int destinations = (*i).first;
			std::cout << " destinations = " << destinations << "\n";
			int weight = (*i).second;
			std::cout << " " << dist[destinations].m_check << " " << dist[destinations].m_value;
			if (dist[destinations].m_check == false && dist[destinations].m_value > weight)
			{
				dist[destinations].m_value = weight;
				dist[destinations].m_parent = first_min_heap;
				min_heap.push(std::make_pair(destinations, dist[destinations].m_value));
			}
		}
	}
	std::cout << "\n";
	for (size_t i = 1; i < m_size; i++)
	{
		std::cout << dist[i].m_parent << "-" << i << "\n";
	}
}