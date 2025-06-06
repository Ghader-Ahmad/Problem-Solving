#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumbers(int From, int To)
{
	int Rand = rand() % (To - From + 1) + From;
	return Rand;
}

void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols)
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
	cout << "\n The following is a 3x3 random matrix : \n";

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		} 
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);

	return 0;
}