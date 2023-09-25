#include "Fraction.h"
#include <iostream>
#include <string>
void Fraction::PrintFract()const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}
Fraction Fraction::Add(const Fraction &k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator + k.m_numerator * m_denominator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}
Fraction Fraction::Subtractions(const Fraction &k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator - k.m_numerator * m_denominator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}
Fraction Fraction::Multipliction(const Fraction &k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_numerator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}
Fraction Fraction::Division(const Fraction &k)const
{
	if (k.m_numerator == 0)
	{
		std::cerr << "the division operation is not possible because the numerator is 0. Result will be second farction"<<std::endl;
		return k;
	}
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator;
	res.m_denominator = m_denominator * k.m_numerator;
	return res;
}
Fraction::Fraction()
{
	m_numerator = 1;
	m_denominator = 1;
}
Fraction::Fraction(int numerator, int denominator)//это не трогать
//первая очередь инициализации
	: m_numerator(numerator)//1 это часть класса, 2 то что мы передаем(область видимости)

{
	//третья очередь инициализации. Сейчас m_denominator == 1, m_numerator == numerator;
	if (denominator == 0)
	{
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
		//ничего не меняем m_denominator и так 1
	}
	else
	{
		m_denominator = denominator;
	}
	if (denominator < 0)//если минус находится в знаменателе, то его переносим в числитель
	{
		m_denominator *= -1;
		m_numerator *= -1;
	}

}
int Fraction::getNumerator()const
{
	return m_numerator;
}

int Fraction:: getDenominator()const
{
	return m_denominator;
}

void Fraction::setNumerator(const int value)
{
	m_numerator = value;
}

void Fraction::setDenominator(int value)
{
	if (value == 0)
	{
		std::cout << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.";
		m_denominator = 1;
	}
	else {
		m_denominator = value;
	}
}
int HCF(int numerator, int denominator)//algorithm's Evklid
{
	if (numerator == 0)
		return 1;
	while (numerator != denominator)
	{
		if (numerator > denominator)
			numerator -= denominator;
		else
			denominator -= numerator;
	}
	return numerator;
}
void Fraction::Reduce()
{
	int hcf = HCF(m_numerator, m_denominator);
	m_numerator = m_numerator / hcf;
	m_denominator = m_denominator / hcf;
}
bool Fraction:: operator == (const Fraction other) const
{
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}
bool Fraction:: operator != (const Fraction other) const
{
	//сокращаем дублирование кода за счет уже реализованных методов
	return !operator == (other);
}
bool Fraction:: operator < (const Fraction other) const
{
	return ((m_numerator * other.m_denominator) < (other.m_numerator * m_denominator));
}
bool Fraction:: operator > (const Fraction other) const
{
	return ((m_numerator * other.m_denominator) > (other.m_numerator * m_denominator));
}
Fraction Fraction::operator +(const Fraction other) const
{
	return Add(other);
}
Fraction Fraction::operator -(const Fraction other)const
{
	return Subtractions(other);
}
Fraction Fraction::operator *(const Fraction other)const
{
	return Multipliction(other);
}
Fraction Fraction::operator /(const Fraction other)const
{
	return Division(other);
}
Fraction Fraction::FlippingFraction()//own method
{
	if (m_numerator == 0)
	{
		std::cerr << "Method FlippingFraction cannot be executed." << std::endl;
		return *this;
	}
	else
	{
		int temp = m_numerator;
		m_numerator = m_denominator;
		m_denominator = temp;
		return *this;
	}
}
void Fraction ::Fraction::Input()
{
	std::cout << "Enter the numerator : ";
	std::cin >> m_numerator;

	std::cout << "Enter the denominator : ";
	std::cin >> m_denominator;

	while (m_denominator == 0) {
		std::cout << ("Denominator can`t be zero! Please, enter a vallid denominator: ");
		std::cin >> m_denominator;
	}
}
Fraction& Fraction:: operator +=(const Fraction &other)//own method
{
	m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
	m_denominator = m_denominator * other.m_denominator;
	return *this;
}