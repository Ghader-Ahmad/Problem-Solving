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

void PrintReverseNumber(int Number)
{
	int Remainder = 0;

	cout << "\nReverse Number:\n";

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		cout << Remainder << endl;
	}
}

int main()
{
	PrintReverseNumber(ReadPositiveNumber("Please enter a positive number?"));

	return 0;
}