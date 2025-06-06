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

stDate IncreaceDateByOneDay(stDate Date)
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

stDate IncreaceDateByXDay(stDate Date, short NumberOfDays)
{
    for (short i = 1; i <= NumberOfDays; i++)
    {
        Date = IncreaceDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaceDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaceDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaceDateByXWeek(stDate Date, short NumberOfWeeks)
{
    for (short i = 1; i <= NumberOfWeeks; i++)
    {
        Date = IncreaceDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaceDateByOneMonth(stDate Date)
{
    if (IsLastMonthInYear(Date.Month))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaceDateByXMonth(stDate Date, short NumberOfMonths)
{
    for (short i = 1; i <= NumberOfMonths; i++)
    {
        Date = IncreaceDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaceDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaceDateByXYear(stDate Date, short NumberOfYears)
{
    for (short i = 1; i <= NumberOfYears; i++)
        Date = IncreaceDateByOneYear(Date);

    return Date;
}

stDate IncreaceDateByXYearsFaster(stDate Date, short NumberOfYears)
{
    Date.Year += NumberOfYears;
    return Date;
}

stDate IncreaceDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return Date;
}

stDate IncreaceDateByXDecades(stDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades; i++)
    {
        Date = IncreaceDateByOneDecade(Date);
    }
    return Date;
}

stDate IncreaceDateByXDecadesFaster(stDate Date, short NumberOfDeacdes)
{
    Date.Year += NumberOfDeacdes * 10;
    return Date;
}

stDate IncreaceDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaceDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    cout << "\n\nDate After: \n";

    Date = IncreaceDateByOneDay(Date);
    cout << "\n 01-Adding one day is             : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXDay(Date, 10);
    cout << "\n 02-Adding 10 days is             : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneWeek(Date);
    cout << "\n 03-Adding one week is            : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXWeek(Date, 10);
    cout << "\n 04-Adding 10 weeks is            : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneMonth(Date);
    cout << "\n 05-Adding one month is           : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXMonth(Date, 5);
    cout << "\n 06-Adding 5 months is            : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneYear(Date);
    cout << "\n 07-Adding one Year is            : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXYear(Date, 10);
    cout << "\n 08-Adding 10 Years is            : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXYearsFaster(Date, 10);
    cout << "\n 09-Adding 10 Years (Faster) is   : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneDecade(Date);
    cout << "\n 10-Adding one Decade is          : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXDecades(Date, 10);
    cout << "\n 11-Adding 10 Decades is          : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByXDecadesFaster(Date, 10);
    cout << "\n 12-Adding 10 Decades (Faster) is : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneCentury(Date);
    cout << "\n 13-Adding one Century is         : " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaceDateByOneMillennium(Date);
    cout << "\n 14-Adding one Millennium is      : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year;
     

    system("pause>0");
    return 0;
}