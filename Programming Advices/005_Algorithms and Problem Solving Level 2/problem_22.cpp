#include<iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void ReadArray(int arr[100], int& arrLength)
{
	cout << "\nEnter a number of elements :\n";
	cin >> arrLength;

	cout << "\nEnter array elements :\n";
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Elements [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int TimesRepeated(int arr[100], int arrLength, int NumberToCheck)
{
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == NumberToCheck)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Please enter the number you want to check ? ");

	cout << "\nOriginal array : ";
	PrintArray(arr, arrLength);
	cout << NumberToCheck << " is repeated " << TimesRepeated(arr, arrLength, NumberToCheck) << " time (s)\n";
	return 0;

}