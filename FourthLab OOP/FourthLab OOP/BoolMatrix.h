#pragma once
#include<stdint.h>
#include<iostream>
#include<vector>
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class BoolMatrix
{
public:
	using UI = unsigned int;
	BoolMatrix();
	BoolMatrix(int rows, int columns, bool value);
	BoolMatrix(char** matrix, int rows);
	BoolMatrix(std::vector<std::vector<bool>>& vec);
	BoolMatrix(const BoolMatrix& other);
	~BoolMatrix();
	const BoolVector& operator[](const int i) const;
	BoolVector& operator[](const int i); 
	void Print()const;
	int GetRowsCount()const;	
	int GetColumnsCount()const; 
	void Swap(BoolMatrix& other);
	int Weight()const;
	BoolVector ConjunctionRows()const;
	BoolVector DisjunctionRows()const;
	BoolMatrix& operator=(const BoolMatrix& matr);
	BoolMatrix operator&(const BoolMatrix& other)const;
	BoolMatrix operator|(const BoolMatrix& other)const;
	BoolMatrix& operator&=(const BoolMatrix& other);
	BoolMatrix& operator|=(const BoolMatrix& other);
	int RowWeight(const int j)const; 
	void Inversion(const int i, const int j);
	void Set0(const int i, const int j);
	void Set1(const int i, const int j);
	BoolMatrix operator^(const BoolMatrix& other)const;
	BoolMatrix& operator^=(const BoolMatrix & other);
	BoolMatrix operator~()const;
	void InvertRange(int row, const int from, const int count);
	void SetRange0(const int row, int from, const int count);
	void SetRange1(const int row, int from, const int count);
private:
	BoolVector *m_bool;
	int m_columns;
	int m_rows;
};

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix);
std::ostream& operator <<(std::ostream& stream,const BoolMatrix& matrix);
