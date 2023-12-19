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

std::vector<int> TopologicalSortMatrix(BoolMatrix& matr)
{
	std::vector<int> res;
	int size = matr.GetColumnsCount();
	BoolVector keeper(size), noPredecessor, new_edges;
	do
	{
		noPredecessor = ~matr.DisjunctionRows();
		if (noPredecessor.Weight() == 0)//checking for a cycle
		{
			std::cout << "We have cycle!!!. Return empty vector\n";
			res.clear();
			return res;
		}
		new_edges = noPredecessor & ~keeper;
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

	/*BoolMatrix matr(4, 4, 0);
	std::cin >> matr;
	std::cout << matr << std::endl;
	std::vector<int> res;
	res = TopologicalSortMatrix(matr);
	std::cout << "decision: ";
	PrintArray(res);
	return 0;*/
}