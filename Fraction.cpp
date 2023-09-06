#include "Fraction.h"
#include <iostream>
#include <string>
void Fraction::PrintFract()
{
	std::cout << numerator << "/" << denominator << std::endl;
}
Fraction Fraction::Add(Fraction k)
{
	Fraction res;
	res.numerator = numerator * k.denominator + k.numerator * denominator;
	res.denominator = denominator * k.denominator;
	return res;
}
Fraction Fraction::Subtractions(Fraction k)
{
	Fraction res;
	res.numerator = numerator * k.denominator - k.numerator * denominator;
	res.denominator = denominator * k.denominator;
	return res;
}
Fraction Fraction::Multipliction(Fraction k)
{
	Fraction res;
	res.numerator = numerator * k.numerator;
	res.denominator = denominator * k.denominator;
	return res;
}
Fraction Fraction::Division(Fraction k)
{
	Fraction res;
	res.numerator = numerator * k.denominator;
	res.denominator = denominator * k.numerator;
	return res;
}