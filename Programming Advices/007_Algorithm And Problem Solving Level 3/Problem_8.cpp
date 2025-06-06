#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillMatrixArrayWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixArray(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d     ", 2,  arr[i][j]);
		}
		cout << "\n";
	}
}

void MultiplyMatrix(int arr1[3][3], int arr2[3][3], int arrMulti[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrMulti[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

	FillMatrixArrayWithRandomNumber(Matrix1, 3, 3);
	cout << "\nMatrix 1 : \n";
	PrintMatrixArray(Matrix1, 3, 3);

	FillMatrixArrayWithRandomNumber(Matrix2, 3, 3);
	cout << "\n\nMatrix 2 : \n";
	PrintMatrixArray(Matrix2, 3, 3);

	MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);
	cout << "\n\nResults : \n";
	PrintMatrixArray(MatrixResults, 3, 3);

	return 0;
}
