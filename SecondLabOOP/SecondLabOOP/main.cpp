#include<iostream>
#include"Array.h"

template <typename ItemType>
double calculateAvg(Array<ItemType> arr)
{
	double avg = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		avg += arr[i];
	}
	avg /= arr.size();
	return avg;
}

int main()
{
	Array<int> arr(10, 2), arr2;
	std::cout << arr[3] << " " << arr[9] << std::endl;
	arr[3] = 3;
	arr[4] = arr[3];
	std::cout << "Average value " << calculateAvg(arr) << std::endl;
	std::cout << arr;
	std::cout << "index elemnt '3' = " << arr.Find(arr, 3)<<std::endl;
	std::cin>> arr2;
	std::cout << "arr2 = "<< arr2;
	arr.swap(arr2);
	std::cout << "arr = " << arr;
	std::cout << "arr2 = " << arr2;

}

