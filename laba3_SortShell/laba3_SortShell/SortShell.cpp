#include<iostream>
#include<time.h>

void PrintArray(int* a, int n)
{
	std::cout << "[";
	for (int* p = a; p < a + n; p++)
		std::cout << *p << " ";
	std::cout << "]";
}

void SortInsert(int* arr, int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
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

void RandArray(int *a,int n ,int left_lim, int right_lim)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % (right_lim - left_lim + 1) + left_lim;
}

void CreateFile(const char* name, int *a, int n)
//name - имя создаваемого файла
//n - кол-во чисел
//lf - левая граница диапазона
//rt - правая граница диапазона
{
	FILE* f;
	errno_t f_err = fopen_s(&f, name, "w");
	if (f_err)
	{
		perror("error opening file in CreateFile");
		exit(-1);
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", a[i]);
	}
	fclose(f);
}

bool CheckSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

void SortShell(int* arr, int n)
{
	int step = n / 2, i, j , k, key;
	for (; step > 0; step /= 2)
	{
		for (i = 0; i < n; i++)
		{
			for (j = i + step; j < n; j += step)
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
}
int main()
{
	srand(time(0));
	int n, left_lim, right_lim;
	std::cout << "Enter the number of numbers in the array n = ";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "\nEnter the left limit of range: ";
	std::cin >> left_lim;
	std::cout << "\nEnter the right limit of range: ";
	std::cin >> right_lim;
	RandArray(arr, n, left_lim, right_lim);
	/*PrintArray(arr, n);
	std::cout << std::endl;*/
	/*CreateFile("Array.txt", arr, n);*/
	/*SortInsert(arr, n);*/
	SortShell(arr, n);
	/*PrintArray(arr, n);*/
	if (CheckSort(arr, n) == true)
		std::cout << " The array is sorted";
	else
		std::cout << " The array is not sorted";


}
