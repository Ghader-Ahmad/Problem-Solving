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
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}

short ReadDaysToAdd()
{
	short Days = 0;
	cout << "\nHow many Days to add? ";
	cin >> Days;
	return Days;
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

short NumberOfDaysFromTheBeginingOfYear(short Year, short Month, short Day)
{
	short TotalDay = 0;
	for (short i = 1; i < Month; i++)
	{
		TotalDay += NumberOfDaysInAMonth(Year, i);
	}

	return TotalDay + Day;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

stDate DateAddDays(stDate Date, short Days)
{

	Days = Days + NumberOfDaysFromTheBeginingOfYear(Date.Year, Date.Month, Date.Day);

	short RemindarDay = Days;
	short MonthDays = 0;

	Date.Year;
	Date.Month = 1;

	while (true)
	{
		if (Date.Month > 12)
		{
			Date.Year++;
			Date.Month = 1;
		}

		MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (RemindarDay > MonthDays)
		{
			RemindarDay -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemindarDay;
			break;
		}
	}
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Date, Days);

	cout << "\nDate after adding [" << Days << "] days is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	system("pause>0");

	return 0;
}