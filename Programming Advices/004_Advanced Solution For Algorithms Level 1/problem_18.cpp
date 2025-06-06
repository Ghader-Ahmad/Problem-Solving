
#include <iostream>
using namespace std;

float ReadRadious()
{
    float R;
    cout << "Please enter Radious ?\n";
    cin >> R;

    return R;
}

float CalculateCircleArea(float R)
{
    const float pi = 3.141592653589793238;
    return pi * pow(R, 2);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleArea(ReadRadious()));

    return 0;
}
