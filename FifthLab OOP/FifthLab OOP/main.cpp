#include<iostream>
#include"List.h"

int main()
{
	List foo(10, 5), foo2;
	std::cout << "foo = ";
	foo.Print();
	if (foo.Empty())
		std::cout << "list is empty\n";
	else
		std::cout << "list isn't empty\n";
	std::cin >> foo2;
	std::cout << "foo2 = " << foo2 << std::endl;

	foo.Swap(foo2);
	std::cout<<"after swap\n";
	std::cout << "foo = " << foo << std::endl;
	std::cout << "foo2 = " << foo2 << std::endl;

	return 0;
	Array<int> arr;
	std::cin >> arr;
	List foo1(arr);
	std::cout << "foo1 = "<< foo1;


	return 0;
}