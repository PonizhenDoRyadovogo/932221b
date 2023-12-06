#pragma once
#include<stdint.h>
#include<iostream>
#include"../../SecondLabOOP/SecondLabOOP/Array.h"

class List
{
public:
	class Node;
	List(const int size = 10, const int value = 0);
	List(const Array<int>& arr);
	~List();
	void PushBack(int value);
	void PopBack();
	void Print()const;
	bool Empty()const;
	void Clear();
	int Size()const;
	void Swap(List &other);
	Node* FindValue(const int value)const;

	int& operator[](const int index);
	const int& operator[](const int index)const;
private:
	void MakeEmptyList();
	int m_countNode = 0;
	Node* m_head = nullptr;
	Node* m_tail = nullptr;

};

class List::Node
{
	friend List;
private:
	int value;
	Node* m_next = nullptr;
	Node* m_prev = nullptr;
};

std::ostream& operator<<(std::ostream& stream, const List& list);
std::istream& operator>>(std::istream& stream, List& list);
