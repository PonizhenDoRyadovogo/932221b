#include<iostream>
#include"BoolVector.h"

int main()
{
	BoolVector bool1, bool2(35,4), bool3(bool2);
	std::cout << "bool1 = ";
	bool1.Print();
	std::cout << "bool2 = ";
	bool2.Print();
	std::cout << "=============================" << std::endl;
	bool1.Set1(0, 1);
	std::cout << "bool1 = ";
	bool1.Print();

	bool1.Set0(0, 1);
	std::cout << "bool1 = ";
	bool1.Print();
	std::cout << "bool3 = ";
	bool3.Print();
	
	BoolVector bool4 = "101110110001";
	std::cout << "bool4 = ";
	bool4.Print();

	bool4.Inversion();
	std::cout << "bool4 = ";
	bool4.Print();
	
	bool4.Swap(bool2);
	std::cout << "bool2 = ";
	bool2.Print();
	
	std::cout << "bool4 = ";
	bool4.Print();
}