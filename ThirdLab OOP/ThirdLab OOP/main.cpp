#include<iostream>
#include"BoolVector.h"

int main()
{
	BoolVector bool1, bool2(32,4);
	bool1.Print();
	bool2.Print();
	bool1.Set1(0, 1);
	bool1.Print();
}