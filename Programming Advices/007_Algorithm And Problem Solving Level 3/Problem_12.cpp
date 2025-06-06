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

void PrintMatrix(int arr[3][3], short Rows, short Cols)
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

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	FillArrayWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2 : \n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
	{
		cout << "\n\nYes : Matrices are typical.\n";
	}
	else
	{
		cout << "\n\nNo : Matrices are NOT typical.\n";
	}

	return 0;
}
