#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number to search for ?\n";
	cin >> Number;
	return Number;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements ?\n";
	cin >> arrLength;
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

int FindNumberPositionInArray(int arr[100], int arrLength, int Number)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int arr[100], int arrLength, int Number)
{
	return FindNumberPositionInArray(arr, arrLength, Number) != -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrLength);

	int Number = ReadNumber();
	cout << "\nNumber you are looking for is : " << Number << endl;

	if (!IsNumberInArray(arr, arrLength, Number))
		cout << "No, The number is not found :-(" << endl;
	else
		cout << "Yes, The number is found :-)" << endl;

	return 0;
		
}
