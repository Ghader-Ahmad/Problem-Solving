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

void Swap(int& A, int& B)
{
	int Temp = 0;
	Temp = A;
	A = B;
	B = Temp;
}

void FillArrayFrom1ToN(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = i + 1;
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

void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;

	arrLength = ReadPositiveNumber("How many Elements ?");

	FillArrayFrom1ToN(arr, arrLength);

	cout << "\nArray elements before shuffle :\n";
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);

	cout << "\nArray elements after shuffle :\n";
	PrintArray(arr, arrLength);

	return 0;

}
