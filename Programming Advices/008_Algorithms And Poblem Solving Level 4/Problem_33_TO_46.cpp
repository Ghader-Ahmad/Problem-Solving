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

bool IsStartMonthInAYear(short Month)
{
    return (Month == 1);
}

bool IsStartDayInAMonth(stDate Date)
{
    return (Date.Day == 1);
}

stDate DecreaceDateByOneDay(stDate Date)
{
    if (IsStartDayInAMonth(Date))
    {
        if (IsStartMonthInAYear(Date.Month))
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaceDateByXDay(stDate Date, short NumberOfDays)
{
    for (short i = 1; i <= NumberOfDays; i++)
    {
        Date = DecreaceDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaceDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaceDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaceDateByXWeeks(stDate Date, short NumberOfWeeks)
{
    for (short i = 1; i <= NumberOfWeeks; i++)
    {
        Date = DecreaceDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaceDateByOneMonth(stDate Date)
{
    if (IsStartMonthInAYear(Date.Month))
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaceDateByXMonths(stDate Date, short NumberOfMonths)
{
    for (short i = 1; i <= NumberOfMonths; i++)
    {
        Date = DecreaceDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaceDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaceDateByXYears(stDate Date, short NumberOfYears)
{
    for (short i = 1; i <= NumberOfYears; i++)
    {
        Date = DecreaceDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaceDateByXYearsFaster(stDate Date, short NumberOfYears)
{
    Date.Year -= NumberOfYears;
    return Date;
}

stDate DecreaceDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaceDateByXDecades(stDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades; i++)
    {
        Date = DecreaceDateByOneDecade(Date);
    }
    return Date;
}

stDate DecreaceDateByXDecadesFaster(stDate Date, short NumberOfDeacdes)
{
    Date.Year -= NumberOfDeacdes * 10;
    return Date;
}

stDate DecreaceDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaceDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\n\nDate After: \n";

    Date = DecreaceDateByOneDay(Date);
    cout << "\n01-Subtracing one day is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;
          
    Date = DecreaceDateByXDay(Date, 10);
    cout << "\n02-Subtracing 10 days is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneWeek(Date);
    cout << "\n03-Subtracing One Week is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXWeeks(Date,10);
    cout << "\n04-Subtracing 10 Weeks is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneMonth(Date);
    cout << "\n05-Subtracing One Month is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXMonths(Date, 5);
    cout << "\n06-Subtracing 5 Months is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneYear(Date);
    cout << "\n07-Subtracing one Year is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXYears(Date, 10);
    cout << "\n08-Subtracing 10 Years is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXYearsFaster(Date, 10);
    cout << "\n09-Subtracing 10 Years (Faster) is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneDecade(Date);
    cout << "\n10-Subtracing one Decade is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXDecades(Date, 10);
    cout << "\n11-Subtracing 10 Decades is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByXDecadesFaster(Date, 10);
    cout << "\n12-Subtracing 10 Decades (Faster) is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneCentury(Date);
    cout << "\n13-Subtracing one Century is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaceDateByOneMillennium(Date);
    cout << "\n14-Subtracing one Millennium is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
}
