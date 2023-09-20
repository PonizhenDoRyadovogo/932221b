#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(const int numerator, int denominator);
	~Fraction() = default;//все равно был бы по умолчанию, но мы написали его явно
	void PrintFract()const;
	Fraction Add(const Fraction &k)const;
	Fraction Subtractions(const Fraction &k)const;
	Fraction Multipliction(const Fraction &k)const;
	Fraction Division(const Fraction &k)const;
	int getNumerator()const;
	int getDenominator()const;
	void setNumerator(const int value);
	void setDenominator(int value);
	//не сокращает дроби при сравнении, если программисту это нужно, то он может вызвать reduce() перед использованием данного метода 
	bool operator == (const Fraction other);
	bool operator != (const Fraction other);
private:
	//приватные переменные принято начинать с префикса m_
	int m_numerator = 0;//вторая очередь инициализации
	int m_denominator = 1;//вторая очередь инициализации
};
