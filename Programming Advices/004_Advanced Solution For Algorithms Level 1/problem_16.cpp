#include <cmath>
#include <iostream>
using namespace std;

void ReadsNumbers(float& A, float& D)
{
	cout << "Please enter rectangle side A?\n";
	cin >> A;

	cout << "Please enter rectangle diagonal D?\n";
	cin >> D;
}

float CalculateAreaBySideAndDiagonal(float A, float D)
{
	return A * sqrt(pow(D, 2) - pow(A, 2));
}

void PrintResult(float Area)
{
	cout << "\nCalculate Area Through Diagonal: " << Area << endl;
}

int main()
{
	float A, D;

	ReadsNumbers(A, D);
	PrintResult(CalculateAreaBySideAndDiagonal(A, D));

	return 0;
}
