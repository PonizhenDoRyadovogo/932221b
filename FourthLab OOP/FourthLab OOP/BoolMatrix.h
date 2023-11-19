#pragma once
#include<stdint.h>
#include<iostream>
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class BoolMatrix
{
public:
	using UI = unsigned int;
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
	BoolVector ConjunctionLines(const BoolMatrix& matr)const;
	BoolMatrix& operator=(const BoolMatrix& matr);
	BoolMatrix operator&(const BoolMatrix& other)const;
	BoolMatrix operator|(const BoolMatrix& other)const;
	BoolMatrix& operator&=(const BoolMatrix& other);
	BoolMatrix& operator|=(const BoolMatrix& other);
	BoolVector Disjunction(const BoolMatrix& other)const;
	int WeightLinesMatrix(const int j)const;
	void InversionIJ(const int i, const int j);
	void Set0IJ(const int i, const int j);
	void Set1IJ(const int i, const int j);
	BoolMatrix operator^(const BoolMatrix& other)const;
	BoolMatrix& operator^=(const BoolMatrix & other);
	BoolMatrix operator~()const;
	void InversionIJInRange(int i, const int j, const int count);
	void Set0IJInRange(int i, const int j, const int count);
	void Set1IJInRange(int i, const int j, const int count);
private:
	BoolVector *m_bool;
	int m_columns;
	int m_lines;
};

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix);
std::ostream& operator <<(std::ostream& stream, BoolMatrix& matrix);
