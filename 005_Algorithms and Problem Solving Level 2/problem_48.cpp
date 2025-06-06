#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "\nPlease enter a number :\n";
	cin >> Number;
	return Number;
}

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

float MyFloor(float Number)
{
	float FractionPart = GetFractionPart(Number);

	if (abs(GetFractionPart(Number)) > 0)
	{
		if (Number > 0)
			return (int)Number;
		else
			return (int)Number - 1;
	}
	else
		return Number;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy MyFloor Result : " << MyFloor(Number) << endl;
	cout << "\nC++ floor Result : " << floor(Number) << endl;

	return 0;
 
}
