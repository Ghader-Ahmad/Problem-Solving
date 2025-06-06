
#include <iostream>
using namespace std;

float ReadSquareSide()
{
	float A;
	cout << "Please enter Square Side?\n";
	cin >> A;

	return A;
}

float CircleAreaInscribedInASquare(float A)
{
	float pi = 3.141592653589793238;

	return (pi * pow(A, 2)) / 4;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaInscribedInASquare(ReadSquareSide()));

	return 0;
}


