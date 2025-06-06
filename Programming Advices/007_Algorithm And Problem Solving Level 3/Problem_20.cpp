#include <iostream>
#include <iomanip>
using namespace std;

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
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
	int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	//int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,8} };
	 
	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeMatrix(Matrix1, 3, 3))
	{
		cout << "\n\nYES : Matrix is Palindrome.\n";
	}
	else
	{
		cout << "\n\nNO : Matrix is NOT Palindrome.\n";
	}

	return 0;
}