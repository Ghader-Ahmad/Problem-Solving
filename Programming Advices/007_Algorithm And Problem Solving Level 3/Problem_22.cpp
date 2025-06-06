#include <iostream>
using namespace std;

void PrintFibonacciNumbersWithRecurision(short Number, int Prev1, int Prev2)
{
	int FiboNumber = 0;
	if (Number > 0)
	{
		FiboNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FiboNumber;
		cout << FiboNumber << "      ";
		PrintFibonacciNumbersWithRecurision(Number - 1, Prev1, Prev2);
	}
}

int main()
{
	PrintFibonacciNumbersWithRecurision(10, 0, 1);

	return 0;
}