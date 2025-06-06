#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number)
{
	int M = Number / 2;

	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumberFrom1ToN(int Number)
{
	cout << "\nPrime Number from 1 to " << Number << " are :" << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPrimeNumberFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

	return 0;
}
