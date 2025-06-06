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

int SumOfDigigts(int Number)
{
	int Sum =0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Sum += Remainder;
	}
	return Sum;
}

int main()
{
	cout << "\nSum Of Digits = "
		<< SumOfDigigts(ReadPositiveNumber("Please enter a positive number?"))
		<< "\n";

	return 0;
}