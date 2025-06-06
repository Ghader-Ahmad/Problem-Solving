#include <iostream>

using namespace std;

short ReadYear()
{
    short Year = 0;
    cout << "Please Enter a year to check? ";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    }
    else
    {
        cout << "\nNo, Year [" << Year << "] is a Not leap year.\n";
    }

    return 0;
}
