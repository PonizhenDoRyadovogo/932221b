#include<iostream>
#include"Set.h"

int main()
{
	Set s("Hello, World!");
	Set foo;
	std::cout << s;
	//foo = ~s;
	foo = s + 'm';
	std::cout << foo;
	std::cout << "Max = " << foo.Max() << " Min = " << foo.Min() << "\n";
	return 0;
	std::cout << foo;
	if (foo != s)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	Set goo = s & foo;
	std::cout << goo;
	return 0;
}