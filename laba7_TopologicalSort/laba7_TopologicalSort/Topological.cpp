#include<iostream>
#include<vector>
#include "TopologicalSort.h"

void PrintArray(std::vector<int> a)
{
	std::cout << "[";
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << "]";
}

void PushVertex(std::vector<int>& res, BoolVector& bool_vec)
{
	const int size = bool_vec.Length();
	for (int i = 0; i < size; ++i)
	{
		if (bool_vec[i] == true)
			res.push_back(i + 1);
	}
}

/**
 * @function TopologicalSortMatrix
 * @brief Performs topoligical sort on the matrix 'matr'.
 * @return vector of node numbers in the proper order.
 *	If there is an cycle, returned vector will be empty.
*/
std::vector<int> TopologicalSortMatrix(BoolMatrix& matr)
{
	std::vector<int> res;
	int size = matr.GetColumnsCount();
	BoolVector keeper(size), noPredecessor, new_edges, check_cycle;
	do
	{
		noPredecessor = ~matr.DisjunctionRows();
		if (noPredecessor.Weight() == 0)//checking for a cycle
		{
			res.clear();
			return res;
		}
		new_edges = noPredecessor & ~keeper;
		check_cycle = new_edges;
		if (new_edges.Weight() == check_cycle.Weight())
		{
			res.clear();
			return res;
		}
		keeper |= new_edges;
		PushVertex(res, new_edges);
		for (int i = 0;i < res.size(); ++i)
		{
			matr.SetRange0(res[i] - 1, 0, size);
		}
	} while (keeper.Weight() != size);
	return res;
}

int main()
{
	Graph gr;
	gr.AddEdge(2, 1);
	gr.AddEdge(4, 5);
	gr.AddEdge(5, 1);
	gr.AddEdge(5, 3);
	gr.AddEdge(6, 2);
	gr.AddEdge(6, 3);
	gr.AddEdge(6, 5);
	gr.AddEdge(7, 1);
	gr.PrintGraph();
	return 0;
}

	/*std::vector<std::vector<bool>> vec = { {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
	,{1, 0, 0, 0, 0, 0, 0, 0, 1, 1 }
	,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	,{0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
	,{0, 0, 1, 0, 0, 0, 0, 0, 0, 1 }
	,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	,{0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }
	,{1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	,{1, 0, 0, 1, 0, 0, 0, 0, 1, 0}};
		BoolMatrix matr(vec);
		std::cout << matr << std::endl;
		std::vector<int> res;
		res = TopologicalSortMatrix(matr);
		if (res.empty())
			std::cout << "We have cycle!!!. Return empty vector\n";
		else
		{
			std::cout << "decision: ";
			PrintArray(res);
		}*/
/*
* Example 1:
0, 1, 0, 0, 0
0, 0, 0, 0, 0
0, 1, 0, 0, 1
0, 1, 0, 0, 0
1, 0, 0, 0, 0
answer: [3 4 5 1 2 ]
* 
* Example 2:
0, 1, 0, 1, 0
0, 0, 0, 1, 0
1, 0, 0, 0, 1
0, 0, 1, 0, 1
0, 0, 0, 0, 0

answer: We have cycle!!!. Return empty vector

Example 3:
0, 0, 0, 0, 1, 0, 0, 0, 0, 0
1, 0, 0, 0, 0, 0, 0, 0, 1, 1
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 1, 0
0, 0, 1, 0, 0, 0, 0, 0, 0, 1
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 1, 0, 0, 1, 0, 0, 0, 0
1, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 1, 0, 0, 0, 0, 1, 0

answer:[2 7 8 1 6 5 3 10 4 9 ]

Example 4:
0, 0, 0, 0, 1, 0, 0, 0, 0, 0
1, 0, 0, 0, 0, 0, 0, 0, 1, 1
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 1, 0
0, 0, 1, 0, 0, 0, 0, 0, 0, 1
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 1, 0, 0, 1, 0, 0, 0, 0
1, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0
1, 0, 0, 1, 0, 0, 0, 0, 1, 0
*/