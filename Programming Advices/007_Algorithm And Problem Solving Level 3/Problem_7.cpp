#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void FillArrayWithOrdaredNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
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

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

int main()
{
	int arr[3][3], arrTrasposed[3][3];

	FillArrayWithOrdaredNumbers(arr, 3, 3);
	cout << "\nThe following is a 3x3 ordeared matrix : \n";
	PrintMatrixArray(arr, 3, 3);

	TransposeMatrix(arr, arrTrasposed, 3, 3);
	cout << "\n\nThe following is the transposed matrix :\n";
	PrintMatrixArray(arrTrasposed, 3, 3);

	return 0;
}