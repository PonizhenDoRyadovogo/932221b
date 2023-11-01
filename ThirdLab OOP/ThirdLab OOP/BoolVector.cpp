#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>

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
	if (value)
	{
		for (int i = 0; i < m_cellCount; i++)
		{
			m_cells[i] |= ~mask;
		}
	}
	else
	{
		for (int i = 0; i < m_cellCount; i++)
		{
			m_cells[i] &= mask;
		}
	}
}

BoolVector:: ~BoolVector()
{
	delete[] m_cells;
}

int BoolVector::Length()const
{
	return m_length;
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
	
}