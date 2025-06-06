#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int Rand = rand() % (To - From + 1) + From;
	return Rand;
}

void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i <= Rows - 1; i++)
	{
		for (int j = 0; j <= Cols - 1; j++)
			arr[i][j] = RandomNumber(1, 100);
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "      ";
		}
		cout << "\n";
	}
}

int RowsSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (int j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void SumMatrixRowsInArray(int arr[3][3], short Rows, short Cols, int arrSum[3])
{
	for (int i = 0; i < Rows; i++)
	{
		arrSum[i] = RowsSum(arr, i, Cols);
	}
}

void PrintSingleArray(int arr[3], short Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillArrayWithRandomNumbers(arr, 3, 3);
	cout << "\n The following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixRowsInArray(arr, 3, 3, arrSum);
	cout << "\n\n The following are the sum of each row in the matrix : \n";
	PrintSingleArray(arrSum, 3);

	return 0;
}