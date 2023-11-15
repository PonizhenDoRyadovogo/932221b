#pragma once
#include<stdint.h>
#include<iostream>
#include "../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class BoolMatrix
{
public:
	BoolMatrix(int columns, int lines, int value);
	BoolVector& operator[](int i);
	void PrintMatrix()const;
private:
	BoolVector *m_bool;
	int m_columns;
	int m_lines;
};

