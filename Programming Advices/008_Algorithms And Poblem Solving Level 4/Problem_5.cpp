#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please Enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease Enter a month to check? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i < 7; i++)
	{
		if (arr31Days[i] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
	return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecnodsInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecnodsInMonth(Year, Month);
	system("pause>0");

	return 0;
}
