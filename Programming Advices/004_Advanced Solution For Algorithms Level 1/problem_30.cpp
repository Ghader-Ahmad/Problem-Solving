
#include <iostream>
using namespace std;

int ReadAPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int CalculateFactorial(int N)
{
	int F = 1;
	for (int counter = 1; counter <= N; counter++)
	{
		F *= counter;
	}

	return F;
}

int main()
{
	cout << CalculateFactorial(ReadAPositiveNumber("Enter N ?")) << endl;

	return 0;
   
}


