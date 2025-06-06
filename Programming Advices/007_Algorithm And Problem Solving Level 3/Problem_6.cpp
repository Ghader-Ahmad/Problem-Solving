#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void FillArrayWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short ContNumber = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			ContNumber++;
			arr[i][j] = ContNumber;
		}
	}
}

void PrintMatrixArray(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "      ";
		}
		cout << "\n";
	}
}

int main()
{
	int arr[3][3];
	FillArrayWithOrderedNumbers(arr, 3, 3);

	cout << " The following is a 3x3 ordered matrix : \n";
	PrintMatrixArray(arr, 3, 3);

	return 0;
}
