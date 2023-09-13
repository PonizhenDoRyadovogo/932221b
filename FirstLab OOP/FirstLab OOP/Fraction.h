#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction() = default;//все равно был бы по умолчанию, но мы написали его явно
	void PrintFract();
	Fraction Add(Fraction k);
	Fraction Subtractions(Fraction k);
	Fraction Multipliction(Fraction k);
	Fraction Division(Fraction k);
	int numerator;
	int denominator;
};
