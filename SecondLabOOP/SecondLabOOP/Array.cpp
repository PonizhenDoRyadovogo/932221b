#ifndef ARRAY_TEMPLATE_LABS
#define ARRAY_TEMPLATE_LABS
#include"Array.h"
template <typename ItemType>
Array<ItemType>::Array(const int size, const ItemType& value)
{
	if (size < 0)
	{
		std::cerr << "Array::Array: size is negative, invert... \n";
		m_size = -size;
	}
	else
	{
		m_size = size;
	}
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = value;
	}

}

template <typename ItemType>
Array<ItemType>::Array(const Array& other)
	:m_size(other.m_size)
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

template <typename ItemType>
Array<ItemType>::Array(const Array&& other)
{
	swap(other);
}

template <typename ItemType>
Array<ItemType>::~Array()
{
	delete[] m_array;
}

template <typename ItemType>
void Array<ItemType>::Print()const
{
	std::cout << *this;
}

template <typename ItemType>
const int& Array<ItemType>:: operator [](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
int& Array<ItemType>:: operator [](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
int Array<ItemType>::size() const
{
	return m_size;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator = (const Array& other)//a = a
{
	/*
	Array& Array::operator = (Array& other)
	{
	swap (other);
	return *this;//как вариант с импользованием swap
	}
	*/
	if (this == &other)
	{
		return *this;
	}
	if (m_size != other.m_size)
	{
		m_size = other.m_size;
		delete[] m_array;
		m_array = new int[m_size];
	}
	for (int i = 0; i < m_size;i++)
	{
		m_array[i] = other.m_array[i];
	}
	return *this;
}
//если внутри класса мы работаем с кучей, то обязательно нужны свои = и конструкторы копирования

template <typename ItemType>
Array<ItemType> Array<ItemType>:: operator +(const Array& other) const
{
	Array res(m_size + other.m_size);
	for (int i = 0; i < m_size; ++i)
	{
		res.m_array[i] = m_array[i];
	}
	for (int i = 0; i < other.m_size; ++i)
	{
		res.m_array[m_size + i] = other.m_array[i];
	}
	return res;
}

template <typename ItemType>
void Array<ItemType>::swap(Array& other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

template <typename ItemType>
void Array<ItemType>::resize(int size)
{
	if (size < 0)
	{
		std::cerr << "Array::Array: size is negative, invert... \n";
		m_size = -size;
	}
	Array res(size);
	int count = std::min(m_size, size);
	for (int i = 0; i < count; ++i)
	{
		res.m_array[i] = m_array[i];
	}
	res.swap(*this);
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>:: operator +=(const Array& other)
{
	Array tmp = *this + other;//работает конструктор копирования
	this->swap(tmp);
	return *this;
}

template <typename ItemType>
int Array<ItemType>::Find(const Array& other, const int d)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_array[i] == d)
		{
			return i;//if match are found, then return index element
		}
	}
	return -1;//if no matches are found, then return -1
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr)
{
	stream << "[";
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << arr[arr.size() - 1] << "]\n";
	return stream;
}

template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		stream >> arr[i];
	}
	return stream;
}
#endif