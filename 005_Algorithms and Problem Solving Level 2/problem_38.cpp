#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nPlease enter a number of array ?\n";
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

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrLDestination)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arrSource[i] % 2 != 0)
			AddArrayElements(arrSource[i], arrDestination, arrLDestination);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100], arrLength = 0;
	FillArrayWithRandomNumber(arr1, arrLength);

	int arr2[100], arr2Length = 0;
	CopyOddNumbers(arr1, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr1, arrLength);

	cout << "\nArray 2 Odd numbers :\n";
	PrintArray(arr2, arr2Length);

	return 0;
   
}

