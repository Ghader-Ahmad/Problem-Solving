#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please Enter a Year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease Enter a Month to check? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (NumberOfDays[Month - 1]);
}

short NumberOfHoursInAMonth(short Month, short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
	cout << "\nNumber of Hours   in [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber of Minutes in [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber of Seconds in [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);
	
	system("pause>0");

	return 0;
}