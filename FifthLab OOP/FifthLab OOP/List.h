#ifndef LIST_TEMPLATE_CLASS
#define LIST_TEMPLATE_CLASS
#include<stdint.h>
#include<iostream>
#include<assert.h>
#include"../../SecondLabOOP/SecondLabOOP/Array.h"

template <typename Type>
class List
{
public:
	template<typename IT, typename LT>
	class TemplateIterator;
	using Iterator = TemplateIterator<Type, List>;
	using ConstIterator = TemplateIterator<const Type, const List>;
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
	void PushOnIterator(Iterator& it, const Type& value);
	void PopBack();
	void PopFront();
	void PopPosition(const int pos);
	void PopKey(const Type& key);
	void PopOnIterator(Iterator& it);
	void DeleteRange(Iterator& from, Iterator& to);
	void Print()const;
	bool Empty()const;
	void Clear();
	int Size()const;
	void Swap(List &other);
	Iterator FindValue(const Type& value);
	ConstIterator FindValue(const Type& value)const;
	Type Min()const;
	Type Max()const;
	void Sort();
	Type& operator[](const int index);
	const Type& operator[](const int index)const;
	bool operator==(const List& other)const;
	bool operator!=(const List& other)const;
	List& operator=(const List& other);
	List operator+(const List& other)const;
	List& operator+=(const List& other);

	Iterator Begin();
	ConstIterator Begin()const;
	Iterator End();
	ConstIterator End()const;

	Iterator begin() { return Begin(); };
	ConstIterator begin()const { return Begin(); };
	Iterator end() { return End(); };
	ConstIterator end()const { return End(); };

private:
	void MakeEmptyList();
	void InsertNode(Iterator& it,const Type& value);
	void DeleteNode(Iterator& it);
	int m_countNode = 0;
	Node* m_head = nullptr;
	Node* m_tail = nullptr;
};

template<typename Type>
std::ostream& operator<<(std::ostream& stream, const List<Type>& list);
template<typename Type>
std::istream& operator>>(std::istream& stream, List<Type>& list);

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
template<typename IT, typename LT>
class List<Type>::TemplateIterator
{
	friend List;
public:
	TemplateIterator(LT* list = nullptr, Node* node = nullptr);
	IT& operator*();
	const IT& operator*()const;
	TemplateIterator& operator++();
	TemplateIterator& operator--();
	TemplateIterator operator++(int);
	TemplateIterator operator--(int);
	bool operator==(const TemplateIterator& other)const;
	bool operator!=(const TemplateIterator& other)const;
private:
	LT* m_list = nullptr;
	Node* m_node = nullptr;
};


#include"List.cpp"
#endif