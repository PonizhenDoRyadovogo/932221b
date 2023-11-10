#pragma once
#include<stdint.h>
#include<iostream>

class BoolVector
{
public:
	using UI = unsigned int;
	using UC = unsigned char;
	class BoolRank;
	BoolVector();
	BoolVector(const UI length, const bool value = false);
	BoolVector(const BoolVector& other);
	BoolVector(const char* str);
	~BoolVector();
	int Length()const;
	void Set1(const int cell, const int pos_cell);
	void Set0(const int cell, const int pos_cell);
	void Inversion();
	void Swap(BoolVector& other);
	BoolVector operator~()const;
	BoolVector& operator=(const BoolVector& other);
	BoolVector operator&(const BoolVector& other)const;
	BoolVector operator|(const BoolVector& other)const;
	BoolVector operator^(const BoolVector& other)const;
	BoolVector& operator&=(const BoolVector& other);
	BoolVector& operator|=(const BoolVector& other);
	BoolVector& operator^=(const BoolVector& other);
	BoolVector::BoolRank operator[](const int index);
	const BoolVector::BoolRank operator[](const int index)const;
	BoolVector operator>>(const int count)const;
	BoolVector operator<<(const int count)const;
	BoolVector operator>>=(const int count);
	BoolVector operator<<=(const int count);
	void Set1InRange(int index, const int range);
	void Set0InRange(int index, const int range);
	void Set1All();
	void Set0All();
	int Weight();
	friend std::ostream& operator <<(std::ostream& stream, const BoolVector& vector);
	
private:
	UI m_length = 0;//length vector
	UI m_cellCount = 0;//number cells
	uint8_t m_insignificantRankCount = 0;
	UC* m_cells = nullptr;
	static const uint8_t m_cellSize = 8;
};

class BoolVector::BoolRank
{
public:
	BoolRank(UC* cell, const int maskoffset);
	BoolRank& operator=(const bool value);
	void Print();
	BoolRank& operator=(const BoolRank &other);
	operator bool() const;
	bool operator==(BoolRank &other)const;
	bool operator==(const bool value)const;
	bool operator~()const;
	bool operator&(const bool value)const;
	bool operator|(const bool value)const;
	bool operator^(const bool vale)const;
private:
	uint8_t* m_cell = nullptr;
	uint8_t m_mask = 1 << 7;
};

std::istream& operator >>(std::istream& stream, BoolVector& vector);