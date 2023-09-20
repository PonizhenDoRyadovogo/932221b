#include "Fraction.h"
#include <iostream>
#include <string>
int main()
{
	using std::cin;
	using std::cout;
	int n, d;
	cout << "enter first fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction a(n, d);

	cout << "enter second fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction b(n, d);

	if (a == b)
	{
		cout << "Fractions is equal";
	}
	else
	{
		cout << "Fractions is not equal";
	}

}
/*Fraction f, k, resadd, ressub, resmul, resdiv;
	f.numerator = 1;
	f.denominator = 2;
	k.numerator = 3;
	k.denominator = 5;
	resadd = f.Add(k);
	std::cout << "result addition fractions:";
	resadd.PrintFract();
	ressub = f.Subtractions(k);
	std::cout << std::endl << "result subtraction fractions:";
	ressub.PrintFract();
	resmul = f.Multipliction(k);
	std::cout << std::endl << "result multiplucation fractions:";
	resmul.PrintFract();
	resdiv = f.Division(k);
	std::cout << std::endl << "result division fractions:";
	resdiv.PrintFract();*/