#include "Fraction.h"
#include <iostream>
#include <string>
int main()
{
	Fraction f, k, resadd, ressub, resmul, resdiv;
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
	resdiv.PrintFract();
}