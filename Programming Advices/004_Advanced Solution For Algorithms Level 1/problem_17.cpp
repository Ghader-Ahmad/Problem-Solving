
#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& H)
{
    cout << "Please enter base A?\n";
    cin >> A;

    cout << "Please enter height H?\n";
    cin >> H;
}

float CalculateTriangleArea(float A, float H)
{
    return (A / 2) * H;
}

void PrintResult(float Area)
{
    cout << "Triangle Area: " << Area << endl;
}

int main()
{
    float A, H;

    ReadNumbers(A, H);
    PrintResult(CalculateTriangleArea(A, H));

    return 0;
}
