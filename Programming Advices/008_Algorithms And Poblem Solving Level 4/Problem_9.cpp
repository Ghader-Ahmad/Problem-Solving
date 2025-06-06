#include <iostream>

using namespace std;

short ReadYear()
{
    short Year = 0;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short arrMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrMonth[Month - 1];
}

string MonthShortName(short Month)
{
    string arrMonth[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    return arrMonth[Month];
}

short DayOfWeekOrder(short Month, short Year, short Day)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintMonthCalendar(short Year, short Month)
{
    short NumberOfDays = NumberOfDaysInMonth(Month, Year);
    short current = DayOfWeekOrder(Month, Year, 1);

    printf("\n\n  _______________%s_______________ \n\n",
        MonthShortName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");

    int i;
    for (i = 0; i < current; i++)
        printf("     ");

    for (short j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            cout << endl;
            i = 0;
        }
    }

    printf("\n  _________________________________\n");
}

void PrintYearCalendars(short Year)
{
    printf("\n  _________________________________\n\n");
    printf("             Calendar - %d\n", Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(Year, i);
    }
}

int main()
{
    short Year = ReadYear();

    PrintYearCalendars(Year);

    system("pause>0");
    return 0;
}
