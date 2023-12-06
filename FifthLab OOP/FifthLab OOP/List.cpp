#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>
#include<stdio.h>

#include "List.h"

List::List(const int size, const int value)
	:m_countNode(size)
{
	MakeEmptyList();
	for (int i = 0; i < m_countNode; ++i)
		PushBack(value);
}

List::List(const Array<int>& arr)
{
	MakeEmptyList();
	for (int i = 0; i < arr.Size(); ++i)
	{
		PushBack(arr[i]);
	}
	m_countNode = arr.Size();
}

List::~List()
{
	Clear();
	delete m_tail;
	delete m_head;
}

void List::PushBack(int value)
{
	Node* q = new Node;
	q->value = value;
	q->m_next = m_tail;
	q->m_prev = m_tail->m_prev;
	m_tail->m_prev->m_next = q;
	m_tail->m_prev = q;
}

void List::PopBack()
{
	if (!Empty())
	{
		Node* tmp_ptr = m_tail->m_prev;
		m_tail->m_prev = tmp_ptr->m_prev;
		tmp_ptr->m_prev->m_next = m_tail;
		delete tmp_ptr;
	}
}

void List::MakeEmptyList()
{
	m_head = new Node;
	m_tail = new Node;
	m_head->m_next = m_tail;
	m_head->m_prev = nullptr;
	m_tail->m_next = nullptr;
	m_tail->m_prev = m_head;
}

void List::Print()const
{
	for (auto* it = m_head->m_next; it != m_tail; it = it->m_next)
		std::cout << it->value << " ";
	std::cout << "\n";
}

bool List::Empty()const
{
	if (m_head->m_next == m_tail)
		return true;
	else
		return false;
}

void List::Clear()
{
	while (!Empty())
	{
		PopBack();
	}
}

int List::Size()const
{
	return m_countNode;
}

void List::Swap(List& other)
{
	std::swap(m_head, other.m_head);
	std::swap(m_tail, other.m_tail);
	std::swap(m_countNode, other.m_countNode);
}

List::Node* List::FindValue(const int value)const
{

}

int& List::operator[](const int index)
{
	assert(index < m_countNode);
	Node* tmp_it = m_head->m_next;
	for (int i = 0; i < index; ++i)
	{
		tmp_it = tmp_it->m_next;
	}
	return tmp_it->value;
}

const int& List::operator[](const int index)const
{
	assert(index < m_countNode);
	Node* tmp_it = m_head->m_next;
	for (int i = 0; i < index; ++i)
	{
		tmp_it = tmp_it->m_next;
	}
	return tmp_it->value;
}

std::ostream& operator<<(std::ostream& stream, const List& list)
{
	for (int i = 0; i < list.Size(); ++i)
	{
		stream << list[i]<< " ";
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, List& list)
{
	for (int i = 0; i < list.Size(); ++i)
	{
		stream >> list[i];
	}
	return stream;
}


