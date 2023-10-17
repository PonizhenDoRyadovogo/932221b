#pragma once
#include<iostream>
#include<assert.h>
template <typename ItemType>
class Array
{
public:
	class Iterator;
public:
	Array(const int size = 10, const ItemType &value = ItemType());
	Array(const Array& other);
	Array(Array&& other);
	~Array();
	void Print()const;
	const int& operator [](const int index) const;
	int& operator [](const int index);
	int size() const;
	Array& operator = (Array&& other);
	Array &operator = (const Array& other);
	Array operator +(const Array& other)const;
	void swap(Array& other);
	void resize(int size);
	Array& operator +=(const Array& other);
	int Find(const ItemType value);
	Array operator +(const ItemType value);
	Array& operator+=(const ItemType value);
	bool operator ==(const Array& other)const;
	bool operator !=(const Array& other)const;
	void RandomArray(const ItemType left_lim, const ItemType right_lim);
	bool InsertIndex(int index, const ItemType value);
	bool DeleteOffIndex(int index);
	bool DeleteOffValue(const ItemType value);
	bool DeleteOffValueAll(const ItemType value);
	ItemType SearchMax();
	ItemType SearchMin();


private:
	int* m_array = nullptr;
	int m_size = 0;
};
template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType> & arr);
template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType> & arr);

#include "Array.cpp"
