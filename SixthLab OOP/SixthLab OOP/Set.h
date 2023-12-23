#pragma once

#include<stdint.h>
#include<iostream>
#include"../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class Set: BoolVector
{
public:
	using UI = unsigned int;
	Set();
	Set(const char* str);
	Set(const Set& other);
	//~Set(); он не нужен, так как вызовется деструктор из BoolVector?
	bool Find(const char value)const;
	friend std::ostream& operator<<(std::ostream& stream, const Set& set);
	friend std::istream& operator>>(std::istream& stream, Set& set);
private:
	static const int m_size = 95;//start: space. end: ~
	static const int m_shift = 32;
};



