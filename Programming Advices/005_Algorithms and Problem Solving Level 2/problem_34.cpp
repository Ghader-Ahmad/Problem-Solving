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

void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	cout << endl;
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

short FindNumberPositionInArray(int arr[100], int arrLength, short Number)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;

	arrLength = ReadPositiveNumber("How many number of elements ?");

	FillArrayWithRandomNumber(arr, arrLength);
	cout << "\nArray 1 elements :";
	PrintArray(arr, arrLength);

	int Number = 0;
	Number = ReadPositiveNumber("\nPlease enter a number to search for ?");

	cout << "\nNumber you are looking is : " << Number << endl;

	short NumberPosition = FindNumberPositionInArray(arr, arrLength, Number);

	if (NumberPosition == -1)
	{
		cout << "The Number is not found : -(" << endl;
	}
	else
	{
		cout << "The Number found at position : " << NumberPosition << endl;
		cout << "The Number found its order : " << NumberPosition + 1 << endl;
	}

	return 0;
   
}
