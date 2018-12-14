#include "dijkstra.h"
int main()
{
	// create the graph given in above fugure 
	int V = 9;
	GRAPH g(V);

	//  making above shown graph 
	g.add_node(0, 1, 4);
	g.add_node(0, 7, 8);
	g.add_node(1, 2, 8);
	g.add_node(1, 7, 11);
	g.add_node(2, 3, 7);
	g.add_node(2, 8, 2);
	g.add_node(2, 5, 4);
	g.add_node(3, 4, 9);
	g.add_node(3, 5, 14);
	g.add_node(4, 5, 10);
	g.add_node(5, 6, 2);
	g.add_node(6, 7, 1);
	g.add_node(6, 8, 6);
	g.add_node(7, 8, 7);

	g.dijkstra(0,3);
	system("pause");
	return 0;
}