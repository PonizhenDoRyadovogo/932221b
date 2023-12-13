#include<iostream>
#include<stdio.h>
#include"BoolMatrix.h"

char** CharMatrix(int rows, int columns)
{
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[columns + 1];
		int j = 0;
		for (j = 0; j < columns; j++) {
			std::cin >> matrix[i][j];
		}
		matrix[i][j] = '\0';
	}
	return matrix;
}

char** RandCharMatrix(int rows, int columns)
{
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[columns + 1];
		int j = 0;
		for (j = 0; j < columns; j++) {
			matrix[i][j] = (rand() % 2) == 0? '0' : '1';
		}
		matrix[i][j] = '\0';
	}
	return matrix;
}

void OutputCharMatrix(char** matr, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "|";
		for (int j = 0; j < columns; j++)
			std::cout << matr[i][j] << " ";
		std::cout << "|" << std::endl;
	}
}

void DeleteMatrix(int rows, int columns, char** matrix)
{
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{	
	srand(time(0));

	BoolMatrix matrixnon(8, 16, 1);
	//std::cin >> matrixnon;
	matrixnon.SetRange0(1, 0, matrixnon.GetColumnsCount());
	std::cout << matrixnon;
	return 0;
	char** char_matr = RandCharMatrix(2, 8);
	OutputCharMatrix(char_matr, 2, 8);
	BoolMatrix matr(char_matr, 2);
	std::cout<<"matr:\n" << matr;
	DeleteMatrix(2, 8, char_matr);
	return 0;

	BoolMatrix matrix(2, 8, 1), matrix_, matrix3(2, 16, 0);
	std::cout << "matrix:\n";
	std::cout << matrix;
	matrix.Inversion(0, 1);
	matrix.Set0(1, 0);
	std::cout << "matrix:\n";
	std::cout << matrix;

	std::cout << "~matrix:\n";
	matrix = ~matrix;
	std::cout << matrix;

	
	std::cout << "weight = " << matrix.Weight()<<std::endl;

	BoolMatrix copy_matrix(matrix);
	std::cout << "copy_matrix:\n";
	copy_matrix.Print();

	BoolMatrix matrix2(3, 8, 1);
	std::cout << "matrix2:\n";
	matrix2.Print();
	matrix.Swap(matrix2);
	std::cout << "Work swap:\n" << "matrix:\n ";
	matrix.Print();
	std::cout << "matrix2:\n";
	matrix2.Print();

	matrix2 = matrix;
	std::cout << "matrix2:\n" << matrix2;

	std::cout << "matrix_:\n";
	matrix_.Print();

	std::cin >> matrix_;
	std::cout << "matrix_:\n";
	matrix_.Print();

	std::cout << "matrix3:\n";
	matrix3.Print();

	std::cin >> matrix3;
	std::cout << "matrix3:\n";
	matrix3.Print();

}

