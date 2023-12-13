#ifndef LIST_TEMPLATE_CLASS_METHODS_DEFINED
#define LIST_TEMPLATE_CLASS_METHODS_DEFINED

#include<iostream>
#include<assert.h>
#include"List.h"

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
	for (Node* tmp_ptr = other.m_head->m_next; tmp_ptr != other.m_tail; tmp_ptr = tmp_ptr->m_next)
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
	auto it = End();
	InsertNode(it, value);
}

template<typename Type>
void List<Type>::PushFront(const Type& value)
{
	auto it = Begin();
	InsertNode(it, value);
}

template<typename Type>
void List<Type>::PushPosition(const int pos, const Type& value)
{
	assert(pos < m_countNode);
	auto it = Begin();
	for (int i = 1; i < pos; ++i)
	{
		++it;
	}
	InsertNode(it, value);
}

template<typename Type>
void List<Type>::PushAfterKey(const Type& key, const Type& value)
{
	auto it = FindValue(key);
	it++;
	if (it != End())
	{
		InsertNode(it, value);
	}
}

template<typename Type>
void List<Type>::PushOnIterator(Iterator& it, const Type& value)
{
	InsertNode(it, value);
}

template<typename Type>
void List<Type>::PopBack()
{
	if (!Empty())
	{
		auto it = End();
		--it;
		DeleteNode(it);
	}
}

template<typename Type>
void List<Type>::PopFront()
{
	if (!Empty())
	{
		auto it = Begin();
		DeleteNode(it);
	}
}

template<typename Type>
void List<Type>::PopPosition(const int pos)
{
	if (!Empty())
	{
		auto it = Begin();
		for (int i = 1; i < pos; ++i)
		{
			++it;
		}
		DeleteNode(it);
	}
}

template<typename Type>
void List<Type>::PopKey(const Type& key)
{
	auto it = FindValue(key);
	if (it != End())
	{
		DeleteNode(it);
	}
}

template<typename Type>
void List<Type>::PopOnIterator(Iterator& it)
{
	if (it != End())
	{
		DeleteNode(it);
	}
}

template<typename Type>
void List<Type>::DeleteRange(Iterator& from, Iterator& to)
{
	auto tmp_it = from;
	if (from != End())
	{
		while (from != to)
		{
			tmp_it = from;
			++from;
			PopOnIterator(tmp_it);
		}
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
void List<Type>::InsertNode(Iterator& it, const Type& value)
{
	Node* q = new Node;
	q->m_value = value;
	q->m_next = it.m_node;
	q->m_prev = it.m_node->m_prev;
	it.m_node->m_prev->m_next = q;
	it.m_node->m_prev = q;
	m_countNode++;
}

template<typename Type>
void List<Type>::DeleteNode(Iterator& it)
{
	it.m_node->m_next->m_prev = it.m_node->m_prev;
	it.m_node->m_prev->m_next = it.m_node->m_next;
	delete it.m_node;
	--m_countNode;
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

template<typename Type>typename
List<Type>::Iterator List<Type>::FindValue(const Type& value)
{
	auto it = Begin();
	while (it != End())
	{
		if (*it == value)
			return it;
		++it;
	}
	return it;
}

template<typename Type>typename
List<Type>::ConstIterator List<Type>::FindValue(const Type& value)const
{
	auto it = Begin();
	while (it != End())
	{
		if (*it == value)
			return it;
		++it;
	}
	return it;
}

template<typename Type>
Type List<Type>::Min()const
{
	assert(m_countNode > 0);
	Type min = m_head->m_next->m_value;
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
Type List<Type>::Max()const
{
	assert(m_countNode > 0);
	Type max = m_head->m_next->m_value;
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
void List<Type>::Sort()
{
	for (auto it = Begin(); it != End(); ++it)
		for (auto jt = Begin(); jt != End(); ++jt)
			if (*it < *jt)
				std::swap(it.m_node->m_value, jt.m_node->m_value);
}

template<typename Type>
Type& List<Type>::operator[](const int index)
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
const Type& List<Type>::operator[](const int index)const
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
	if (m_countNode == m_countNode)
		return false;
	else if (m_head == other.m_head)
		return true;
	else
	{
		for (auto it = Begin(), jt = other.Begin(); it != End() && jt != other.End(); ++it, ++jt)
		{
			if (*it != *jt)
				return false;
		}
		return true;
	}
}

template<typename Type>
bool List<Type>::operator!=(const List& other)const
{
	return !(*this == other);
}

template<typename Type>
List<Type>& List<Type>::operator=(const List& other)
{
	if (m_head == other.m_head)
		return *this;
	Clear();
	for (const Type& value : other)
	{
		PushBack(value);
	}
	return *this;
}

template<typename Type>
List<Type> List<Type>::operator+(const List& other)const
{
	List res(*this);
	auto it = other.Begin();
	while (it != other.End())
	{
		res.PushBack(*it);
		++it;
	}
	return res;
}

template<typename Type>
List<Type>& List<Type>::operator+=(const List& other)
{
	(*this + other).Swap(*this);
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
	stream << "TAIL\n";
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

template<typename Type>
template<typename IT, typename LT>
List<Type>::TemplateIterator<IT, LT>::TemplateIterator(LT* list, Node* node)
{
	m_node = node;
	m_list = list;
}

template<typename Type>typename
List<Type>::Iterator List<Type>::Begin()
{
	return Iterator(this, m_head->m_next);
}

template<typename Type>typename
List<Type>::ConstIterator List<Type>::Begin()const
{
	return ConstIterator(this, m_head->m_next);
}

template<typename Type>typename
List<Type>::Iterator List<Type>::End()
{
	return Iterator(this, m_tail);
}

template<typename Type>typename
List<Type>::ConstIterator List<Type>::End()const
{
	return ConstIterator(this, m_tail);
}

template<typename Type>
template<typename IT, typename LT>
IT& List<Type>::TemplateIterator<IT, LT>::operator*()
{
	assert(m_node != nullptr);
	return m_node->m_value;
}

template<typename Type>
template<typename IT, typename LT>
const IT& List<Type>::TemplateIterator<IT, LT>::operator*()const
{
	assert(m_node != nullptr);
	return m_node->m_value;
}

template<typename Type>
template<typename IT, typename LT>
List<Type>::TemplateIterator<IT, LT>& List<Type>::TemplateIterator <IT, LT>::operator++()
{
	m_node = m_node->m_next;
	return *this;
}

template<typename Type>
template<typename IT, typename LT>
List<Type>::TemplateIterator<IT, LT>& List<Type>::TemplateIterator <IT, LT>::operator--()
{
	m_node = m_node->m_prev;
	return *this;
}

template<typename Type>
template<typename IT, typename LT>
List<Type>::TemplateIterator<IT, LT> List<Type>::TemplateIterator <IT, LT>::operator++(int)
{
	TemplateIterator old(m_list, m_node);
	m_node = m_node->m_next;
	return old;
}

template<typename Type>
template<typename IT, typename LT>
List<Type>::TemplateIterator<IT, LT> List<Type>::TemplateIterator <IT, LT>::operator--(int)
{
	TemplateIterator old(m_list, m_node);
	m_node = m_node->m_prev;
	return old;
}

template<typename Type>
template<typename IT, typename LT>
bool List<Type>::TemplateIterator <IT, LT>::operator==(const TemplateIterator& other)const
{
	assert(m_list == other.m_list);
	return (m_list == other.m_list && m_node == other.m_node);
}

template<typename Type>
template<typename IT, typename LT>
bool List<Type>::TemplateIterator <IT, LT>::operator!=(const TemplateIterator& other)const
{
	return !(*this == other);
}


#endif