#include<iostream>
#include"List.h"
#include <list>

int main()
{
	List<int> foo(10, 5), foo1(11, 2);
	std::cout << foo;
	std::cout << foo1;
	if (foo == foo)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0;
}