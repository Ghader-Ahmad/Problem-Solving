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

short NumberOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
    return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
    return NumberOfMinutesInYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;
    system("pause>0");

    return 0;
}