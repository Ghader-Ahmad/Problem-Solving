#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	int Day = 0;
	int Month = 0;
	int Year = 0;
};

string ReadDateString()
{
	string DateString;
	cout << "Please Enter Date dd/mm/yyyy? ";
	getline(cin >> ws, DateString);
	return DateString;
}

vector <string> SplitString(string S, string delim)
{
	string sWord;
	short pos = 0;
	vector <string> vString;

	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}
	return vString;
}

stDate StringToDate(string S)
{
	stDate Date;
	vector <string> vDate = SplitString(S, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(stDate Date, string Seperator)
{
	string DateString;
	
	DateString += to_string(Date.Day) + Seperator;
	DateString += to_string(Date.Month) + Seperator;
	DateString += to_string(Date.Year);

	return DateString;
}

void PrintDate(stDate Date)
{
	cout << "\nDay:" << Date.Day;
	cout << "\nMonth:" << Date.Month;
	cout << "\nYear:" << Date.Year;
}

int main()
{
	string S = ReadDateString();
	stDate Date = StringToDate(S);

	PrintDate(Date);

	cout << "\n\nYou Entered: " << DateToString(Date,"/");

	system("pause>0");
	return 0;
}