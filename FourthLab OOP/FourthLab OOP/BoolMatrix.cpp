#include "BoolMatrix.h"
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.cpp"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>
#include<stdio.h>

BoolMatrix::BoolMatrix()
{
	m_columns = 8;
	m_lines = 1;
	m_bool = new BoolVector[m_lines];
	BoolVector bool1(m_columns, 1);
	m_bool[0] = bool1;
}

BoolMatrix::BoolMatrix(int columns, int lines, int value)
{
	assert(columns > 0 || lines > 0);
	m_bool = new BoolVector[m_lines = lines];
	m_columns = columns;
	for (int i = 0; i < m_lines; i++)
	{
		BoolVector bool1(columns, value);
		m_bool[i] = bool1;
	}
}

BoolMatrix::BoolMatrix(char** matrix, int lines)
{
	assert(lines > 0);
	m_columns = strlen(matrix[0]);
	m_lines = lines;
	m_bool = new BoolVector[m_lines];
	for (int i = 0; i < m_lines; i++)
	{
		m_bool[i] = BoolVector(matrix[i]);
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other)
	:m_columns(other.m_columns),
	m_lines(other.m_lines)
{
	m_bool = new BoolVector[m_lines];
	for (int i = 0; i < m_lines; i++)
	{
		m_bool[i] = other.m_bool[i];
	}
}

BoolMatrix::~BoolMatrix()
{
	delete []m_bool;
}

BoolVector& BoolMatrix::operator[](const int i)
{
	assert(i >= 0 || i < m_lines);
	return m_bool[i];
}

void BoolMatrix::PrintMatrix()const
{
	for (int i = 0; i < m_lines; i++)
	{
		std::cout << m_bool[i] << std::endl;
	}
}

int BoolMatrix::TakeCountLines()const
{
	return m_lines;
}

int BoolMatrix::TakeCountColumns()const
{
	return m_columns;
}

void BoolMatrix::Swap(BoolMatrix& other)
{
	std::swap(m_lines, other.m_lines);
	std::swap(m_columns, other.m_columns);
	std::swap(m_bool, other.m_bool);
}

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.TakeCountLines(); i++)
	{
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream, BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.TakeCountLines(); i++)
	{
		std::cout << matrix[i];
	}
	return stream;
}

int BoolMatrix::WeightMatrix()const
{
	int w = 0;
	for (int i = 0; i < m_lines; i++)
	{
		w += m_bool[i].Weight();
	}
	return w;
}

BoolVector BoolMatrix::ConjunctionLines(BoolMatrix& matr)const
{
	BoolVector res(m_bool[0]);
	for (int i = 1; i < m_lines; i++)
	{
		res &= m_bool[i];
	}
	return res;
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& matr)
{
	if (m_bool == matr.m_bool)
		return *this;
	if (m_lines != matr.m_lines)
	{
		m_lines = matr.m_lines;
		delete[] m_bool;
		m_bool = new BoolVector[m_lines];
	}
	m_columns = matr.m_columns;
	for (int i = 0; i < m_lines; i++)
	{
		m_bool[i] = matr.m_bool[i];
	}
	return *this;
}