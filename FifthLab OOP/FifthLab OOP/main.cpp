#include<iostream>
#include"List.h"
#include <list>

int main()
{
	List<int> foo(10, 5), foo1;
	//std::cin >> foo;
	foo.PushFront(100);
	foo.PushPosition(1, 33);
	foo.PushAfterKey(33, 750);
	foo.PushBack(555);
	foo.PopPosition(1);
	std::cout << foo;
	return 0;
}