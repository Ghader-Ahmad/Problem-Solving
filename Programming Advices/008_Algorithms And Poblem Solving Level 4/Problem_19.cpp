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
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year = 0;
    cout << "Please enter a Year? ";
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

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short arrMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrMonth[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : 
        (Date1.Month == Date2.Month? Date1.Day < Date2.Day : false )) : false);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

    /*
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate; 
    */

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
}

int GetDiffrenceDays(stDate Date1, stDate Date2, bool EndAay = false)
{
    int Day = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Day++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (EndAay == true ? ++Day * SwapFlagValue : Day * SwapFlagValue);
}

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    cout << "\nDiffrence is: "
        << GetDiffrenceDays(Date1, Date2) << " Day(s).";

    cout << "\nDiffrence (Including End Day) is: "
        << GetDiffrenceDays(Date1, Date2, true) << " Day(s).\n";

    system("pause>0");
    return 0;
}
