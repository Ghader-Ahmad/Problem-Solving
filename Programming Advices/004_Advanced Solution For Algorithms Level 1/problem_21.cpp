

#include <iostream>
using namespace std;

float ReadCirumference()
{
    float L;
    cout << "Please enter a Cirumference L?\n";
    cin >> L;

    return L;
}

float CiecleAreaByCirumference(float L)
{
    float pi = 3.141592653589793238;

    return pow(L, 2) / (4 * pi);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    PrintResult(CiecleAreaByCirumference(ReadCirumference()));

    return 0;
}

