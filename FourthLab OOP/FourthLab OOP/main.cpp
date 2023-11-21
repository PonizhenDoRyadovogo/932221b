#include<iostream>
#include<stdio.h>
#include"BoolMatrix.h"

char** CharMatrix(int lines, int columns)
{
	char** matrix = new char* [lines];
	for (int i = 0; i < lines; i++) {
		matrix[i] = new char[columns + 1];
		int j = 0;
		for (j = 0; j < columns; j++) {
			std::cin >> matrix[i][j];
		}
		matrix[i][j] = '\0';
	}
	return matrix;
}

char** RandCharMatrix(int lines, int columns)
{
	char** matrix = new char* [lines];
	for (int i = 0; i < lines; i++) {
		matrix[i] = new char[columns + 1];
		int j = 0;
		for (j = 0; j < columns; j++) {
			matrix[i][j] = (rand() % 2) == 0? '0' : '1';
		}
		matrix[i][j] = '\0';
	}
	return matrix;
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

void DeleteMatrix(int lines, int columns, char** matrix)
{
	for (int i = 0; i < lines; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{	
	srand(time(0));

	char** char_matr = RandCharMatrix(2, 8);
	OutputCharMatrix(char_matr, 2, 8);
	BoolMatrix matr(char_matr, 2);
	std::cout<<"matr:\n" << matr;
	DeleteMatrix(2, 8, char_matr);
	return 0;

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

