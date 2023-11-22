#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>
#include<stdio.h>

#include "BoolMatrix.h"

BoolMatrix::BoolMatrix()
{
	m_columns = 8;
	m_rows = 1;
	m_bool = new BoolVector[m_rows];
	BoolVector bool1(m_columns, 1);
	m_bool[0] = bool1;
}

BoolMatrix::BoolMatrix(int rows, int columns, bool value)
{
	assert(columns > 0 || rows > 0);
	m_bool = new BoolVector[m_rows = rows];
	m_columns = columns;
	for (int i = 0; i < m_rows; i++)
	{
		BoolVector bool1(columns, value);
		m_bool[i] = bool1;
	}
}

BoolMatrix::BoolMatrix(char** matrix, int rows)
{
	assert(rows > 0);
	m_columns = strlen(matrix[0]);
	m_rows = rows;
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = BoolVector(matrix[i]);
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other)
	: m_columns(other.m_columns)
	, m_rows(other.m_rows)
{
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = other.m_bool[i];
	}
}

BoolMatrix::~BoolMatrix()
{
	delete []m_bool;
}

const BoolVector& BoolMatrix::operator[](const int i) const
{
	assert(i >= 0 || i < m_rows);
	return m_bool[i];
}

BoolVector& BoolMatrix::operator[](const int i)
{
	assert(i >= 0 || i < m_rows);
	return m_bool[i];
}

void BoolMatrix::Print()const
{
	for (int i = 0; i < m_rows; i++)
	{
		std::cout << m_bool[i] << std::endl;
	}
}

int BoolMatrix::GetRowsCount()const
{
	return m_rows;
}

int BoolMatrix::GetColumnsCount()const
{
	return m_columns;
}

void BoolMatrix::Swap(BoolMatrix& other)
{
	std::swap(m_rows, other.m_rows);
	std::swap(m_columns, other.m_columns);
	std::swap(m_bool, other.m_bool);
}

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.GetRowsCount(); i++)
	{
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream,const BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.GetRowsCount(); i++)
	{
		stream << matrix[i];
	}
	return stream;
}

int BoolMatrix::Weight()const
{
	int w = 0;
	for (int i = 0; i < m_rows; i++)
	{
		w += m_bool[i].Weight();
	}
	return w;
}

BoolVector BoolMatrix::ConjunctionRows(const BoolMatrix& matr)const
{
	BoolVector res(m_bool[0]);
	for (int i = 1; i < m_rows; i++)
	{
		res &= m_bool[i];
	}
	return res;
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& matr)
{
	if (m_bool == matr.m_bool)
		return *this;
	if (m_rows != matr.m_rows)
	{
		m_rows = matr.m_rows;
		delete[] m_bool;
		m_bool = new BoolVector[m_rows];
	}
	m_columns = matr.m_columns;
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = matr.m_bool[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix tmp(*this);
	for (int i = 0; i < m_rows; i++)
	{
		tmp.m_bool[i] &= other.m_bool[i];
	}
	return tmp;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix tmp(*this);
	for (int i = 0; i < m_rows; i++)
	{
		tmp.m_bool[i] |= other.m_bool[i];
	}
	return tmp;
}

BoolMatrix& BoolMatrix::operator&=(const BoolMatrix& other)
{
	BoolMatrix tmp = *this & other;
	Swap(tmp);
	return *this;
}

BoolMatrix& BoolMatrix::operator|=(const BoolMatrix& other)
{
	BoolMatrix tmp = *this | other;
	Swap(tmp);
	return *this;
}

BoolVector BoolMatrix::DisjunctionRows(const BoolMatrix& other)const
{
	BoolVector res(m_bool[0]);
	for (int i = 1; i < m_rows; i++)
	{
		res |= m_bool[i];
	}
	return res;
}

int BoolMatrix::RowWeight(const int j)const
{
	assert(j >= 0 && j < m_rows);
	int w = m_bool[j].Weight();
	return w;
}

void BoolMatrix::Inversion(const int i, const int j)
{
	assert(i >= 0 && i < m_columns && j >= 0 && j < m_rows);
	m_bool[j][i] = ~m_bool[j][i];
}

void BoolMatrix::Set0(const int i, const int j)
{
	assert(i >= 0 && i < m_columns && j >= 0 && j < m_rows);
	m_bool[j][i] = 0;
}

void BoolMatrix::Set1(const int i, const int j)
{
	assert(i >= 0 && i < m_columns && j >= 0 && j < m_rows);
	m_bool[j][i] = 1;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix tmp(*this);
	for (int i = 0; i < m_rows; i++)
	{
		tmp.m_bool[i] ^= other.m_bool[i];
	}
	return tmp;
}

BoolMatrix& BoolMatrix::operator^=(const BoolMatrix& other)
{
	BoolMatrix tmp = *this ^ other;
	Swap(tmp);
	return *this;
}

BoolMatrix BoolMatrix::operator~()const
{
	BoolMatrix copy(*this);
	for (int i = 0; i < m_rows; i++)
	{
		copy.m_bool[i].Inversion();
	}
	return copy;
}

void BoolMatrix::InvertRange(int row, const int from, const int count)
{
	assert(row >= 0 && row < m_columns && from >= 0 && from < m_rows && (count + row) < m_columns);
	for (int k = 1; k <= count; k++)
	{
		m_bool[from][row] = ~m_bool[from][row];
		row++;
	}
}

void BoolMatrix::SetRange0(int i, const int from, const int count)
{
	assert(i >= 0 && i < m_columns&& from >= 0 && from < m_rows && (count + i) < m_columns);
	for (int k = 1; k <= count; k++)
	{
		m_bool[from][i] = 0;
		i++;
	}
}

void BoolMatrix::SetRange1(int i, const int from, const int count)
{
	assert(i >= 0 && i < m_columns&& from >= 0 && from < m_rows && (count + i) < m_columns);
	for (int k = 1; k <= count; k++)
	{
		m_bool[from][i] = 1;
		i++;
	}
}