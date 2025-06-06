#include <cmath>
#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number = 0;
    cout << "\nPlease enter a number : \n";
    cin >> Number;
    return Number;
}

float Myabs(float Number)
{
    if (Number < 0)
        return Number * -1;
    else
        return Number;
}

int main()
{
    float Number = 0;
    Number = ReadNumber();

    cout << "\nMy abs Result : " << Myabs(Number) << endl;

    cout << "\nC++ abs Result : " << abs(Number) << endl;

    return 0;

    
}

