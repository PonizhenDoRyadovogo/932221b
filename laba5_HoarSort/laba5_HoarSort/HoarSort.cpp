#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

bool CheckSort(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
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


void HoarSort(std::vector<int>& arr, const int left_lim, const int right_lim)
{
	if (left_lim >= right_lim)
		return;
	int i = left_lim, j = right_lim, refernce_value = arr[(left_lim + right_lim) / 2];
	while (i <= j)
	{
		while (arr[i] < refernce_value)
			i++;
		while (arr[j] > refernce_value)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	HoarSort(arr, left_lim, j);
	HoarSort(arr, i, right_lim);
}

float AverageTimeWorkHoarSort(const char* name)
{
	float average_time = 0;
	const int count = 3;
	std::vector<int> origin;
	FileInArray(name, origin);
	for (int i = 0; i <= count; i++)
	{
		std::vector<int> copy = origin;
		auto start = std::chrono::high_resolution_clock::now();
		HoarSort(copy, 0, copy.size() - 1);
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
	std::cout << "=============Hoar Sort=============" << std::endl;
	for (int size = 10000; size <= 1000000; size *= 10)
	{
		for (int range = 10; range <= 100000; range *= 100)
		{
			std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
			float average_time = AverageTimeWorkHoarSort(name.c_str());
			std::cout << "Numbers of element = " << size << " range[-" << range << ";" << range << "]" << std::endl;
			std::cout << "Average time = " << average_time << " ms" << std::endl;
		}
	}
}