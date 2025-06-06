#include <iostream>
#include<iomanip>
using namespace std;

bool AreMatrixIsIdentity(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1)
			{
				return false;
			}
			else if (i != j && arr[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "            ";
		}
		cout << "\n";
	}
}

int main()
{
	//int Matrix1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int Matrix1[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	cout << "\nMatrix1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	if (AreMatrixIsIdentity(Matrix1, 3, 3))
	{
		cout << "\nYES : Matrix is identity.\n";
	}
	else
	{
		cout << "\nNO : Matrix is NOT identity.\n";
	}

	return 0;
}