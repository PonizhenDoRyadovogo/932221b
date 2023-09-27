#include<iostream>
#include"Array.h"

int main()
{
	Array arr(10, 0);
	std::cout << arr[3] << " " << arr[9] << std::endl;
	//arr[3] = 4;
	//arr[4] = arr[3];
	arr.Print();
}
