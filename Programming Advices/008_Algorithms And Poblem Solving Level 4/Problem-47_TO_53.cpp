#pragma warning (disable : 4996)

#include <iostream>

using namespace std;

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* dt = localtime(&t);

	Date.Day = dt->tm_mday;
	Date.Month = dt->tm_mon + 1;
	Date.Year = dt->tm_year + 1900;
	return Date;
}

string DayShortName(short DayOfOrder)
{
	string arrDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDay[DayOfOrder];
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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short GetDiffrenceDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	short Day = 0;
	while (IsDate1BeforDate2(Date1,Date2))
	{
		Day++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return (IncludeEndDay? ++Day:Day);
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

bool IsEndOfWeek(stDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
		
	/*
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex >= 1 && DayIndex <= 4);
	*/

	return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return  6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDiffrenceDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDiffrenceDays(Date, EndOfYearDate, true);
}

int main()
{
	stDate Date = GetSystemDate();

	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	//-------------------------
	cout << "\nIs it End of Week? \n";
	if (IsEndOfWeek(Date))
	{
		cout << "Yes end of week.\n";
	}
	else
	{
		cout << "No Not end of week.\n";
	}
	//-------------------------
	cout << "\nIs it Weekend?\n";
	if (IsWeekEnd(Date))
	{
		cout << "Yes it is a week end.\n";
	}
	else
	{
		cout << "No it is not a week end.\n";
	}
	//-------------------------
	cout << "\nIs it Business Day?\n";
	if (IsBusinessDay(Date))
	{
		cout << "Yes is a business day.\n";
	}
	else
	{
		cout << "No it is NOT a business day.\n";
	}
	//-------------------------
	cout << "\nDays until end of week  : " << 
		DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
	//-------------------------
	cout << "Days until end of month : " <<
		DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
	//-------------------------
	cout << "Days until end of year  : " <<
		DaysUntilTheEndOfYear(Date) << " Day(s).\n";

	system("pause>0");
	return 0;
}
