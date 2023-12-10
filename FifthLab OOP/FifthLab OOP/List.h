#pragma once
#include<stdint.h>
#include<iostream>
#include<assert.h>
#include"../../SecondLabOOP/SecondLabOOP/Array.h"

template <typename Type>
class List
{
public:
	class Node;
	List(const int size = 10, const Type& value = Type());
	List(const Array<Type>& arr);
	List(const List& other);
	~List();
	void PushBack(const Type& value);
	void PushFront(const Type& value);
	void PushPosition(const int pos, const Type& value);
	void PushAfterKey(const Type& key, const Type& value);
	void PopBack();
	void PopFront();
	void PopPosition(const int pos);
	void PopKey(const Type& key);
	void Print()const;
	bool Empty()const;
	void Clear();
	int Size()const;
	void Swap(List &other);
	Node* FindValue(const Type& value)const;
	int Min()const;
	int Max()const;

	int& operator[](const int index);
	const int& operator[](const int index)const;
	bool operator==(const List& other)const;
	bool operator!=(const List& other)const;
	List& operator=(const List& other);
private:
	void MakeEmptyList();
	int m_countNode = 0;
	Node* m_head = nullptr;
	Node* m_tail = nullptr;

};

template<typename Type>
class List<Type>::Node
{
	friend List;
private:
	Type m_value;
	Node* m_next = nullptr;
	Node* m_prev = nullptr;
};

template<typename Type>
std::ostream& operator<<(std::ostream& stream, const List<Type>& list);
template<typename Type>
std::istream& operator>>(std::istream& stream, List<Type>& list);

template<typename Type>
List<Type>::List(const int size, const Type& value)
{
	MakeEmptyList();
	for (int i = 0; i < size; ++i)
		PushBack(value);
}

template<typename Type>
List<Type>::List(const List& other)
{
	MakeEmptyList();
	for (Node* tmp_ptr = other.m_head->m_next; tmp_ptr != m_tail; tmp_ptr = tmp_ptr->m_next)
	{
		PushBack(tmp_ptr->m_value);
	}
	m_countNode = other.m_countNode;
}

template<typename Type>
List<Type>::List(const Array<Type>& arr)
{
	MakeEmptyList();
	for (int i = 0; i < arr.Size(); ++i)
	{
		PushBack(arr[i]);
	}
	m_countNode = arr.Size();
}

template<typename Type>
List<Type>::~List()
{
	Clear();
	delete m_tail;
	delete m_head;
}

template<typename Type>
void List<Type>::PushBack(const Type& value)
{
	Node* q = new Node;
	q->m_value = value;
	q->m_next = m_tail;
	q->m_prev = m_tail->m_prev;
	m_tail->m_prev->m_next = q;
	m_tail->m_prev = q;
	m_countNode++;
}

template<typename Type>
void List<Type>::PushFront(const Type& value)
{
	Node* q = new Node;
	q->m_value = value;
	q->m_prev = m_head;
	q->m_next = m_head->m_next;
	m_head->m_next->m_prev = q;
	m_head->m_next = q;
	m_countNode++;
}

template<typename Type>
void List<Type>::PushPosition(const int pos, const Type& value)
{
	assert(pos < m_countNode);
	Node* tmp_ptr = m_head->m_next;
	for (int i = 1; i <= pos; ++i)
	{
		tmp_ptr = tmp_ptr->m_next;
	}
	Node* q = new Node;
	q->m_value = value;
	q->m_next = tmp_ptr;
	q->m_prev = tmp_ptr->m_prev;
	tmp_ptr->m_prev->m_next = q;
	tmp_ptr->m_prev = q;
	m_countNode++;
}

template<typename Type>
void List<Type>::PushAfterKey(const Type& key, const Type& value)
{
	Node* tmp_ptr = FindValue(key);
	if (tmp_ptr != nullptr)
	{
		tmp_ptr = tmp_ptr->m_next;
		Node* q = new Node;
		q->m_value = value;
		q->m_next = tmp_ptr;
		q->m_prev = tmp_ptr->m_prev;
		tmp_ptr->m_prev->m_next = q;
		tmp_ptr->m_prev = q;
		m_countNode++;
	}
}

template<typename Type>
void List<Type>::PopBack()
{
	if (!Empty())
	{
		Node* tmp_ptr = m_tail->m_prev;
		m_tail->m_prev = tmp_ptr->m_prev;
		tmp_ptr->m_prev->m_next = m_tail;
		delete tmp_ptr;
		--m_countNode;
	}
}

template<typename Type>
void List<Type>::PopFront()
{
	if (!Empty())
	{
		Node* tmp_ptr = m_head->m_next;
		m_head->m_next = tmp_ptr->m_next;
		tmp_ptr->m_next->m_prev = m_head;
		delete tmp_ptr;
		--m_countNode;
	}
}

template<typename Type>
void List<Type>::PopPosition(const int pos)
{
	if (!Empty())
	{
		Node* tmp_ptr = m_head->m_next;
		for (int i = 1; i <= pos; ++i)
		{
			tmp_ptr = tmp_ptr->m_next;
		}
		tmp_ptr->m_prev->m_next = tmp_ptr->m_next;
		tmp_ptr->m_next->m_prev = tmp_ptr->m_prev;
		delete tmp_ptr;
		--m_countNode;
	}
}

template<typename Type>
void List<Type>::PopKey(const Type& key)
{
	Node* tmp_ptr = FindValue(key);
	if (tmp_ptr != nullptr)
	{
		tmp_ptr->m_prev->m_next = tmp_ptr->m_next;
		tmp_ptr->m_next->m_prev = tmp_ptr->m_prev;
		delete tmp_ptr;
		--m_countNode;
	}
}

template<typename Type>
void List<Type>::MakeEmptyList()
{
	m_head = new Node;
	m_tail = new Node;
	m_head->m_next = m_tail;
	m_head->m_prev = nullptr;
	m_tail->m_next = nullptr;
	m_tail->m_prev = m_head;
}

template<typename Type>
void List<Type>::Print()const
{
	for (auto* it = m_head->m_next; it != m_tail; it = it->m_next)
		std::cout << it->m_value << " ";
	std::cout << "\n";
}

template<typename Type>
bool List<Type>::Empty()const
{
	if (m_head->m_next == m_tail)
		return true;
	else
		return false;
}

template<typename Type>
void List<Type>::Clear()
{
	while (!Empty())
	{
		PopBack();
	}
}

template<typename Type>
int List<Type>::Size()const
{
	return m_countNode;
}

template<typename Type>
void List<Type>::Swap(List& other)
{
	std::swap(m_head, other.m_head);
	std::swap(m_tail, other.m_tail);
	std::swap(m_countNode, other.m_countNode);
}

template<typename Type> typename
List<Type>::Node* List<Type>::FindValue(const Type& value)const
{
	for (Node* tmp_it = m_head->m_next; tmp_it != m_tail; tmp_it = tmp_it->m_next)
	{
		if (tmp_it->m_value == value)
			return tmp_it;
	}
	return nullptr;
}

template<typename Type>
int List<Type>::Min()const
{
	assert(m_countNode > 0);
	int min = m_head->m_next->m_value;
	Node* tmp_it = m_head->m_next;
	while (tmp_it != m_tail)
	{
		if (tmp_it->m_value < min)
			min = tmp_it->m_value;
		tmp_it = tmp_it->m_next;
	}
	return min;
}

template<typename Type>
int List<Type>::Max()const
{
	assert(m_countNode > 0);
	int max = m_head->m_next->m_value;
	Node* tmp_it = m_head->m_next;
	while (tmp_it != m_tail)
	{
		if (tmp_it->m_value > max)
			max = tmp_it->m_value;
		tmp_it = tmp_it->m_next;
	}
	return max;
}

template<typename Type>
int& List<Type>::operator[](const int index)
{
	assert(index < m_countNode);
	Node* tmp_it = m_head->m_next;
	for (int i = 0; i < index; ++i)
	{
		tmp_it = tmp_it->m_next;
	}
	return tmp_it->m_value;
}

template<typename Type>
const int& List<Type>::operator[](const int index)const
{
	assert(index < m_countNode);
	Node* tmp_it = m_head->m_next;
	for (int i = 0; i < index; ++i)
	{
		tmp_it = tmp_it->m_next;
	}
	return tmp_it->m_value;
}

template<typename Type>
bool List<Type>::operator==(const List& other)const
{
	return (m_head == other.m_head && m_tail == other.m_tail);
}

template<typename Type>
bool List<Type>::operator!=(const List& other)const
{
	return !(*this == other);
}

template<typename Type>
List<Type>& List<Type>::operator=(const List& other)
{
	Clear();
	for (Node* tmp_ptr = other.m_head->m_next; tmp_ptr != other.m_tail; tmp_ptr = tmp_ptr->m_next)
	{
		PushBack(tmp_ptr->m_value);
	}
	m_countNode = other.m_countNode;
	return *this;
}

template<typename Type>
std::ostream& operator<<(std::ostream& stream, const List<Type>& list)
{
	stream << "HEAD<=>";
	for (int i = 0; i < list.Size(); ++i)
	{
		stream << list[i] << "<=>";
	}
	stream << "TAIL";
	return stream;
}

template<typename Type>
std::istream& operator>>(std::istream& stream, List<Type>& list)
{
	for (int i = 0; i < list.Size(); ++i)
	{
		stream >> list[i];
	}
	return stream;
}


