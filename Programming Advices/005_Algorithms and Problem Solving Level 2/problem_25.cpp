#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = 0;
	RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements array :\n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int MinNumberOfArray(int arr[100], int arrLength)
{
	int MinNumber = 0;
	MinNumber = arr[0];
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < MinNumber)
		{
			MinNumber = arr[i];
		}
	}

	return MinNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nMin Number is : " << MinNumberOfArray(arr, arrLength) << endl;

	return 0;
}