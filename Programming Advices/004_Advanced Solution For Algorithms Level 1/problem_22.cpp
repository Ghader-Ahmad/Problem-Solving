#include <string>
#include <iostream> 
#include <cmath>
using namespace std;

void ReadTriangleData(float& A, float& B)
{
    cout << "Please enter triangle side A?\n";
    cin >> A;

    cout << "Please enter triangle base B?\n";
    cin >> B;
}

float CircleAreaByTriangle(float A, float B)
{
    const float pi = 3.141592653589793238;

    float Area = (pi * pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}


int main()
{
    float A, B;

    ReadTriangleData(A, B);
    PrintResult(CircleAreaByTriangle(A, B));

    return 0;
}


