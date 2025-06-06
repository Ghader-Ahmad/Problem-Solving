#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

string DayShortName(short DayOrder)
{
	string arrDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDay[DayOrder];
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			DaysCount++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return DaysCount;
}

int main()
{
	cout << "\nVacation Start:";
	stDate DateFrom = ReadFullDate();
	
	cout << "\nVacation End:";
	stDate DateTo = ReadFullDate();

	
	cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) <<
		" , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

	cout << "\nVacation To: " << DayShortName(DayOfWeekOrder(DateTo)) <<
		" , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

	cout << "\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo) << endl;

	system("pause>0");
	return 0;
}