#include <iostream>
#include <iomanip>
using namespace std;

int ReadNumber(string Message)
{
	int Number = 0;
	cout << Message;

	cin >> Number;
	return Number;
}

short CounterNumberInMatrix(int arr[3][3], int Number,  short Rows, short Cols)
{
	short Count = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
			{
				Count++;
			}
		}
	}
	return Count;
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
	int Matrix1[3][3] = { {1,9,9},{8,7,9},{5,9,9} };

	cout << "\nMatrix1 : \n\n";
	PrintMatrix(Matrix1, 3, 3);

	int Num = ReadNumber("\n\nEnter the number to count in matrix ? ");

	cout << "\n\nNumber " << Num << " count in matrix is " << CounterNumberInMatrix(Matrix1, Num, 3, 3) << endl;

	return 0;
}