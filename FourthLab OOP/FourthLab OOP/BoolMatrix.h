#pragma once
#include<stdint.h>
#include<iostream>
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class BoolMatrix
{
public:
	BoolMatrix();
	BoolMatrix(int columns, int lines, int value);
	BoolMatrix(char** matrix, int lines);
	BoolMatrix(const BoolMatrix& other);
	~BoolMatrix();
	BoolVector& operator[](const int i);
	void PrintMatrix()const;
	int TakeCountLines()const;
	int TakeCountColumns()const;
	void Swap(BoolMatrix& other);
	int WeightMatrix()const;
	BoolVector ConjunctionLines(BoolMatrix& matr)const;
	BoolMatrix& operator=(const BoolMatrix& matr);
private:
	BoolVector *m_bool;
	int m_columns;
	int m_lines;
};

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix);
std::ostream& operator <<(std::ostream& stream, BoolMatrix& matrix);
