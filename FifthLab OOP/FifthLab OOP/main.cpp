#include<iostream>
#include"List.h"

int main()
{
	List<int> foo;
	std::cin >> foo;
	std::cout << foo;
	List<int>::Node* ptr = foo.FindValue(5);


	return 0;
}