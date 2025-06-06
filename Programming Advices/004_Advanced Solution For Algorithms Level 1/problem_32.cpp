
#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a number?\n";
	cin >> Number;

	return Number;
}

int ReadPower()
{
	int M;

	cout << "Please enter a power?\n";
	cin >> M;

	return M;
}

int PowerOfM(int Number, int M)
{
	int P = 1;

	if (M == 0)
		return P;
	else
	{
		for (int counter = 1; counter <= M; counter++)
		{
			P *= Number;
		}
		return P;
	}
}

int main()
{
	cout << "Result = " << PowerOfM(ReadNumber(), ReadPower());

	return 0;
}