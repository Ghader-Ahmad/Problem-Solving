#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number = 0;
    cout << "\nPlease neter a number ?\n";
    cin >> Number;
    return Number;
}

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

float MyRound(float Number)
{
    int IntPart = 0;
    IntPart = (int)Number;
    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) >= .5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
        return IntPart;
}

int main()
{
    float Number = ReadNumber();
    cout << "\nMy Round Result : " << MyRound(Number) << endl;
    cout << "\nC++ Round Result : " << round(Number) << endl;

    return 0;
}


