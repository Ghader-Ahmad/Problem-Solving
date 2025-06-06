#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumbers(int From, int To)
{
	int Rand = rand() % (To - From + 1) + From;
	return Rand;
}

void FillArrayWithRandomNumebrs(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumbers(1, 100);
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

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (int j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void SumOfEachRowInTheMatrix(int arr[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillArrayWithRandomNumebrs(arr, 3, 3);
	cout << "\n The following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	cout << "\n\n The following are the sum of each row in the matrix : \n";
	SumOfEachRowInTheMatrix(arr, 3, 3);

	return 0;
}
