#include <iostream>
#include <string.h>
#include <time.h>

void RandomMatrix(int **matr, int m)
{
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = 1 + rand() % (20 - 1 + 1);
}
void OutputMatrix(int** matr, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << matr[i][j]<< " ";
		std::cout<<std::endl;
	}
}
void OutputMas(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
		std::cout << *p << " ";
}
int AddMas(int* a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		k += a[i];
	return k;
}
int WeightWay(int* way, int** matr, int n)
{
	int min = 0;
	int i;
	for (i = 0; i < n - 1; i++)
		min += matr[way[i] - 1][way[i + 1] - 1];
	min += matr[way[i] - 1][way[0] - 1];
	return min;
}
void CopyMas(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++) b[i] = a[i];
}
void Swap(int& a, int& b)
{
	int x;
	x = a; a = b; b = x;
}
void SearchOptimalWeight(int* way, int** matr, int number_city, int *min_way)
{
	for (int k = 1; ; k++)
	{
		int max_i = -1, max_j;
		for (int i = 1; i < number_city - 1; i++)
		{
			if (way[i] < way[i + 1])
				max_i = i;
		}
		if (max_i == -1)
			break;
		for (int j = max_i + 1; j <= number_city - 1; j++)
		{
			if (way[j] > way[max_i])
				max_j = j;
		}
		Swap(way[max_i], way[max_j]);
		int j = number_city - 1;
		int i = max_i + 1;
		while (i < j)
		{
			Swap(way[i], way[j]);
			i++;
			j--;
		}
		if (WeightWay(way, matr, number_city) < WeightWay(min_way, matr, number_city))
			CopyMas(way, min_way, number_city + 1);
		OutputMas(way, number_city + 1);
		std::cout << " weight " << WeightWay(way, matr, number_city) << std::endl;
	}
}
int main()
{
	srand(time(0));
	int** matr_way_weight, number_city, starting_city, *way, *min_way;
	std::cout << "enter the number of cities: ";
	std::cin >> number_city;
	std::cout << std::endl <<"enter the number of starting city: ";
	std::cin >> starting_city;
	//создаем матрицу стоимостей маршрутов
	matr_way_weight = new int* [number_city];//выделяем память под массив указателей
	for (int i = 0; i < number_city; i++)//выделяем память под каждую "строку"
		matr_way_weight[i] = new int[number_city];
	RandomMatrix(matr_way_weight, number_city);
	for (int i = 0; i < number_city; i++)//зануляем диагонали матрицы
		matr_way_weight[i][i] = 0;
	OutputMatrix(matr_way_weight, number_city);
	way = new int[number_city + 1];//создаем массив, в котором будут храниться пути
	min_way = new int [number_city + 1];
	//создаем первый путь
	for (int i = 0, n = 1; i < number_city + 1; )
	{
		if (i == 0 || i == number_city)
			way[i++] = starting_city;
		else if (n != starting_city)
			way[i++] = n++;
		else if (++n == starting_city)//если n == стартовому городу, то нужно увеличить n и записать его, после этого увеличить n
			way[i++] = n++;
	}
	OutputMas(way, number_city + 1);
	std::cout << " weight " << WeightWay(way, matr_way_weight, number_city) << std::endl;
	CopyMas(way, min_way, number_city + 1);//предполагаем, то что наш начальный путь может быть минимальным 
	SearchOptimalWeight(way, matr_way_weight, number_city, min_way);

	std::cout << "minimum weight path ";
	OutputMas(min_way, number_city + 1);
	std::cout << "his weight " << WeightWay(min_way, matr_way_weight, number_city);

	//удаляем память, выделенную под матрицу
	for (int i = 0; i < number_city; i++)
		delete[] matr_way_weight[i];
	delete[] matr_way_weight;
	//удаляем память, выделенную под массив
	delete[] way;
	delete[] min_way;
}