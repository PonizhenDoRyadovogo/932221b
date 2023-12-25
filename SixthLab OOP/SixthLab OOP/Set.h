#pragma once

#include<stdint.h>
#include<iostream>
#include"../../ThirdLab OOP/ThirdLab OOP/BoolVector.h"

class Set : BoolVector
{
public:
	using UI = unsigned int;
	Set();
	Set(const char* str);
	Set(const Set& other);
	//~Set(); он не нужен, так как вызовется деструктор из BoolVector?
	bool Find(const char value)const;
	int Cardinality()const;
/*
* @function Max
* @return returns the maximum element in the set. If if the set is empty, returns ~
*
*/
	char Max()const;
/*
* @function Min
* @return returns the minimum element in the set. If if the set is empty, returns 0
*
*/
	char Min()const;
	Set& operator=(const Set& other);
	bool operator==(const Set& other)const;
	bool operator!=(const Set& other)const;
	Set& operator|=(const Set& other);
	Set operator|(const Set& other)const;
	Set& operator&=(const Set& other);
	Set operator&(const Set& other)const;
	Set operator/=(const Set& other);
	Set operator/(const Set& other)const;
	Set operator~()const;
	Set operator+(const char value)const;
	Set operator+=(const char value);
	Set operator-(const char value)const;
	Set operator-=(const char value);
	friend std::ostream& operator<<(std::ostream& stream, const Set& set);
	friend std::istream& operator>>(std::istream& stream, Set& set);
private:
	static const int m_size = 95;//start: space. end: ~
	static const int m_shift = 32;
};



