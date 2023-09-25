#include "Fraction.h"
#include <iostream>
#include <string>
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	int n, d;
	cout << "enter first fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction a(n, d);
	cout << "a = ";
	a.PrintFract();
	cout << "enter second fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction b(n, d);
	cout << "b = ";
	b.PrintFract();

	cout << "Method set" << endl;
	a.setNumerator(5);
	a.setDenominator(7);
	cout << "When we used the method set, the fraction a = ";
	a.PrintFract();
	
	cout << "Method get" << endl;
	int numerator_b = b.getNumerator();
	int denominator_b = b.getDenominator();
	cout << "When we used the method set numerator fraction a = "<<numerator_b<<" denominator fraction a = "<<denominator_b<<endl;

	cout << "Work of default constructor. Fraction c = ";
	Fraction c;
	c.PrintFract();
	
	cout << "Work of methods: + - * /, performed by conventional methods" << endl;
	Fraction resadd, ressub, resmul, resdiv;
	resadd = a.Add(b);
	cout << "result addition fractions:";
	resadd.PrintFract();
	ressub = a.Subtractions(b);
	cout<< "result subtraction fractions:";
	ressub.PrintFract();
	resmul = a.Multipliction(b);
	cout << "result multiplucation fractions:";
	resmul.PrintFract();
	resdiv = a.Division(b);
	cout << "result division fractions:";
	resdiv.PrintFract();

	cout << "Work of method reduce" << endl;
	a.Reduce();
	b.Reduce();
	cout << "a = ";
	a.PrintFract();
	cout << "b = ";
	b.PrintFract();

	cout << "Work of methods: == != < >" << endl;
	if (a == b)
		cout << "Fractions is equal" << endl;
	else
		cout << "Fractions is not equal" << endl;
	if(a != b)
		cout << "Fractions is not equal" << endl;
	else
		cout << "Fractions is equal" << endl;
	bool temp = (a < b);
	cout << temp << endl;//if return 1 a<b, if return 0 a>b
	temp = (a > b);
	cout << temp << endl;//if return 1 a>b, if return 0 a<b

	cout << "Work of methods: + - * /, performed by overload" << endl;
	resadd = a + b;
	ressub = a - b;
	resmul = a * b;
	resdiv = a / b;
	cout << "Result addiction: ";
	resadd.PrintFract();
	cout << "Result substractions: ";
	ressub.PrintFract();
	cout << "Result multiplications: ";
	resmul.PrintFract();
	cout << "Result division: ";
	resdiv.PrintFract();

	cout << "Work of methods: FlippingFraction" << endl;
	cout << "a = ";
	a.PrintFract();
	cout << "flip";
	a.FlippingFraction();
	cout << " a = ";
	a.PrintFract();

	cout << "Work of methods: input" << endl;//own method
	Fraction fraction;
	fraction.Input();
	fraction.PrintFract();	

	cout << "Work of methods: +=" << endl;//own method
	a += b;
	a.PrintFract();
}
