#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number = 0;
    cout << "\nPlease enter a Number :\n";
    cin >> Number;
    return Number;
}

float GetFractionPart(float Number)
{
    return Number - (int)Number;
}

float MyCeil(float Number)
{
    float FractionPart = GetFractionPart(Number);

    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return (int)Number + 1;
        else
            return (int)Number;
    }
    else
        return Number;
        
}

int main()
{
    float Number = ReadNumber();

    cout << "\nMy MyCeil Result : " << MyCeil(Number) << endl;
    cout << "\nC++ Ceil Result : " << ceil(Number) << endl;

    return 0;
}

