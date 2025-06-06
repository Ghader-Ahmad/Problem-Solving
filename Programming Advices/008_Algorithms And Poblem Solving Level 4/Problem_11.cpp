#include <iostream>
#include <string>

using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
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

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short arrMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrMonth[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Month, short Year, short Day)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	return TotalDays + Day;
}

stDate GetDateFromDayOrderInYear(short Year, short DaysOrderInYear)
{
	stDate Date;
	short ReminderDays = DaysOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Year);

		if (ReminderDays > MonthDays)
		{
			ReminderDays -= MonthDays;
			Date.Month++;
		}

		else
		{
			Date.Day = ReminderDays;
			break;
		}
	}
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Date.Month, Date.Year, Date.Day);

	cout << "\nNumber of days from the begining of the year is " << DaysOrderInYear << endl;

	Date = GetDateFromDayOrderInYear(Date.Year, DaysOrderInYear);

	cout << "\nDate for [" << DaysOrderInYear << "] is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	return 0;
}