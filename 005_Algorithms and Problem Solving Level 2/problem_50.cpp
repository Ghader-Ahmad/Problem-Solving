#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "\nPlease enter a number :\n";
	cin >> Number;
	return Number;
}

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy MySqrt Result : " << MySqrt(Number) << endl;
	cout << "\nC++ sqrt Result : " << sqrt(Number) << endl;

	return 0;
}
