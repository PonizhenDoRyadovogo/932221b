#include "BoolMatrix.h"
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.cpp"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

BoolMatrix::BoolMatrix(int columns, int lines, int value)
{
	m_bool = new BoolVector[m_lines = lines];
	m_columns = columns;
	for (int i = 0; i < m_lines; i++)
	{
		BoolVector bool1(columns, value);
		m_bool[i] = bool1;
	}
}

BoolVector& BoolMatrix::operator[](int i)
{
	assert(i > 0 || i < m_lines);
	return m_bool[i];
}

void BoolMatrix::PrintMatrix()const
{
	for (int i = 0; i < m_lines; i++)
	{
		std::cout << m_bool[i] << std::endl;
	}
}
