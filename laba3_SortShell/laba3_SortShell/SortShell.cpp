#include<iostream>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
#include<string>
#include<assert.h>

void PrintArray(std::vector<int> a)
{
	std::cout << "[";
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << "]";
}

void SortInsert(std::vector<int> &arr)
{
	int i, j, key;
	for (i = 1; i < arr.size(); i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

bool CheckSort(std::vector<int> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void InsertWithStep(std::vector<int> &arr, int step)
{
	int i, j, k, key;
		for (i = 0; i < step; i++)
		{
			for (j = i + step; j < arr.size(); j += step)
			{
				key = arr[j];
				k = j - step;
				while (k >= 0 && arr[k] > key)
				{
					arr[k + step] = arr[k];
					k -= step;
				}
				arr[k + step] = key;
			}
		}
}

void SortShell(std::vector<int> &arr)
{
	int step = arr.size() / 2;
	for(; step > 0; step /= 2)
		InsertWithStep(arr, step);
	
}

void SortShellKnuth(std::vector<int> &arr)
{
	int step = 1;
	while (step < arr.size() / 3)
		step = 3 * step + 1;
	for(; step > 0; step = (step - 1)/3)
		InsertWithStep(arr, step);
}

void SortShellHibbard(std::vector<int>& arr)
{
	int step = 1;
	int degr = 2;
	while (degr * 2 - 1 < arr.size())
	{
		step = degr * 2 - 1;
		degr *= 2;
	}
	for (; step > 0; step = (step - 1) / 2)
		InsertWithStep(arr, step);
}

void FileInArray(const char *name, std::vector<int> &arr)
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

enum AlgType
{
	Shell,
	Knuth,
	Hibbard,
	End
};
float AverageTimeWorkShell(const char* name, AlgType algstep)
{
	float average_time = 0;
	const int count = 3;
	std::vector<int> origin;
	FileInArray(name, origin);
	for (int i = 1; i <= count; i++)
	{
		std::vector<int> copy = origin;
		auto start = std::chrono::high_resolution_clock::now();
		switch (algstep)
		{
		case Shell:
			SortShell(copy);
			break;
		case Knuth:
			SortShellKnuth(copy);
			break;
		case Hibbard:
			SortShellHibbard(copy);
			break;
		}
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		if (!CheckSort(copy))
			std::cout <<"Try "<< i << " .The array is not sorted" << std::endl;
	}
	average_time /= count;
	return average_time;
}

void OutputSelection(AlgType step)
{
	switch (step) 
	{
	case Shell:
		std::cout << "===========Sort Shell===========\n";
		break;
	case Knuth:
		std::cout << "===========Sort Shell with step's Knuth===========\n";
		break;
	case Hibbard:
		std::cout << "===========Sort Shell with step's Hibbard===========\n";
		break;
	default:
		std::cerr << "ERROR!";
	}
}

int main()
{
	for(int step = Shell; step < End; step++)
	{
		OutputSelection(AlgType(step));
		for (int size = 10000; size <= 1000000; size *= 10)
		{
			for (int range = 10; range <= 100000; range *= 100)
			{
				std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
				float average_time = AverageTimeWorkShell(name.c_str(), AlgType(step));
				std::cout << "Numbers of element = " << size << " range[-" << range << ";" << range << "]" << std::endl;
				std::cout << "Average time = " << average_time << " ms" << std::endl;
			}
		}
	}
}



	