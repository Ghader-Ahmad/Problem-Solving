#include <iostream>

using namespace std;

enum enCompareDate { Before = -1, Equal = 0, After = 1 };

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : 
        (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false));
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enCompareDate CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equal;

    /*if (IsDate1AfterDate2(Date1, Date2))
        return enCompareDate::After;*/
    
        // Faster
    return enCompareDate::After;
}



int main()
{
    cout << "\nEnter Date1: ";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter Date2: ";
    stDate Date2 = ReadFullDate();

    cout << "\n\nCompare Result = " << CompareDates(Date1, Date2);

    system("pause>0");
    return 0;
}
