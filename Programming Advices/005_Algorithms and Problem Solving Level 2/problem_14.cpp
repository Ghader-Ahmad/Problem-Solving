
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

void PrintInvertedLetter(int Number)
{
	cout << endl;

	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetter(ReadPositiveNumber("Please enter a positive number ?"));

	return 0;
}
