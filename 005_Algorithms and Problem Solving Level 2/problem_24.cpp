#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void ReadArray(int arr[100], int& arrLength)
{
	cout << "\nEnter numbers of elements :\n";
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

int MaxNumberInArray(int arr[100], int arrLength)
{
	int max = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;

	ReadArray(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nMax Numbers is : " << MaxNumberInArray(arr, arrLength) << "\n";

	return 0;
}