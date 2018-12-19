#include "dijkstra.h"
std::vector<DIST> dist;
bool GREATER::operator()(Ipair object_one, Ipair object_two)
{
	return object_one.first > object_two.first;
}
//Them canh
int DIJKSTRA::addEdge(int a, int b, int c)
{
	std::list<Ipair>::iterator i;
	for (i = m_graph[a].begin(); i != m_graph[a].end(); i++)
	{
		//Kiem tra xem canh da ton tai chua
		if ((*i).first == b)
		{
			return 0;
		}
	}
	m_graph[a].push_back(std::make_pair(b, c));
	m_graph[b].push_back(std::make_pair(a, c));
	return 1;
}
int DIJKSTRA::deleteEdge(int a, int b)
{
	bool check = false;
	std::list<Ipair>::iterator i;
	for (i = m_graph[a].begin(); i != m_graph[a].end(); i++)
	{
		//Kiem tra xem co canh khong
		if ((*i).first == b)
		{
			m_graph[a].erase(i);
			check = true;
			break;
		}
	}
	//Neu khong co thi tra ve 0
	if (check == false)
	{
		return 0;
	}
	for (i = m_graph[b].begin(); i != m_graph[b].end(); i++)
	{
		if ((*i).first == a)
		{
			m_graph[b].erase(i);
			break;
		}
	}
	return 1;
}
//Thuat toan tim duong di ngan nhat
int DIJKSTRA::agorithmDijkstra(int apex_begin, int apex_finish)
{
	DIST temp_dist;
	for (size_t i = 0; i < MAX; i++)
	{
		temp_dist.m_value = INF;
		temp_dist.m_parent = -1;
		dist.push_back(temp_dist);
	}
	std::priority_queue<Ipair, std::vector<Ipair>, GREATER> min_heap;
	min_heap.push(std::make_pair(apex_begin, 0));
	dist[apex_begin].m_value = 0;
	while (!min_heap.empty())
	{
		int first_min_heap = min_heap.top().first;
		min_heap.pop();
		std::list<Ipair>::iterator i;
		for (i = m_graph[first_min_heap].begin(); i != m_graph[first_min_heap].end(); i++)
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
	if (dist[apex_finish].m_value == INF)
	{
		return -1;
	}
	else return 1;
}
void DIJKSTRA::menu()
{
	//Mo file input,output
	std::fstream input, output;
	int selection;
	do{
		system("cls");
		std::cout << "\n================================================================================\n\n";
		std::cout << std::setw(45) << " MENU \n\n";
		std::cout << "\t\t\t\t1 . THEM CANH  \n";
		std::cout << "\t\t\t\t2 . XOA CANH \n";
		std::cout << "\t\t\t\t3 . TIM DUONG DI NGAN NHAT \n";
		std::cout << "\t\t\t\t0 . Thoat\n";
		std::cout << "\n================================================================================\n\n";
		std::cout << "\t\t\t Nhap lua chon : ";
		std::cin >> selection;
		std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
		if (selection<0 || selection>3)
		{
			std::cout << "\t\t!!! LUA CHON KHONG HOP LE!!!\n\t      !!!VUI LONG NHAP LAI LUA CHON!!!";
			std::cout << "\n\n--------------------------------------------------------------------------------\n\n";
			system("pause");
		}

		else if (selection == 0)
		{
			std::cout << "\t\t\t    Cam On Ban\n";
		}
		else if (selection == 1)
		{
			system("cls");
			input.open("input.txt", std::ios::app);
			output.open("output.txt", std::ios::app);
			if (!input)
			{
				std::cout << "\n\t\t!!! CANNOT OPEN FILE INPUT!!!\n\n";
				return;
			}
			if (!output)
			{
				std::cout << "\n\t\t!!! CANNOT OPEN FILE OUTPUT !!!\n\n";
				return;
			}
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 1 . THEM CANH \n\n";
			std::cout << "================================================================================\n\n";
			int apex_begin, apex_finish, weigth;
			std::cout << "\t\t Nhap dinh 1 : ";
			std::cin >> apex_begin;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			std::cout << "\t\t Nhap dinh 2 : ";
			std::cin >> apex_finish;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			std::cout << "\t\t Nhap trong so : ";
			std::cin >> weigth;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			//xuat trong file input
			input << "CREATE " << apex_begin << " " << apex_finish << " " << weigth << "\n";
			int check = addEdge(apex_begin, apex_finish, weigth);
			if (check == 0)
			{
				std::cout << "\t\t  CANH DA TON TAI \n\n";
				output << "0\n";
			}
			else
			{
				std::cout << "\t\t   DA THEM CANH\n";
				output << "1\n";
			}
			input.close();
			output.close();
			system("pause");
		}
		else if (selection == 2)
		{
			system("cls");
			input.open("input.txt", std::ios::app);
			output.open("output.txt", std::ios::app);
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 2 . XOA CANH \n\n";
			std::cout << "================================================================================\n\n";
			int apex_begin, apex_finish;
			std::cout << "\t\t Nhap dinh 1 : ";
			std::cin >> apex_begin;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			std::cout << "\t\t Nhap dinh 2 : ";
			std::cin >> apex_finish;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			//xuat trong file input
			input << "DELETE " << apex_begin << " " << apex_finish << "\n";
			int check = deleteEdge(apex_begin, apex_finish);
			if (check == 0)
			{
				std::cout << "\t\t  CANH KHONG TON TAI \n\n";
				output << "0\n";
			}
			else
			{
				std::cout << "\t\t    DA XOA CANH\n";
				output << "1\n";
			}
			input.close();
			output.close();
			system("pause");
		}
		else
		{
			system("cls");
			input.open("input.txt", std::ios::app);
			output.open("output.txt", std::ios::app);
			std::cout << "================================================================================\n\n";
			std::cout << std::setw(45) << " 3 . TIM DUONG DI NGAN NHAT \n\n";
			std::cout << "================================================================================\n\n";
			int apex_begin, apex_finish;
			std::cout << "\t\t Nhap dinh bat dau : ";
			std::cin >> apex_begin;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			std::cout << "\t\t Nhap dinh ket thuc : ";
			std::cin >> apex_finish;
			std::cout << "\n--------------------------------------------------------------------------------\n\n";
			input << "SP " << apex_begin << " " << apex_finish << "\n";
			int check = agorithmDijkstra(apex_begin, apex_finish);
			if (check == -1)
			{
				std::cout << "\t\t KHONG CO DUONG DI TU " << apex_begin << " DEN " << apex_finish << "\n\n";
				output << "-1\n";
			}
			else
			{
				std::vector<int> path;
				int temp = apex_finish;
				while (temp != -1)
				{
					path.push_back(temp);
					temp = dist[temp].m_parent;
				}
				std::cout << "\t\t" << apex_begin << " -> " << apex_finish << " : " << dist[apex_finish].m_value << "\n";
				std::cout << "\t\t PATH : \n";
				output << dist[apex_finish].m_value << "\n";
				//xuat duong di ngan nhat
				for (int i = path.size() - 1; i >0; i--)
				{
					std::cout << "\t\t" << path[i] << " - " << path[i - 1] << "\n";
					output << path[i] << " - " << path[i - 1] << "\n";
				}
			}
			input.close();
			output.close();
			system("pause");
		}
	} while (selection != 0);
}