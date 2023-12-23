#include<iostream>
#include"Set.h"

int main()
{
	Set s("Hello World!");
	Set foo;
	std::cout << s;
	std::cin >> foo;
	std::cout << foo;
	if (foo.Find('W'))
		std::cout << "HAVE\n";
	else
		std::cout << "DONT HAVE\n";

	return 0;
}