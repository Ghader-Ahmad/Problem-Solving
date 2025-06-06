#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}
	return enPrimeNotPrime::Prime;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nEnter a number of elements :\n";
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

void CopyOnlyPrimeNumber(int arr1[100], int arr1Length, int arr2[100], int& arr2Length)
{
	int Counter = 0;
	for (int i = 0; i < arr1Length; i++)
	{
		if (CheckPrime(arr1[i]) == enPrimeNotPrime::Prime)
		{
			arr2[Counter] = arr1[i];
			Counter++;
		}
	}
	arr2Length = Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100], arr1Length = 0;
	FillArrayWithRandomNumber(arr1, arr1Length);

	int arr2[100], arr2Length = 0;
	CopyOnlyPrimeNumber(arr1, arr1Length, arr2, arr2Length);

	cout << "\nArray 1 Elements :\n";
	PrintArray(arr1, arr1Length);
	cout << "\nPrime Number In Array 2: \n";
	PrintArray(arr2, arr2Length);

	return 0;


}

