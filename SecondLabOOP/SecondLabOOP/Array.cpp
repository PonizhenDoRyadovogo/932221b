#ifndef ARRAY_TEMPLATE_LABS
#define ARRAY_TEMPLATE_LABS
#include"Array.h"
#include<algorithm>
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
	m_array = new ItemType[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = value;
	}

}

template <typename ItemType>
Array<ItemType>::Array(const Array& other)
	:m_size(other.m_size)
{
	m_array = new ItemType[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

template <typename ItemType>
Array<ItemType>::Array(Array&& other)
{
	Swap(other);
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
const ItemType& Array<ItemType>:: operator [](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
ItemType& Array<ItemType>:: operator [](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template <typename ItemType>
int Array<ItemType>::Size() const
{
	return m_size;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator = (Array&& other)
{
	Swap(other);
	return *this;//��� ������� � �������������� swap
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator = (const Array& other)//a = a
{
	if (this == &other)
	{
		return *this;
	}
	if (m_size != other.m_size)
	{
		m_size = other.m_size;
		delete[] m_array;
		m_array = new ItemType[m_size];
	}
	for (int i = 0; i < m_size;i++)
	{
		m_array[i] = other.m_array[i];
	}
	return *this;
}
//���� ������ ������ �� �������� � �����, �� ����������� ����� ���� = � ������������ �����������

template <typename ItemType>
Array<ItemType> Array<ItemType>:: operator +(const Array& other)const
{
	Array res(m_size + other.m_size);
	for (int i = 0, j = 0; i < res.m_size; i++) {
		if (i < m_size) {
			res[i] = m_array[i];
		}
		else {
			res[i] = other.m_array[j];
			j++;
		}
	}
	return res;
}

template <typename ItemType>
void Array<ItemType>::Swap(Array& other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

template <typename ItemType>
void Array<ItemType>::Resize(int size)
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
	res.Swap(*this);
}
template <typename ItemType>
Array<ItemType>& Array<ItemType>:: operator +=(const Array& other)
{
	Array tmp = *this + other;//�������� ����������� �����������
	Swap(tmp);
	return *this;
}

template <typename ItemType>
int Array<ItemType>::Find(const ItemType& value)const
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_array[i] == value)
		{
			return i;//if match are found, then return index element
		}
	}
	return -1;//if no matches are found, then return -1
}

template <typename ItemType>
Array<ItemType> Array<ItemType>:: operator +(const ItemType &value)const
{
	Array tmp_Array(m_size + 1, 0);
	for (int i = 0; i < m_size; ++i)
	{
		tmp_Array.m_array[i] = m_array[i];
	}
	tmp_Array.m_array[m_size] = value;
	return tmp_Array;
}

template <typename ItemType>
Array<ItemType> &Array<ItemType>::operator+=(const ItemType &value)
{
	*this = *this + value;
	return *this;
}

template <typename ItemType>
bool Array<ItemType>::operator ==(const Array& other)const
{
	if (this == &other)
	{
		return true;
	}
	if (m_size != other.m_size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < m_size; ++i)
			if (m_array[i] != other.m_array[i])
				return false;
	}
	return true;
}

template <typename ItemType>
bool Array<ItemType>:: operator !=(const Array& other)const
{
	return !operator==(other);
}

template <typename ItemType>
bool Array<ItemType>::InsertIndex(int index, const ItemType& value)
{
	if (index >= m_size || index<0)
		return false;
	int i;
	this->Resize(m_size + 1);
	for (i = m_size - 2; i >= index; i--)
		m_array[i + 1] = m_array[i];
	m_array[i + 1] = value;
	return true;
}

template <typename ItemType>
bool Array<ItemType>::DeleteOffIndex(int index)
{
	if (index >= m_size || index < 0)
		return false;
	int i;
	for (i = index; i < m_size - 1;i++)
		m_array[i] = m_array[i + 1];
	this->Resize(m_size - 1);
	return true;
}

template <typename ItemType>
bool Array<ItemType>::DeleteOffValue(const ItemType& value)
{
	int index = this->Find(value);
	if (index == -1)
		return false;
	else
		this->DeleteOffIndex(index);
	return true;
}

template <typename ItemType>
bool Array<ItemType>::DeleteOffValueAll(const ItemType &value)
{
	int index = this->Find(value);
	if (index == -1)
		return false;
	else
	{
		while (index >= 0)
		{
			this->DeleteOffIndex(index);
			index = this->Find(value);
		}
	}
	return true;
}

template <typename ItemType>
ItemType Array<ItemType>::SearchMax()const
{
	assert(m_size != 0);
	int i = 0;
	ItemType max = m_array[i];
	for (i = 1; i < m_size; i++)
	{
		if (m_array[i] > max)
			max = m_array[i];
	}
	return max;
}

template <typename ItemType>
ItemType Array<ItemType>::SearchMin()const
{
	assert(m_size != 0);
	int i = 0;
	ItemType min = m_array[i];
	for (i = 1; i < m_size; i++)
	{
		if (m_array[i] < min)
			min = m_array[i];
	}
	return min;
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr)
{
	stream << "[";
	for (int i = 0; i < arr.Size() - 1; ++i)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << arr[arr.Size() - 1] << "]\n";
	return stream;
}

template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType>& arr)
{
	for (int i = 0; i < arr.Size(); ++i)
	{
		stream >> arr[i];
	}
	return stream;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::Iterator<IT, AT>::Iterator(AT* array, int pos)
	:m_array(array),
	m_pos(pos)
{
}

template <typename ItemType>
template<typename IT, typename AT>
IT& Array<ItemType>::Iterator<IT, AT>::operator*()
{
	return m_array->operator[](m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::Iterator<IT, AT>& Array<ItemType>::Iterator<IT, AT>::operator++()
{
	++m_pos;
	return *this;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::Iterator<IT, AT>& Array<ItemType>::Iterator<IT, AT>::operator--()
{
	--m_pos;
	return *this;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::Iterator<IT, AT> Array<ItemType>::Iterator<IT, AT>::operator++(int)
{
	auto old(*this);
	++m_pos;
	return old;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::Iterator<IT, AT> Array<ItemType>::Iterator<IT, AT>::operator--(int)
{
	auto old(*this);
	--m_pos;
	return old;
}

template <typename ItemType>
template<typename IT, typename AT>
int Array<ItemType>::Iterator<IT, AT>::Position()const
{
	return m_pos;
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::Iterator<IT, AT>::operator ==(const Iterator& other)const
{
	assert(m_array == other.m_array);
	return (m_array == other.m_array && m_pos == other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::Iterator<IT, AT>::operator!=(const Iterator& other)const
{
	return!(operator == (other));
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::Iterator<IT, AT>::operator<=(const Iterator& other)const
{
	assert(m_array == other.m_array);
	return(m_array == other.m_array && m_pos <= other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::Iterator<IT, AT>::operator<(const Iterator& other)const
{
	assert(m_array == other.m_array);
	return(m_array == other.m_array && m_pos < other.m_pos);
}

template <typename ItemType>typename
Array<ItemType>:: TmpIterator Array<ItemType>::Begin()
{
	return TmpIterator(this, 0);
}

template <typename ItemType>typename
Array<ItemType>::TmpIterator Array<ItemType>::End()
{
	return TmpIterator(this, m_size);
}

template<typename ItemType>typename
Array<ItemType>::TmpConstIterator Array<ItemType>::Begin()const
{
	return TmpConstIterator(this, 0);
}

template<typename ItemType>typename
Array<ItemType>::TmpConstIterator Array<ItemType>::End()const
{
	return TmpConstIterator(this, m_size);
}

template<typename ItemType>typename
bool Array<ItemType>::InsertIter(TmpIterator iter, const ItemType& value)
{
	if (iter.Position() > m_size || iter < Begin())
		return false;
	int index = iter.Position();
	if (iter == Begin())
		return this->InsertIndex(index, value);
	else if(index == m_size)//if this is the last index of the array, then just add a number to the end of the array
	{
		*this += value;//adding a value to the end of the array
		return true;
	}
	index--;
	return this->InsertIndex(index, value);
}

template<typename ItemType>typename
bool Array<ItemType>::DeleteOfIteratorRange(const TmpIterator &left, TmpIterator right)
{
	if (left.Position() < 0 || left.Position() > right.Position() || right.Position() > m_size)
		return false;
	if (right == End())
		--right;
	int j = 0;
	for (;left <= right; --right)
	{
		for (typename Array::TmpIterator i = left; i < End(); ++i)
			m_array[i.Position()] = m_array[i.Position() + 1];
		j++;
	}
	this->Resize(m_size - j);
	return true;
}

template<typename ItemType>typename
bool Array<ItemType>::DeleteOfIterator(TmpIterator iter)
{
	if (iter.Position() < 0 || iter.Position() > m_size)
		return false;
	if (iter == End())
		--iter;
	for (typename Array::TmpIterator i = iter; i < End(); ++i)
		m_array[i.Position()] = m_array[i.Position() + 1];
	this->Resize(m_size - 1);
	return true;
}

template <typename ItemType>
template<typename IT, typename AT>
IT& Array<ItemType>::Iterator<IT, AT>::operator[](const int value)
{
	return*(operator+(value));
}
#endif