#include<iostream>
#include"Array.h"
#include<time.h>
#include<algorithm>
template <typename ItemType>
double calculateAvg(Array<ItemType> arr)
{
	double avg = 0;
	for (int i = 0; i < arr.Size(); ++i)
	{
		avg += arr[i];
	}
	avg /= arr.Size();
	return avg;
}

template <typename ItemType>
void bubbleSort(Array<ItemType> &arr)
{
	int i, j, n = arr.Size();
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
}

void RandomArray(Array<int> &arr,const int left_lim, const int right_lim)
{
	for (int i = 0; i < arr.Size(); i++)
		arr[i] = rand() % (right_lim - left_lim + 1) + left_lim;
}

int main()
{
	srand(time(0));
	Array<int> arr(10, 2), arr2, arr3, arr4, arr5(5), arr6(5), arr7(5);
	arr5[0] = 25;
	arr5[4] = 25;
	std::cout << arr[3] << " " << arr[9] << std::endl;
	arr[0] = 3;
	arr[4] = arr[3];
	std::cout << "Average value " << calculateAvg(arr) << std::endl;
	std::cout << arr;
	std::cout << "index element '3' = " << arr.Find(3)<<std::endl;
	std::cin>> arr2;
	std::cout << "arr2 = "<< arr2;
	arr.Swap(arr2);
	std::cout << "arr = " << arr;
	std::cout << "arr2 = " << arr2;
	arr2 += arr ;
	std::cout << "+=: arr2 = " << arr2;
	arr2 = arr2 + 100;
	std::cout << "Array + value: arr2 = " << arr2;
	arr2 += 33;
	std::cout << "Array += value: arr2 = " << arr2;
	std::cout << "== and !=\n";
	if (arr2 == arr3)
		std::cout << "arr2 == arr3" << std::endl;
	else
		std::cout << "arr2 != arr3" << std::endl;
	if (arr2 != arr3)
		std::cout << "arr2 != arr3" << std::endl;
	else
		std::cout << "arr2 == arr3" << std::endl;
	RandomArray(arr4, 1, 10);
	std::cout << "Random arr4 = " << arr4<<std::endl;
	bubbleSort(arr4);
	std::cout << "Sorted arr4 = " << arr4 << std::endl;
	if (arr4.InsertIndex(9, 100))
		std::cout <<"Insert off index: arr4 = " << arr4<< std::endl;
	else
		std::cout << "Insert off index: index incorrect" << std::endl;
	if(arr4.DeleteOffIndex(3))
		std::cout << "Delete off index: arr4 = " << arr4 << std::endl;
	else
		std::cout << "Delete off index: index incorrect" <<std::endl;
	if(arr2.DeleteOffValue(33))
		std::cout << "Delete off value: arr2 = " << arr2 << std::endl;
	else
		std::cout << "Delete off value: value not found" << std::endl;
	std::cout << "arr5 = " << arr5 << std::endl;
	if(arr5.DeleteOffValueAll(25))
		std::cout << "Delete off all values: arr5 = " << arr5 << std::endl;
	else
		std::cout << "Delete off all values: values not found" << std::endl;
	std::cout << "Max element off arr2: " << arr2.SearchMax()<<std::endl;
	std::cout << "Min element off arr2: " << arr2.SearchMin() << std::endl;

	Array<int>::TmpIterator iter_b = arr4.Begin();
	std::cout << "Iterator to the beginning of the arr4: " << *iter_b << std::endl;
	Array<int>::TmpIterator iter_end = arr4.End();
	std::cout << "Iterator to the ending of the arr4: " << *(--iter_end) << std::endl;
	if (iter_b == iter_end)
		std::cout << "Iterators are equal" << std::endl;
	else
		std::cout << "Iterators are not equal" << std::endl;
	iter_b = arr5.Begin();
	if (arr5.InsertIter(iter_b, 25))
		std::cout << "Insert of iterator: arr5 = " << arr5 << std::endl;
	else
		std::cout << "Insert of iterator: false"<<std::endl;
	RandomArray(arr6, 1, 10);
	std::cout << "arr6 = " << arr6 << std::endl;
	Array<int>::TmpIterator left = arr6.Begin(), right = arr6.End();
	for (int i = 0; i < 2; i++)
		--right;
	//left++;
	if (arr6.DeleteOfIteratorRange(left, right))
		std::cout << "Delete of range: arr6 = " << arr6 << std::endl;
	else
		std::cout << "Index invalid" << std::endl;
	RandomArray(arr7, 1, 10);
	std::cout << "arr 7 = " << arr7 << std::endl;
	iter_b = arr7.Begin();
	iter_b++;
	if (arr7.DeleteOfIterator(iter_b))
		std::cout << "Delete of iterator: arr7 = " << arr7 << std::endl;
	else
		std::cout << "Delete of iterator: false" << std::endl;
}



