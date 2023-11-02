#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>

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
	m_insignificantRankCount = (m_cellCount * m_size) - m_length;
	m_cells = new UC[m_cellCount];
	uint8_t mask = 0;
	int i;
	if (value)
	{
		for (i = 0; i < m_cellCount; i++)
		{
			m_cells[i] |= ~mask;
		}
	}
	else
	{
		for (i = 0; i < m_cellCount; i++)
		{
			m_cells[i] &= mask;
		}
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::BoolVector(const BoolVector& other)
	:m_length(other.m_length)
{
	m_cellCount = other.m_cellCount;
	m_cells = new UC[m_cellCount];
	m_insignificantRankCount = (m_cellCount * m_size) - m_length;
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
}

BoolVector::BoolVector(const char* str)
{
	m_length = strlen(str);
	m_cellCount = m_length / 8 + bool(m_length % 8);
	m_insignificantRankCount = (m_cellCount * m_size) - m_length;
	m_cells = new UC[m_cellCount];//"10110111"
	for (int i = 0; i < m_length; i++)
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
	return (m_length - m_insignificantRankCount);
}

void BoolVector::PrintCell(const int& number_cell)const
{
	assert(number_cell >= 0 && number_cell < m_cellCount);

	for (uint8_t i = 128; i > 0; i >>= 1)// i == 10000000 in first try
	{
		if (m_cells[number_cell] & i)
			std::cout << "1 ";
		else
			std::cout << "0 ";
	}
}

void BoolVector::Print()const
{
	for (int i = 0; i < m_cellCount; i++)
	{
		std::cout << "[";
		PrintCell(i);
		std::cout << "]";
	}
	std::cout << std::endl;
}

void BoolVector::Set1(const int& cell, const int& pos_cell)
{
	uint8_t mask = 1;//00000001
	mask = mask << 7 - pos_cell;
	m_cells[cell] = m_cells[cell] | mask;
}

void BoolVector::Set0(const int& cell, const int& pos_cell)
{
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