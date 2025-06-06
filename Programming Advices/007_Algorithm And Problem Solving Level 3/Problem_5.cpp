#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short j = 0; j < Cols; j++)
	{
		arrSum[j] = ColSum(arr, Rows, j);
	}
}

void PrintColSumArray(int arr[3], short Length)
{
	cout << "\n The following are the sum of each col in the matrix : \n";
	for (int i = 0; i < Length; i++)
	{
		cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillArrayWithRandomNumber(arr, 3, 3);
	cout << " The following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColsInArray(arr, arrSum, 3, 3);

	PrintColSumArray(arrSum, 3);

	return 0;
}