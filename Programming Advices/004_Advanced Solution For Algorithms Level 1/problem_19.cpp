
#include <iostream>
using namespace std;

float ReadDiameter()
{
    float D;

    cout << "Please enter a Diameter?\n";
    cin >> D;

    return D;
}

float CircleAreaByDiameter(float D)
{
    float pi = 3.141592653589793238;

    return (pi * pow(D, 2)) / 4;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    PrintResult(CircleAreaByDiameter(ReadDiameter()));

    return 0;
}

