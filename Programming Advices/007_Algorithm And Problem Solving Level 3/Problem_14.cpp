#include <iostream>
#include <iomanip>
using namespace std;

bool AreScalarMatrices(int Matrix[3][3], short Rows, short Cols)
{
	int FirstDiagElement = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != FirstDiagElement)
			{
				return false;
			}

			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "         ";
		}
		cout << "\n";
	}
}

int main()
{
	int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	//int Matrix1[3][3] = { {10,0,0},{0,10,0},{0,0,10} };
	//int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,11} };
	
	cout << "Matrix1: \n";
	PrintMatrix(Matrix1, 3, 3);

	if (AreScalarMatrices(Matrix1, 3, 3))
	{
		cout << "\n\nYES : Matrix is scalar.\n";
	}
	else
	{
		cout << "\n\nNO : Matrix is NOT scalar.\n";
	}

	return 0;
}