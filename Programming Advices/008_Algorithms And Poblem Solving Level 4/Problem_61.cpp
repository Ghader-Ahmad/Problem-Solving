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

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "Enter Start Date: \n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date: \n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    short arrMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrMonth[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false;
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

bool OverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDate(Period2.EndDate, Period1.StartDate) == enCompareDate::Before ||
        CompareDate(Period2.StartDate, Period1.EndDate) == enCompareDate::After)
        return false;

    return true;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate tempDate = Date1;
    Date1 = Date2;
    Date2 = tempDate;
}

short GetDifferenceDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short Day = 0;
    short SwapFlagValue = 1;

    if (!(CompareDate(Date1, Date2) == enCompareDate::Before))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (CompareDate(Date1,Date2) == enCompareDate::Before)
    {
        Day++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return (IncludeEndDay) ? ++Day * SwapFlagValue : Day * SwapFlagValue;
}

short CalculatePeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
    return (CompareDate(Date, Period.StartDate) == enCompareDate::After &&
        CompareDate(Date, Period.EndDate) == enCompareDate::Before);
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = CalculatePeriodLengthInDays(Period1, true);
    int Period2Length = CalculatePeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!OverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (CompareDate(Period1.StartDate, Period1.EndDate) == enCompareDate::Before)
        {
            if (IsDateInPeriod(Period2, Period1.StartDate))
                OverlapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }

    else
    {
        while (CompareDate(Period2.StartDate, Period2.EndDate) == enCompareDate::Before)
        {
            if (IsDateInPeriod(Period1, Period2.StartDate))
                OverlapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

int main()
{
    cout << "\nEnter Period1:\n";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period2:\n";
    stPeriod Period2 = ReadPeriod();

    cout << "\n\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;

    system("pause>0");
    return 0;
}