#include<iostream>
using namespace std;

int ReadNumber()
{
	int Number = 0;
	cout << "\nPlease enter a number ? ";
	cin >> Number;
	return Number;
}

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;
	do
	{
		AddArrayElements(ReadNumber(), arr, arrLength);
		cout << "\nDo you want to add more numbers? [0]:No , [1]:Yes ? ";
		cin >> AddMore;
	} while (AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);

	cout << "\nArray Length : " << arrLength << endl;
	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	return 0;
}