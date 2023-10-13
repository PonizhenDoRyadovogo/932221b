#include<iostream>
#include<time.h>

void Insert(int *a, int n, int key)//We go from the end of the array, look for a place, shifting the elements one by one to the right, 
//insert the number to the right place
{
	int i;
	for (i = n - 1; key < a[i] && i >= 0; i--)
		a[i + 1] = a[i];
	a[i + 1] = key;
}

void SortInsert(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		Insert(a, i, a[i]);
}

void RandArray(int *a,int n ,int left_lim, int right_lim)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % (right_lim - left_lim + 1) + left_lim;
}

void PrintArray(int* a, int n)
{
	std::cout << "[";
	for (int* p = a; p < a + n; p++)
		std::cout << *p << " ";
	std::cout << "]";
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
	CreateFile("Array.txt", arr, n);
	SortInsert(arr, n);
	PrintArray(arr, n);
	if (CheckSort(arr, n) == true)
		std::cout << " The array is sorted";
	else
		std::cout << " The array is not sorted";


}
