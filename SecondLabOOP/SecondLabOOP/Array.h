#pragma once
#include<iostream>
#include<assert.h>
template <typename ItemType>
class Array
{
public:
	template<typename IT, typename AT>
	class Iterator;
	typedef Iterator<ItemType, Array> TmpIterator;
	typedef Iterator<const ItemType, const Array> TmpConstIterator;
public:
	Array(const int size = 10, const ItemType &value = ItemType());
	Array(const Array& other);
	Array(Array&& other);
	~Array();
	void Print()const;
	const ItemType& operator [](const int index) const;
	ItemType& operator [](const int index);
	int Size() const;
	Array& operator = (Array&& other);
	Array &operator = (const Array& other);
	Array operator +(const Array& other)const;
	void Swap(Array& other);
	void Resize(int size);
	Array& operator +=(const Array& other);
	int Find(const ItemType &value)const;
	Array operator +(const ItemType &value)const;
	Array& operator+=(const ItemType &value);
	bool operator ==(const Array& other)const;
	bool operator !=(const Array& other)const;
	bool InsertIndex(int index, const ItemType &value);
	bool DeleteOffIndex(int index);
	bool DeleteOffValue(const ItemType &value);
	bool DeleteOffValueAll(const ItemType &value);
	ItemType SearchMax()const;
	ItemType SearchMin()const;

	TmpIterator Begin();
	TmpIterator End();
	TmpConstIterator Begin()const;
	TmpConstIterator End()const;
	bool InsertIter(TmpIterator iter, const ItemType& value);
	bool DeleteOfIteratorRange(const TmpIterator &left, TmpIterator right);
	bool DeleteOfIterator(TmpIterator iter);
private:
	ItemType* m_array = nullptr;
	int m_size = 0;
};

//iostream
template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType> & arr);
template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType> & arr);

template<typename ItemType>
template<typename IT, typename AT>
class Array<ItemType>:: Iterator
{
public:
	Iterator(AT* array = nullptr, int pos = 0);
	IT& operator *();
	Iterator& operator++();
	Iterator& operator--();

	Iterator operator++(int);
	Iterator operator--(int);
	int Position()const;
	bool operator ==(const Iterator& other)const;
	bool operator !=(const Iterator& other)const;
	bool operator <=(const Iterator& other)const;
	bool operator <(const Iterator& other)const;
	IT& operator[](const int value);
private:
	AT *m_array;
	int m_pos = 0;
};

#include "Array.cpp"
