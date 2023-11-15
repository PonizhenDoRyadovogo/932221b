#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

BoolVector::BoolVector()
{
	m_length = 8;
	m_cellCount = 1;
	m_cells = new UC[m_cellCount];
	m_cells[0] = false;
}

BoolVector::BoolVector(UI length, const bool value)
{
	assert(length >= 0);

	m_length = length;
	m_cellCount = length / 8 + bool(length % 8);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	m_cells = new UC[m_cellCount];
	uint8_t mask = 0;
	if (value)
	{
		mask = ~mask;
	}
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = mask;
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::BoolVector(const BoolVector& other)
	:m_length(other.m_length)
{
	m_cellCount = other.m_cellCount;
	m_cells = new UC[m_cellCount];
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
}

BoolVector::BoolVector(const char* str)
{
	m_length = strlen(str);
	m_cellCount = m_length / 8 + bool(m_length % 8);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	m_cells = new UC[m_cellCount];
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '1')
			Set1(i / 8, i % 8);
		else
			Set0(i / 8, i % 8);
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector:: ~BoolVector()
{
	delete[] m_cells;
}

int BoolVector::Length()const
{
	return m_length;
}

void BoolVector::Set1(const int cell, const int pos_cell)
{
	assert(cell >= 0 || cell < m_cellCount || pos_cell < m_cellSize);
	uint8_t mask = 1;//00000001
	mask = mask << 7 - pos_cell;
	m_cells[cell] = m_cells[cell] | mask;
}

void BoolVector::Set0(const int cell, const int pos_cell)
{
	assert(cell >= 0 || cell < m_cellCount || pos_cell < m_cellSize);
	uint8_t mask = 1;//00000001
	mask = mask << 7 - pos_cell;
	m_cells[cell] = m_cells[cell] & ~mask;
}

void BoolVector::Inversion()
{
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = ~m_cells[i];
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

void BoolVector::Swap(BoolVector& other)
{
	std::swap(m_length, other.m_length);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_insignificantRankCount, other.m_insignificantRankCount);
	std::swap(m_cells, other.m_cells);
}

BoolVector BoolVector::operator ~()const
{
	BoolVector copy(*this);
	copy.Inversion();
	return copy;
}

BoolVector& BoolVector::operator=(const BoolVector& other)
{
	if (m_cells == other.m_cells)
		return *this;
	if (m_cellCount != other.m_cellCount)
	{
		m_cellCount = other.m_cellCount;
		delete[] m_cells;
		m_cells = new UC[m_cellCount];
	}
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
	m_length = other.m_length;
	m_insignificantRankCount = other.m_insignificantRankCount;
	return *this;
}

BoolVector BoolVector::operator&(const BoolVector& other)const
{
	assert(m_length == other.m_length);
	BoolVector tmp(m_length);
	for (int i = 0; i < m_cellCount; i++)
	{
		tmp.m_cells[i] = m_cells[i] & other.m_cells[i];
	}
	return tmp;
}

BoolVector BoolVector::operator|(const BoolVector& other)const
{
	assert(m_length == other.m_length);
	BoolVector tmp(m_length);
	for (int i = 0; i < m_cellCount; i++)
	{
		tmp.m_cells[i] = m_cells[i] | other.m_cells[i];
	}
	return tmp;
}

BoolVector BoolVector::operator^(const BoolVector& other)const
{
	assert(m_length == other.m_length);
	BoolVector tmp(m_length);
	for (int i = 0; i < m_cellCount; i++)
	{
		tmp.m_cells[i] = m_cells[i] ^ other.m_cells[i];
	}
	return tmp;
}

BoolVector& BoolVector::operator&=(const BoolVector& other)
{
	BoolVector tmp = *this & other;
	Swap(tmp);
	return *this;
}

BoolVector& BoolVector::operator|=(const BoolVector& other)
{
	BoolVector tmp = *this | other;
	Swap(tmp);
	return *this;
}

BoolVector& BoolVector::operator^=(const BoolVector& other)
{
	BoolVector tmp = *this ^ other;
	Swap(tmp);
	return *this;
}

BoolVector::BoolRank::BoolRank(UC* cell, const int maskoffset)
{
	m_cell = cell;
	m_mask >>= maskoffset;
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const bool value)
{
	if (value == 0)
		(*m_cell) &= ~m_mask;
	else
		(*m_cell) |= m_mask;
	return *this;
}

BoolVector::BoolRank BoolVector::operator[](const int index)
{
	return BoolRank(m_cells + index / m_cellSize, index % m_cellSize);
}

const BoolVector::BoolRank BoolVector::operator[](const int index)const
{
	return BoolRank(m_cells + index / m_cellSize, index % m_cellSize);
}

void BoolVector::BoolRank::Print()
{
	m_mask = m_mask & *m_cell;
	if (m_mask == 0)
		std::cout << "0";
	else
		std::cout << "1";
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const BoolRank &other)
{
	operator=((bool)other);
	return *this;
}


BoolVector BoolVector::operator>>(const int count)const
{
	assert(count >= 0);
	BoolVector tmp(*this);
	if (count / m_cellSize > 0)
	{
		for (int i = tmp.m_cellCount - 1; i >= 0; i--)
		{
			if (i - count / tmp.m_cellSize >= 0)
			{
				tmp.m_cells[i] = m_cells[i - (count / tmp.m_cellSize)];
				tmp.m_cells[i - (count / tmp.m_cellSize)] = 0;
			}
			else
				tmp.m_cells[i] = 0;
		}
	}
	tmp.m_cells[m_cellCount - 1] >>= count % m_cellSize;
	for (int i = tmp.m_cellCount - 2; i >= 0; i--)
	{
		UI mask = 0;
		mask |= tmp.m_cells[i];
		mask <<= m_cellSize - count % m_cellSize;
		tmp.m_cells[i + 1] |= mask;
		tmp.m_cells[i] >>= count % m_cellSize;
	}
	tmp.m_cells[m_cellCount - 1] >>= m_insignificantRankCount;
	tmp.m_cells[m_cellCount - 1] <<= m_insignificantRankCount;
	return tmp;
}

BoolVector BoolVector::operator<<(const int count)const
{
	assert(count >= 0);
	BoolVector tmp(*this);
	if (count / m_cellSize == 0)
	{
		tmp.m_cells[0] <<= count;
		for (int i = 1; i < tmp.m_cellCount; i++)
		{
			UI mask = 0;
			mask |= tmp.m_cells[i];
			mask >>= m_cellSize - count;
			tmp.m_cells[i - 1] |= mask;
			tmp.m_cells[i] <<= count;
		}
	}
	else
	{	
		for (int i = 0; i < tmp.m_cellCount; i++)	
		{
			if (i + count / tmp.m_cellSize < tmp.m_cellCount)
			{
				tmp.m_cells[i] = m_cells[i + (count / tmp.m_cellSize)];
				tmp.m_cells[i + (count / tmp.m_cellSize)] = 0;
			}
			else
			{
				tmp.m_cells[i] = 0;
			}
		}
		tmp.m_cells[0] <<= count % m_cellSize;
		for (int i = 1; i < tmp.m_cellCount; i++)
		{
			UI mask = 0;
			mask |= tmp.m_cells[i];
			mask >>= m_cellSize - count % m_cellSize;
			tmp.m_cells[i - 1] |= mask;
			tmp.m_cells[i] <<= count % m_cellSize;
		}
	}
	tmp.m_cells[m_cellCount - 1] >>= m_insignificantRankCount;
	tmp.m_cells[m_cellCount - 1] <<= m_insignificantRankCount;
	return tmp;
}

BoolVector BoolVector::operator >>=(const int count)
{
	*this = *this >> count;
	return *this;
}

BoolVector BoolVector::operator <<=(const int count)
{
	*this = *this << count;
	return *this;
}

void BoolVector::Set1InRange(int index, const int range)
{
	assert(index >= 0 || (index < m_cellCount&& range < m_length));
	for (int i = 1; i <= range; i++)
	{
		Set1(index / m_cellSize, index % m_cellSize);
		index++;
	}
}

void BoolVector::Set0InRange(int index, const int range)
{
	assert(index >= 0 || (index < m_cellCount && range <= m_length));
	for (int i = 1; i <= range; i++)
	{
		Set0(index / m_cellSize, index % m_cellSize);
		index++;
	}
}

void BoolVector::Set1All()
{
	Set1InRange(0, m_length);
}

void BoolVector::Set0All()
{
	Set0InRange(0, m_length);
}

int BoolVector::Weight()
{
	int count = 0;
	for (int i = 0; i < m_cellCount; i++)
	{
		for (int j = 0; j < m_cellSize; j++)
		{
			UI mask = 128;
			mask >>= j;
			mask &= m_cells[i];
			if (mask)
				count++;
		}
	}
	return count;
}

BoolVector::BoolRank::operator bool() const
{
	uint8_t copy_mask = m_mask;
	copy_mask &= *m_cell;
	if (copy_mask == m_mask)
		return true;
	else
		return false;
}

std::ostream& operator <<(std::ostream& stream, const BoolVector& vector)
{
	stream << "[";
		for (int j = 0; j < vector.m_length + vector.m_insignificantRankCount; j++)
		{
			if (j % 8 == 0 && j != 0)
				std::cout << "][";
			std::cout << (bool)vector[j]<<" ";
		}
		stream << "]" << std::endl;
	return stream;
}

std::istream& operator >>(std::istream& stream, BoolVector& vector)
{
	char* str = new char[vector.Length()];
	for (int i = 0; i < vector.Length(); i++)
	{
		stream >> str[i];
	}
	for (int i = 0; i < vector.Length(); i++)
	{
		if (str[i] != '0')
			vector[i] = 1;
		else
			vector[i] = 0;
	}
	delete[]str;
	return stream;
}

bool BoolVector::BoolRank::operator==(BoolRank& other)const
{
	return (*this == (bool)other);
}

bool BoolVector::BoolRank::operator==(const bool value)const
{
	if ((bool)*this == value)
		return true;
	else
		return false;
}

bool BoolVector::BoolRank::operator~()const
{
	if ((bool)*this)
		return false;
	else
		return true;
}

bool BoolVector::BoolRank::operator&(const bool value)const
{
	if (value == 0)
		return false;
	else
		return ((bool)*this & true);
}

bool BoolVector::BoolRank::operator|(const bool value)const
{
	if (value)
		return true;
	else
		return ((bool)*this | false);
}

bool BoolVector::BoolRank::operator^(const bool value)const
{
	if (value == (bool)*this)
		return false;
	else
		return true;
}