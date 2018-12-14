#include "gr.h"
void GRAPH::add_node(int a,int b,int c )
{
		m_weight[a].push_back(std::make_pair(b, c));
		m_weight[b].push_back(std::make_pair(a, c));
}
bool GREATER::operator()(Ipair a, Ipair b)
{
	return a.first > b.first;
}