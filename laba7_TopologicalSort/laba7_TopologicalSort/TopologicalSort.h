#pragma once

#include"../../FourthLab OOP/FourthLab OOP/BoolMatrix.h"
#include"../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"
#include"../../FifthLab OOP/FifthLab OOP/List.h"


class Graph
{
public:
	struct Lider;
public:
	Graph();
	void PrintGraph() const;
	void AddEdge(const int left, const int right);//need private
	void DeleteEdge(const int left, const int right);//need private
private:
	List<Lider> m_list;
	
};

struct Graph::Lider
{
	Lider() = default;
	Lider(const int value)
	{
		key = value;
	}
	bool operator==(const Graph::Lider& lid)const;
	int key = 0;
	int input_arc_count = 0;
	List<List<Lider>::Iterator> trailers;
};
