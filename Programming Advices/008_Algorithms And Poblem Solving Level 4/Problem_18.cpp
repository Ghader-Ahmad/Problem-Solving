#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year) ?(Date1.Month < Date2.Month ? true : 
		(Date1.Month == Date2.Month ?(Date1.Day< Date2.Day):false )) : false);
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

int GetDiffrenceDays(stDate Date1, stDate Date2)
{
	int Day = 0;
	while (IsDate1BeforeDate2(Date1,Date2))
	{
		Day++;
		Date1 = IncreaceDateByOneDay(Date1);
	}
	return Day;
}

int main()
{
	cout << "\nPlease Enter Your Date of Birth: \n";
	stDate Date1 = ReadFullDate();
	stDate Date2 = GetSystemDate();

	cout << "\n\nYour Age is : " <<
		GetDiffrenceDays(Date1, Date2) << " Day(s).\n";
	system("pause>0");

	return 0;
}