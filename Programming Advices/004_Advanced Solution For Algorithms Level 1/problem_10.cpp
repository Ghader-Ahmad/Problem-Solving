#include <string>
#include <iostream>
using namespace std;

void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please enter Mark 1 ?\n";
	cin >> Mark1;
	cout << "Please enter Mark 2 ?\n";
	cin >> Mark2;
	cout << "Please enter Mark 3 ?\n";
	cin >> Mark3;
}

int CalaculateSumOf3Marks(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)CalaculateSumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

void printResult(float Average)
{
	cout << "Average of 3 Marks " << Average << endl;
}



int main()
{
	int Mark1, Mark2, Mark3;

	ReadMarks(Mark1, Mark2, Mark3);

	printResult(CalculateAverage(Mark1, Mark2, Mark3));

	return 0;
}

