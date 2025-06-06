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

stPeriod RaedPeriod()
{
    stPeriod Period;
    cout << "Enter Start Date: \n";
    Period.StartDate = ReadFullDate();

    cout << "\n\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
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
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : 
        (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDateEqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) :false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDateEqualDate2(Date1, Date2));
}

enCompareDate CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;
    
    if (IsDateEqualDate2(Date1, Date2))
        return enCompareDate::Equal;
    
    return enCompareDate::After;
}

bool OverLapPeriods(stPeriod Period1, stPeriod Period2)
{
    if ((CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDate::Before) ||
        (CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDate::After))
        return false;
    
    return true;
}

int main()
{
    cout << "\nEnter Period 1:\n";
    stPeriod Period1 = RaedPeriod();

    cout << "\nEnter Period 2:\n";
    stPeriod Period2 = RaedPeriod();

    if (OverLapPeriods(Period1, Period2))
    {
        cout << "\n\nYes, Periods Overlap.";
    }
    else
    {
        cout << "\n\nNo, Periods Not Overlap.";
    }

    system("pause>0");
    return 0;
}
