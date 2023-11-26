#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

void PrintArray(std::vector<int> a, int l, int r)
{
	std::cout << "[";
	for (int i = l; i <= r; i++)
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
	int mask = 1 << k;
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

int IndexFirstNegative(std::vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
			return i;
	}
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
	std::vector<int> copy;
	int index = IndexFirstNegative(arr);
	for (int i = index; i < arr.size(); i++)
		copy.push_back(arr[i]);
	for (int i = 0; i < index; i++)
		copy.push_back(arr[i]);
	std::swap(copy, arr);
	copy.clear();
}

void FileInArray(const char* name, std::vector<int>& arr)
{
	std::ifstream fin(name);
	int n;
	if (!fin.good())
		std::cout << "File not found!" << std::endl;
	else
	{
		while (fin >> n)
			arr.push_back(n);
	}
	fin.close();
}

float AverageTimeWorkBitSort(const char* name)
{
	float average_time = 0;
	const int count = 3;
	std::vector<int> origin;
	FileInArray(name, origin);
	for (int i = 0; i <= count; i++)
	{
		std::vector<int> copy = origin;
		auto start = std::chrono::high_resolution_clock::now();
		BitSort(copy);
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		if (!CheckSort(copy))
			std::cout << "Try " << i << " .The array is not sorted" << std::endl;
	}
	average_time /= count;
	return average_time;
}

int main()
{
	std::cout << "=============BitSort Sort=============" << std::endl;
	for (int size = 10000; size <= 1000000; size *= 10)
	{
		for (int range = 10; range <= 100000; range *= 100)
		{
			std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
			float average_time = AverageTimeWorkBitSort(name.c_str());
			std::cout << "Numbers of element = " << size << " range[-" << range << ";" << range << "]" << std::endl;
			std::cout << "Average time = " << average_time << " ms" << std::endl;
		}
	}
}
