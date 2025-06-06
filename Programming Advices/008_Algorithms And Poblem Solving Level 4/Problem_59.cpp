#include <iostream>

using namespace std;

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
    stPeriod Peroid;
    
    cout << "Enter Strat Date:\n";
    Peroid.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Peroid.EndDate = ReadFullDate();
    return Peroid;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : 
        (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate tempDate;
    tempDate = Date1;
    Date1 = Date2;
    Date2 = Date1;
}

short GetDifferanceDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short Day = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1,Date2))
    {
        Day++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return (IncludeEndDay ? ++Day * SwapFlagValue : Day * SwapFlagValue);
}

short CalculatePeroidLengthInDays(stPeriod Peroid, bool IncludeEndDay = false)
{
    return GetDifferanceDays(Peroid.StartDate, Peroid.EndDate, IncludeEndDay);
}

int main()
{
    cout << "\nEnter Peroid1: \n";
    stPeriod Peroid = ReadPeriod();


    cout << "\n\nPeroid Length is: " << CalculatePeroidLengthInDays(Peroid);
    cout << "\nPeroid Length (Including End Date) is: " << CalculatePeroidLengthInDays(Peroid, true);

    system("pause>0");
    return 0;
}
