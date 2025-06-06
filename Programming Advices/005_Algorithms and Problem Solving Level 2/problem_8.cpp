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

int CountDigigtFrequency(int Number, short DigitToCheck)
{
	int FreqCount = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (Remainder == DigitToCheck)
			FreqCount += 1;
	}
	return FreqCount;
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number ?");
	short DigitToCheck = ReadPositiveNumber("Please enter a one of digit ?");

	cout << "\nDigit " << DigitToCheck << " Frequency is "
		<< CountDigigtFrequency(Number, DigitToCheck) << " Time(s).\n";

	return 0;
}