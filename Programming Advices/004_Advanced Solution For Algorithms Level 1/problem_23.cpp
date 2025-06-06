
#include <iostream>
using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
    cout << "Please enter trignal side A?\n";
    cin >> A;

    cout << "Please enter trignal base B?\n";
    cin >> B;

    cout << "Please enter trignal side C?\n";
    cin >> C;
}

float CircleAreaATrignal(float A, float B, float C)
{
    const float pi = 3.141592653589793238;
    float P = (A + B + C) / 2;
    float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

    float Area = pi * pow(T, 2);

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    float A, B, C;

    ReadTriangleData(A, B, C);
    PrintResult(CircleAreaATrignal(A, B, C));

    return 0;
}
