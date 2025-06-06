
#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Please enter Age between 18 and 45?\n";
	cin >> Age;

	return Age;
}

bool ValidateNumberAge(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

int ReadUntilAgeBetween(int From, int To)
{
	int Age = 0;
	do
	{
		Age = ReadAge();
	} while (!ValidateNumberAge(Age, From, To));

	return Age;
}

void PrintResult(int Age)
{
	cout << " your age is : " << Age << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));

	return 0;
}

