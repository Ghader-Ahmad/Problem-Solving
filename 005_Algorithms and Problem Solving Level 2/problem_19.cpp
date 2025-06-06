#include <cstdlib>
#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = 0; 
	RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;

	return 0;
}