#include <iostream>
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

bool IsPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}
	return Sum == Number;
}

void PrintPerfectNumbersFrom1ToN(int Number)
{
	cout << "\nPerfect Numbers From 1 To " << Number << " :\n";

	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ?"));

	return 0;
}