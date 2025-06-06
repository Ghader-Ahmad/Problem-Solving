#include <iostream>
#include <cmath>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please Enter a Year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Please Enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "Please Enter a Day? ";
	cin >> Day;
	return Day;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
}

string DayShortName(short DayOrder)
{
	string arr[7] = { "Sun", "Mon","Tue","Wed","Thu","Fri","Sat" };

	return arr[DayOrder];
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;

	short DayOrder = DayOfWeekOrder(Year, Month, Day);

	cout << "\nDay Order : " << DayOrder;
	cout << "\nDay Name  : " << DayShortName(DayOrder);

	system("pause>0");
	return 0;
}