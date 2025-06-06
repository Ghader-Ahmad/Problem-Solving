#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumbers(int From, int To)
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
			arr[i][j] = RandomNumbers(1, 100);
		}
	}
}

int ColSum(int arr[3][3], short ColsNumbers, short Rows)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColsNumbers];
	}
	return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
	for (int j = 0; j < Cols; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << ColSum(arr, j, Rows) << endl;
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

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillArrayWithRandomNumber(arr, 3, 3);
	cout << "\n The following is a 3x3 random matrix : \n";
	PrintMatrix(arr,3,3);

	cout << "\n The the following are the sum of each col in the matrix :\n";
	PrintEachColSum(arr, 3, 3);

	return 0;
}