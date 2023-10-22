#include<iostream>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>

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
	while (step < arr.size())
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

void AverageTimeWorkShell(std::vector<int>& arr, const char* name, float &average_time)
{
	average_time = 0;
	for (int i = 1; i <= 3; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		SortShell(arr);
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		/*if (CheckSort(arr))
			std::cout <<"Try "<< i << " .The array is sorted" << std::endl;
		else
			std::cout <<"Try "<< i << " .The array is not sorted" << std::endl;*/
		arr.clear();
		FileInArray("FirstArray10000_in_range10.txt", arr);
	}
	average_time /= 3;
}

void AverageTimeWorkShellKnuth(std::vector<int>& arr, const char* name, float& average_time)
{
	average_time = 0;
	for (int i = 1; i <= 3; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		SortShellKnuth(arr);
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		/*if (CheckSort(arr))
			std::cout <<"Try "<< i << " .The array is sorted" << std::endl;
		else
			std::cout <<"Try "<< i << " .The array is not sorted" << std::endl;*/
		arr.clear();
		FileInArray("FirstArray10000_in_range10.txt", arr);
	}
	average_time /= 3;
}

void AverageTimeWorkShellHibbard(std::vector<int>& arr, const char* name, float& average_time)
{
	average_time = 0;
	for (int i = 1; i <= 3; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		SortShellHibbard(arr);
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		/*if (CheckSort(arr))
			std::cout <<"Try "<< i << " .The array is sorted" << std::endl;
		else
			std::cout <<"Try "<< i << " .The array is not sorted" << std::endl;*/
		arr.clear();
		FileInArray("FirstArray10000_in_range10.txt", arr);
	}
	average_time /= 3;
}

int main()
{
	srand(time(0));
	std::vector<int> arr10k_range10, arr10k_range1k, arr10k_range100k, arr100k_range10, arr100k_range1k, arr100k_range100k, arr1kk_range10, arr1kk_range1000, arr1kk_range100k;
	float average_time = 0;
	FileInArray("FirstArray10000_in_range10.txt", arr10k_range10);
	FileInArray("SecondArray10000_in_range1000.txt", arr10k_range1k);
	FileInArray("ThirdArray10000_in_range100000.txt", arr10k_range100k);

	FileInArray("FirstArray100000_in_range10.txt", arr100k_range10);
	FileInArray("SecondArray100000_in_range1000.txt", arr100k_range1k);
	FileInArray("ThirdArray100000_in_range100000.txt", arr100k_range100k);

	FileInArray("FirstArray1000000_in_range10.txt", arr1kk_range10);
	FileInArray("SecondArray1000000_in_range1000.txt", arr1kk_range1000);
	FileInArray("ThirdArray1000000_in_range100000.txt", arr1kk_range100k);

	//Shell's step
	std::cout << "===========Sort Shell===========\n";
	AverageTimeWorkShell(arr10k_range10, "FirstArray10000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr10k_range1k, "SecondArray10000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr10k_range100k, "ThirdArray10000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr100k_range10, "FirstArray100000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr100k_range1k, "SecondArray100000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr100k_range100k, "ThirdArray100000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr1kk_range10, "FirstArray1000000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShell(arr1kk_range1000, "SecondArray1000000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;
	
	AverageTimeWorkShell(arr1kk_range100k, "ThirdArray1000000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	//Knuth's step
	std::cout << "===========Sort Shell with step's Knuth===========\n";
	AverageTimeWorkShellKnuth(arr10k_range10, "FirstArray10000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr10k_range1k, "SecondArray10000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr10k_range100k, "ThirdArray10000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr100k_range10, "FirstArray100000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr100k_range1k, "SecondArray100000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr100k_range100k, "ThirdArray100000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr1kk_range10, "FirstArray1000000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr1kk_range1000, "SecondArray1000000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellKnuth(arr1kk_range100k, "ThirdArray1000000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;
	
	//Hibbard's step
	std::cout << "===========Sort Shell with step's Hibbard===========\n";
	AverageTimeWorkShellHibbard(arr10k_range10, "FirstArray10000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr10k_range1k, "SecondArray10000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr10k_range100k, "ThirdArray10000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 10000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr100k_range10, "FirstArray100000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr100k_range1k, "SecondArray100000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr100k_range100k, "ThirdArray100000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 100000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr1kk_range10, "FirstArray1000000_in_range10.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-10;10]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr1kk_range1000, "SecondArray1000000_in_range1000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-1000;1000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;

	AverageTimeWorkShellHibbard(arr1kk_range100k, "ThirdArray1000000_in_range100000.txt", average_time);
	std::cout << "Numbers of element = 1000000, range[-100000;100000]\n";
	std::cout << "Average time = " << average_time << " ms" << std::endl;
	average_time = 0;
}



	