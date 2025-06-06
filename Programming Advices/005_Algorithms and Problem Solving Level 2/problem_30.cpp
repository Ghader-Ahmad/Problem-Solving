#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
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

void SumOf2Array(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrSum[i] = arr1[i] + arr2[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], arrSum[100], arrLength = 0;

	arrLength = ReadPositiveNumber("How many elements ?");

	FillArrayWithRandomNumber(arr1, arrLength);
	FillArrayWithRandomNumber(arr2, arrLength);

	SumOf2Array(arr1, arr2, arrSum, arrLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr1, arrLength);

	cout << "\nArray 2 elements :\n";
	PrintArray(arr2, arrLength);

	cout << "\nSum of array 1 and array 2 elements: \n";
	PrintArray(arrSum, arrLength);

	return 0;
}
