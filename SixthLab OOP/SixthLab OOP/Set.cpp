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
	if ((int)value >= m_size || (int)value < m_shift)
		return false;
	else
		return (operator[]((int)value - m_shift));
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