#include <iostream>
#include <assert.h>

#include "TopologicalSort.h"

Graph::Graph()
{
	m_list.PushBack(Lider(-1));
}

void Graph::AddEdge(const int left, const int right)
{
	assert(left >= 0 || right >= 0 || left != right);
	auto it_left = m_list.Begin();
	auto it_right = m_list.Begin();

	while (it_left != m_list.End())
	{
		if ((*it_left).key == left)
			break;
		++it_left;
	}
	while (it_right != m_list.End())
	{
		if ((*it_right).key == right)
			break;
		++it_right;
	}
	/*for (; it_left != m_list.End() || (*it_left).key != left; ++it_left);
	for (; it_right != m_list.End() || (*it_right).key != right; ++it_right);*/
	bool set_edge = true;
	if (it_left != m_list.End() || it_right != m_list.End())
	{
		auto it_trl = (*it_left).trailers.Begin();
		for (;it_trl != (*it_left).trailers.End() && (*(*it_trl)).key != (*it_right).key; ++it_trl);
		if (it_trl == (*it_left).trailers.End())
			set_edge = true;
		else
			set_edge = false;
	}
	else 
	{
		if (it_left == m_list.End())
		{
			Graph::Lider tmp = Lider(left);
			m_list.PushFront(tmp);
			it_right = m_list.FindValue(tmp);
		}

		if (it_right == m_list.End())
		{
			Graph::Lider tmp = Lider(right);
			m_list.PushFront(tmp);
			it_right = m_list.FindValue(tmp);
		}
	}

	if (set_edge)
	{
		(*it_left).trailers.PushBack(it_right);
		++(*it_right).input_arc_count;
	}
}

void Graph::PrintGraph() const
{
	for (auto it = m_list.Begin(); it != m_list.End(); ++it)
	{
		for (auto jt = (*it).trailers.Begin(); jt != (*it).trailers.End(); ++jt)
			std::cout << (*it).key << " " << (*(*jt)).key<<"\n";
	}
	std::cout << std::endl;
}

void Graph::DeleteEdge(const int left, const int right)
{
	assert(left >= 0 || right >= 0 || left != right);
	auto it_left = m_list.Begin();
	auto it_right = m_list.Begin();

	while (it_left != m_list.End())
	{
		if ((*it_left).key == left)
			break;
		++it_left;
	}
	while (it_right != m_list.End())
	{
		if ((*it_right).key == right)
			break;
		++it_right;
	}
	if (it_left != m_list.End() && (*it_left).trailers.Begin() != nullptr && it_right != m_list.End())
	{
		//if((*it_left).trailers == it_right)
	}

}

bool Graph::Lider::operator==(const Graph::Lider& lid)const
{
	if (key != lid.key || input_arc_count != lid.input_arc_count || trailers != lid.trailers)
		return false;
	else
		return true;
}