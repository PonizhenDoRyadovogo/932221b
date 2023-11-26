#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

void PrintArray(std::vector<int> a)
{
	std::cout << "[";
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << "]";
}

bool CheckSort(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

int FindMax(std::vector<int>& arr)
{
	int max = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}



void BitwiseSort(std::vector<int>& arr, int left_lim, int right_lim, int k)
{
	if (left_lim >= right_lim || k < 0)
		return;
	int i = left_lim, j = right_lim;
	unsigned int mask = 1 << k;
	while (i <= j)
	{
		while (i <= j && (arr[i] & mask) == 0)
			i++;
		while (i <= j && (arr[j] & mask) != 0)
			j--;
		if (i < j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	BitwiseSort(arr, left_lim, j, k - 1);
	BitwiseSort(arr, i, right_lim, k - 1);
}

void BitSort(std::vector<int> &arr)
{
	int max = FindMax(arr);
	int k = 0;
	while (max)
	{
		max >>= 1;
		k++;
	}
	BitwiseSort(arr, 0, arr.size() - 1, k);
}

int main()
{
	std::vector<int> arr = { 5, 4, -3, -2, 1 };
	BitSort(arr);
	PrintArray(arr);
}
