#include<iostream>
#include<vector>
#include<chrono>
#include<string>
#include<assert.h>
#include<fstream>

void Sift(std::vector<int>& a, const int size,int index)
{
	int descendant = 2 * index + 1, flag = 1, tmp = a[index];//tmp - parent
	while (descendant < size && flag)
	{
		if ((descendant + 1) < size)//check if the next descendant exists
		{
			if (a[descendant + 1] > a[descendant])//if the next descendant is larger than the previous one
				descendant++;//then we take the index of the next descendant (right)
		}
		if (a[descendant] > tmp)//if descendant > tmp(parent) 
		{
			a[index] = a[descendant];//then descendant falls into place parent
			index = descendant;
			descendant = 2 * index + 1;
		}
		else
			flag = 0;//if its not happend ===> good
	}
	a[index] = tmp;
}

void CreateHeap(std::vector<int>& a)
{
	const int size = a.size();
	for (int i = size / 2 - 1; i >= 0; i--)
		Sift(a, size,i);
}

void HeapSort(std::vector<int> &a)
{
	CreateHeap(a);
	int j;
	for (j = a.size() - 1; j > 0; j--)
	{
		std::swap(a[0], a[j]);
		Sift(a, j,0);
	}
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

float AverageTimeWorkHeapSort(const char *name)
{
	float average_time = 0;
	const int count = 3;
	std::vector<int> origin;
	FileInArray(name, origin);
	for (int i = 0; i <= count; i++)
	{
		std::vector<int> copy = origin;
		auto start = std::chrono::high_resolution_clock::now();
		HeapSort(copy);
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
	std::cout << "=============Heap Sort=============" << std::endl;
	for (int size = 10000; size <= 1000000; size *= 10)
	{
		for (int range = 10; range <= 100000; range *= 100)
		{
			std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
			float average_time = AverageTimeWorkHeapSort(name.c_str());
			std::cout << "Numbers of element = " << size << " range[-" << range << ";" << range << "]" << std::endl;
			std::cout << "Average time = " << average_time << " ms" << std::endl;
		}
	}
}