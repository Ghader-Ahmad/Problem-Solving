
#include <string>
#include <iostream>
using namespace std;

void ReadLengths(float& a, float& b)
{
    cout << "Please enter rectangle width A?\n";
    cin >> a;

    cout << "Please enter rectangle  length B?\n";
    cin >> b;
}

float CalculatRrectangleArea(float a, float b)
{
    return a * b;
}

void PrintResult(float Area)
{
    cout << "\nRrectangle Area : " << Area << endl;
}

int main()
{
    float a, b;

    ReadLengths(a, b);
    PrintResult(CalculatRrectangleArea(a, b));

    return 0;
}

