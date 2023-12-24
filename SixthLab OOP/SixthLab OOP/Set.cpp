#include<iostream>
#include<string>
#include "Set.h"

Set::Set()
	:BoolVector(m_size)
{
}

Set::Set(const char* str)
	:BoolVector(m_size)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if ((int)str[i] < (m_size + m_shift) && (int)str[i] >= m_shift)
		{
			Set1InRange((int)str[i] - m_shift);
		}
	}
}

Set::Set(const Set& other)
	:BoolVector(other)
{
}

bool Set::Find(const char value)const
{
	if ((int)value >= m_shift || (int)value < m_size)
		return false;
	else
		return (operator[]((int)value - m_shift));
}

int Set::Capacity()const
{
	return BoolVector::Weight();
}

char Set::Max()const
{
	char max;
	if (BoolVector::operator[](m_size - 1))
	{
		max = (char)((m_size - 1) + m_shift);
		return max;
	}
	else
	{
		for (int i = m_size - 2; i >= 0; --i)
		{
			if ((BoolVector::operator[](i)))
			{
				max = (char)(i + m_shift);
				return max;
			}
		}
	}
}

char Set::Min()const
{
	char min = 0;
	if(BoolVector::operator[](0))
		return min = (char)(m_shift);
	else
	{
		for (int i = 1; i < m_size; ++i)
		{
			if ((BoolVector::operator[](i)))
			{
				min = (char)(i + m_shift);
				return min;
			}
		}
	}
}

Set& Set::operator=(const Set& other)
{
	if (this == &other)
		return *this;
	BoolVector::operator=(other);
	return *this;
}

bool Set::operator==(const Set& other)const
{
	return BoolVector::operator==(other);
}

bool Set::operator!=(const Set& other)const
{
	return !(*this == other);
}

Set& Set::operator|=(const Set& other)
{
	BoolVector::operator|=(other);
	return *this;
}

Set Set::operator|(const Set& other)const
{
	Set tmp(*this);
	tmp |= other;
	return tmp;
}

Set& Set::operator&=(const Set& other)
{
	BoolVector::operator&=(other);
	return *this;
}

Set Set::operator&(const Set& other)const
{
	Set tmp(*this);
	tmp &= other;
	return tmp;
}

Set Set::operator/=(const Set& other)
{
	BoolVector::operator&=(~other);
	return *this;
}

Set Set::operator/(const Set& other)const
{
	Set tmp(*this);
	tmp /= other;
	return tmp;
}

Set Set::operator~()const
{
	Set res(*this);
	res.Inversion();
	return res;
}

/*
*@Set Set::operator+ 
* @return *this
* 
* 
* как это сделать?
*/

Set Set::operator+(const char value)const
{
	if ((int)value >= m_shift || (int)value < m_size)
	{
		Set tmp(*this);
		tmp.Set1InRange((int)value - m_shift);
		return tmp;
	}
	return *this;
}

Set Set::operator+=(const char value)
{
	*this = *this + value;
	return *this;
}

Set Set::operator-(const char value)const
{
	if ((int)value >= m_shift || (int)value < m_size)
	{
		Set tmp(*this);
		tmp.Set0InRange((int)value - m_shift);
		return tmp;
	}
	return *this;
}

Set Set::operator-=(const char value)
{
	*this = *this - value;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Set& set)
{
	for (int i = 0; i < Set::m_size; ++i)
	{
		if (set[i] > 0)
			stream << (char)(i+Set::m_shift) <<"("<<i+Set::m_shift<<")"<<" ";
	}
	stream << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Set& set)
{
	std::string str;
	std::getline(stream, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if ((int)str[i] < (Set::m_size + Set::m_shift) && (int)str[i] >= Set::m_shift)
		{
			set.Set1InRange((int)str[i] - Set::m_shift);
		}
	}
	return stream;
}