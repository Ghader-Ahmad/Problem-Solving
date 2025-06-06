#include <iostream>

using namespace std;

long long ReadPositiveNumber(string Message)
{
	long long Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int CountDigitFrequency(long long Number, short DigitFreq)
{
	int Freq = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (Remainder == DigitFreq)
			Freq += 1;
	}
	return Freq;
}

void PrintAllDigitFrequency(long long Number)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		short DigitFreq = 0;
		DigitFreq = CountDigitFrequency(Number, i);

		if (DigitFreq > 0)
		{
			cout << "Digit " << i << " Frequency is " << DigitFreq << " Time (s).\n";
		}
	}
}

int main()
{
	long long Number = ReadPositiveNumber("Please enter a positive number ?");

	PrintAllDigitFrequency(Number);

	return 0;
}