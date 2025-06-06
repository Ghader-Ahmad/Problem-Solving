#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "       ";
		}
		cout << "\n";
	}
}

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
}

void PrintInserctedNumbresInTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsNumberInMatrix(Matrix2, Matrix1[i][j], 3, 3))
			{
				cout << setw(3) << Matrix1[i][j] << "           ";
			}
		}
	}
}

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "\nMatrix1 :\n ";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\n\nMatrix2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\n\nInsercted Numbers are : \n\n";
	PrintInserctedNumbresInTwoMatrices(Matrix1, Matrix2, 3, 3);
	cout << "\n\n";
	return 0;
}