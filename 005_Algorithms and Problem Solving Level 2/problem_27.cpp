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
	cout << "\nEnter numbre of array : \n";
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

int SumArray(int arr[100], int arrLength)
{
	int Sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}

float ArrayAverage(int arr[100], int arrLength)
{
	return (float)SumArray(arr, arrLength) / arrLength;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nAverage of all numbers is : " << ArrayAverage(arr, arrLength) << endl;

	return 0;
}