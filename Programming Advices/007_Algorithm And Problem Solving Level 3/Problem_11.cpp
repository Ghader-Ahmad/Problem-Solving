#include <iostream>
using namespace std;

int RandomNumbers(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumbers(1, 10);
		}
	}
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));
}

void PrintMatrixArray(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d      ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1 : \n";
	PrintMatrixArray(Matrix1, 3, 3);

	FillArrayWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2 : \n";
	PrintMatrixArray(Matrix2, 3, 3);

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
	{
		cout << "\n\nYes : Matrixes are equal.\n";
	}
	
	else
	{
		cout << "\n\nNo : Matrixes are NOT equal.\n";
	}

	return 0;
}