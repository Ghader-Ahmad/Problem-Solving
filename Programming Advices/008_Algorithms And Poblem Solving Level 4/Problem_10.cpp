#include <iostream>

using namespace std;

short ReadDay()
{
	short Day = 0;
	cout << "Please Enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease Enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease Enter a Year? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month >12)
		return 0;

	short arrMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrMonth[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
	short TotalDays = 0;
	for (int i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(Year, i);
	}

	return TotalDays + Day;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of Days from the begining of the year is "
		<< NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day) << endl;

	return 0;
}
