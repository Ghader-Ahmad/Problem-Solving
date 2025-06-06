#include <iostream>

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

short ReadVacationDays()
{
    short Day = 0;
    cout << "\n\nPlease enter vacation days? ";
    cin >> Day;
    return Day;
}

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

bool IsLastDayInAMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInAYear(short Month)
{
    return (Month == 12);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOrder)
{
    string arrDay[] = { "Sun", "Mon","Tue","Wed","Thu", "Fri","Sat" };
    return arrDay[DayOrder];
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekEnd(Date));
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInAMonth(Date))
    {
        if (IsLastMonthInAYear(Date.Month))
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

stDate CalculateVacationDaysReturnDate(stDate DateFrom, short VacationDay)
{
    short WeekEndDays = 0;

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    for (short i = 1; i <= VacationDay + WeekEndDays; i++)
    {
        if (IsWeekEnd(DateFrom))
            WeekEndDays++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DateFrom;
}

int main()
{
    stDate DateFrom;
    cout << "\nVacation Starts:";
    DateFrom = ReadFullDate();

    short VacationDays = ReadVacationDays();

    DateFrom = CalculateVacationDaysReturnDate(DateFrom, VacationDays);
    cout << "\n\nReturn Date : " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "
        << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;
         

    system("pause>0");
    return 0;
}