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
private:
	List<Lider> m_list;

};

struct Graph::Lider
{
	struct Trailer;
	int key;
	int count_in_arc;
	List<Lider* > trailers;
};
