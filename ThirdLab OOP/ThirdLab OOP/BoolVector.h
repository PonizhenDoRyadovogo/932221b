#pragma once
#include<stdint.h>
class BoolVector
{
public:
	using UI = unsigned int;
	using UC = unsigned char;

	BoolVector();
	BoolVector(const UI length, const bool value = false);
	BoolVector(const BoolVector& other);
	BoolVector(const char* str);
	~BoolVector();
	int Length()const;
	void PrintCell(const int& cellNumber)const;
	void Print()const;
	void Set1(const int& cell, const int& pos_cell);
	void Set0(const int& cell, const int& pos_cell);
	void Inversion();
	void Swap(BoolVector& other);
	
private:
	UI m_length = 0;//length vector
	UI m_cellCount = 0;//number cells
	uint8_t m_insignificantRankCount = 0;
	UC* m_cells = nullptr;
	const uint8_t m_size = 8;
};

