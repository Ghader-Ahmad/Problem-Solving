#include <iostream>

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

short ReadDay()
{
    short Day = 0;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month = 0;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year = 0;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
        (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 is less than Date2.\n";
    }
    else
    {
        cout << "\nNo, Date1 is NOT less than Date2.\n";
    }

    system("Pause>0");

    return 0;
}

