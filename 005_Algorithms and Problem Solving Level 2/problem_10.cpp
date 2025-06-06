#include <string>
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

int ReverseNumber(int Number)
{
	int Number2 = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}

void PrintNumber(int Number)
{
	Number = ReverseNumber(Number);
	int Reminder = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		cout << Reminder << endl;
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a number ?");

	PrintNumber(Number);

	return 0;
}