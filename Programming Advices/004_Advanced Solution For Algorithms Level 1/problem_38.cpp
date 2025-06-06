#include <string>
#include <iostream>
using namespace std;
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

enPrimeNotPrime CheckPrimeNotPrime(int Number)
{
	int M = round(Number / 2);

	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}
	return enPrimeNotPrime::Prime;
}

void PrintNumberType(int Number)
{
	
	switch (CheckPrimeNotPrime(Number))
	{
	case enPrimeNotPrime::Prime:
		cout << "\nThe number is a prime\n";
		break;

	case enPrimeNotPrime::NotPrime:
		cout << "\nThe number is not prime\n";
		break;
	}
}

int main()
{
	PrintNumberType(ReadPositiveNumber("Please enter a positive number ?\n"));

	return 0;
}
