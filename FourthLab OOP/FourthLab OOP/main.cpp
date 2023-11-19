#include<iostream>
#include<stdio.h>
#include"BoolMatrix.h"

void InputCharMatrix(char** matr, int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cin >> &matr[i][j];
	}
}

void OutputCharMatrix(char** matr, int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		std::cout << "|";
		for (int j = 0; j < columns; j++)
			std::cout << matr[i][j] << " ";
		std::cout << "|" << std::endl;
	}
}

int main()
{
	BoolMatrix matrix(2, 8, 1), matrix_, matrix3(2, 16, 0);
	std::cout << "matrix:\n";
	std::cout << matrix;
	matrix.InversionIJ(0, 1);
	matrix.Set0IJ(1, 0);
	std::cout << "matrix:\n";
	std::cout << matrix;

	std::cout << "~matrix:\n";
	matrix = ~matrix;
	std::cout << matrix;

	return 0;
	std::cout << "weight = " << matrix.WeightMatrix()<<std::endl;

	BoolMatrix copy_matrix(matrix);
	std::cout << "copy_matrix:\n";
	copy_matrix.PrintMatrix();

	BoolMatrix matrix2(3, 8, 1);
	std::cout << "matrix2:\n";
	matrix2.PrintMatrix();
	matrix.Swap(matrix2);
	std::cout << "Work swap:\n" << "matrix:\n ";
	matrix.PrintMatrix();
	std::cout << "matrix2:\n";
	matrix2.PrintMatrix();

	matrix2 = matrix;
	std::cout << "matrix2:\n" << matrix2;

	std::cout << "matrix_:\n";
	matrix_.PrintMatrix();

	std::cin >> matrix_;
	std::cout << "matrix_:\n";
	matrix_.PrintMatrix();

	std::cout << "matrix3:\n";
	matrix3.PrintMatrix();

	std::cin >> matrix3;
	std::cout << "matrix3:\n";
	matrix3.PrintMatrix();

}

//char** matr;
	//matr = new char* [5];
	//for (int i = 0; i < 5; i++)
	//{
	//	matr[i] = new char[12];
	//}
	//InputCharMatrix(matr, 5, 12);
	//OutputCharMatrix(matr, 5, 12);

	//BoolMatrix matrix1(matr, 5);
	//matrix1.PrintMatrix();

	////delete memory of char matrix
	//for (int i = 0; i < 5; i++)
	//	delete[] matr[i];
	//delete[] matr;