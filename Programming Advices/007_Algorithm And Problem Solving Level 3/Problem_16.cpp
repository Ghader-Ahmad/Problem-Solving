#include <iostream>
#include <iomanip>
using namespace std;

short CounterOfZeroNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
	short Count = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				Count++;
			}
		}
	}
	return Count;
}

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;
	return (CounterOfZeroNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));
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
	//int Matrix1[3][3] = { {10,0,12},{20,15,1},{0,0,9} };
	int Matrix1[3][3] = { {0,1,12},{0,1,1},{0,0,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparceMatrix(Matrix1, 3, 3))
	{
		cout << "\n\nYES : It is sparce.\n";
	}
	else
	{
		cout << "\n\nNO : It's not sparce.\n";
	}

	return 0;
}