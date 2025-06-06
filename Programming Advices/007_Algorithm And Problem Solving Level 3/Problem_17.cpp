#include <iostream>
#include <iomanip>
using namespace std;

short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message;
	cin >> Number;

	return Number;
}

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

bool SearchNumberInMatrix(int Matrix[3][3], int Number,  short Rows, short Cols)
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

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "        ";
		}
		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumber(Matrix, 3, 3);
	cout << "Matrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	short Num = ReadNumber("\n\nPlease Enter the number to look for in matrix ? ");

	if (SearchNumberInMatrix(Matrix, Num, 3, 3))
	{
		cout << "\n\nYES it is there.\n";
	}
	else
	{
		cout << "\n\nNo it is not there.\n";
	}

	return 0;
}