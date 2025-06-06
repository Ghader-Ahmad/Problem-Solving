#include <iostream>

using namespace std;

enum enCompareDate { Before = -1, Equal = 0, After = 1 };

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeroid()
{
    stPeriod Period;
    cout << "Enter Start Date:\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n";
    Period.EndDate = ReadFullDate();
    return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true:
        (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enCompareDate CompareDate(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equal;

    else
        return enCompareDate::After;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
    // If Date out Period
    /*return !(CompareDate(Date, Period.StartDate) == enCompareDate::Before ||
        CompareDate(Date, Period.EndDate) == enCompareDate::After);
        */

    // If Date within Peroid 
    return (CompareDate(Date, Period.StartDate) == enCompareDate::After &&
        CompareDate(Date, Period.EndDate) == enCompareDate::Before);
}

int main()
{
    cout << "\nEnter Period :\n";
    stPeriod Period = ReadPeroid();

    cout << "\nEnter Date to check:\n";
    stDate Date = ReadFullDate();

    if (IsDateInPeriod(Date, Period))
    {
        cout << "\nYes, Date is within period.";
    }
    else
    {
        cout << "\nNo, Date is Not within period.";
    }

    system("Pause>0");
    return 0;
}