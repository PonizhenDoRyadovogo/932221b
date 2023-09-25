#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(const int numerator, int denominator);
	~Fraction() = default;//��� ����� ��� �� �� ���������, �� �� �������� ��� ����
	void PrintFract()const;
	Fraction Add(const Fraction &k)const;
	Fraction Subtractions(const Fraction &k)const;
	Fraction Multipliction(const Fraction &k)const;
	Fraction Division(const Fraction &k)const;
	int getNumerator()const;
	int getDenominator()const;
	void setNumerator(const int value);
	void setDenominator(int value);
	void Reduce();
	//�� ��������� ����� ��� ���������, ���� ������������ ��� �����, �� �� ����� ������� reduce() ����� �������������� ������� ������ 
	bool operator == (const Fraction other) const;
	bool operator != (const Fraction other)const;
	bool operator < (const Fraction other)const;
	bool operator > (const Fraction other)const;
	Fraction operator +(const Fraction other)const;
	Fraction operator -(const Fraction other)const;
	Fraction operator *(const Fraction other)const;
	Fraction operator /(const Fraction other)const;
	Fraction FlippingFraction();
	void Input();
	Fraction& operator +=(const Fraction& other);
private:
	//��������� ���������� ������� �������� � �������� m_
	int m_numerator = 0;//������ ������� �������������
	int m_denominator = 1;//������ ������� �������������
};
