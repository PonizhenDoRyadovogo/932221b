#include<iostream>
#include"BoolVector.h"

int main()
{
	BoolVector bool1, bool2(35,4), bool3(bool2);
	std::cout << "bool1 = " << bool1;
	std::cout << "bool2 = "<<bool2;

	bool1.Set1(0, 1);
	std::cout << "bool1 = "<<bool1;

	bool1.Set0(0, 1);
	std::cout << "bool1 = "<<bool1;

	std::cout << "Constuctor copy: bool3 = "<<bool3;
	
	BoolVector bool4 = "101110110001";
	std::cout << "bool4 = "<<bool4;

	bool4.Inversion();
	std::cout << "~bool4 = " << bool4;
	
	std::cout << "Swap bool4 and bool2\n";
	bool4.Swap(bool2);
	std::cout << "bool2 = "<<bool2;
	std::cout << "bool4 = " << bool4;

	bool2 = ~bool2;
	std::cout << "~bool2 = "<<bool2;

	bool2 = bool4;
	std::cout << "Make bool2 = bool4\n";
	std::cout << "bool2 = "<<bool2;

	BoolVector bool5 = "110001110111101";
	std::cout << "bool5 = "<<bool5;

	BoolVector bool6 = "101100011011101";
	std::cout << "bool6 = "<<bool6;

	bool5 = bool5 & bool6;
	std::cout << "Work of & for BoolVector: bool5 = bool5 & bool6\n";
	std::cout << "bool5 = "<<bool5;

	bool5 = bool5 | bool6;
	std::cout << "Work of & for BoolVector: bool5 = bool5 | bool6\n";
	std::cout << "bool5 = "<<bool5;

	bool5 = bool5 ^ bool6;
	std::cout << "Work of & for BoolVector: bool5 = bool5 ^ bool6\n";
	std::cout << "bool5 = "<<bool5;

	BoolVector bool7 = "10011011101110001";
	std::cout << "bool7 = "<<bool7;

	BoolVector bool8 = "11011101101010001";
	std::cout << "bool8 = "<<bool8;

	bool8 ^= bool7;
	std::cout << "bool8 ^= bool7\n";
	std::cout << "bool8 = "<<bool8;

	bool7 >>= 3;
	std::cout << "bool7 >>=  3\n";
	std::cout << "bool7 = "<<bool7;

	bool7 <<= 3;
	std::cout << "bool7 <<= 3\n";
	std::cout << "bool7 = "<<bool7;

	bool7.Set0InRange(0, 10);
	std::cout << "Work of Set0 in range:\n";
	std::cout << "bool7 = "<<bool7;

	bool7.Set1InRange(0, 10);
	std::cout << "Work of Set1 in range:\n";
	std::cout << "bool7 = " << bool7;

	bool7.Set0All();
	std::cout << "All 0\n";
	std::cout << "bool7 = "<<bool7;

	int conunt_bool4 = bool4.Weight();
	std::cout << "count = " << conunt_bool4<<std::endl;

	int conunt_bool7 = bool7.Weight();
	std::cout << "count = " << conunt_bool7 << std::endl;

	bool4[10] = 0;
	std::cout << "bool 4 = "<<bool4;

	BoolVector bool9;
	std::cin >> bool9;
	std::cout << "bool9 = " << bool9;
}
