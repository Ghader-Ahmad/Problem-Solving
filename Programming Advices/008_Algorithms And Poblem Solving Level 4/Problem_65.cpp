#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	int Day;
	int Month;
	int Year;
};

string ReadDateString(string Message)
{
	string sDate;
	cout << Message;
	getline(cin >> ws, sDate);
	return sDate;
}

vector <string> SplitString(string S, string delim)
{
	string sWord;
	vector <string> vString;
	short pos = 0;

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

stDate StringToDate(string sDate, string Seperator)
{
	stDate Date;
	vector <string> vString = SplitString(sDate, "/");

	Date.Day = stoi(vString[0]);
	Date.Month = stoi(vString[1]);
	Date.Year = stoi(vString[2]);
	return Date;
}

string ReplaceWordInString(string S, string StringToReplace, string ReplaceTo)
{
	short pos = S.find(StringToReplace);

	while (pos != S.npos)
	{
		S = S.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S.find(StringToReplace);
	}
	return S;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string sDate;

	sDate = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	sDate = ReplaceWordInString(sDate, "mm", to_string(Date.Month));
	sDate = ReplaceWordInString(sDate, "yyyy", to_string(Date.Year));

	return sDate;
}

int main()
{
	string sDate = ReadDateString("Please Enter Date dd/mm/yyyy? ");
	stDate Date = StringToDate(sDate, "/");

	cout << "\n" << FormateDate(Date) << endl;
	cout << "\n" << FormateDate(Date, "yyyy/mm/dd") << endl;
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << endl;
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << endl;
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << endl;
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;

	system("pause>0");
	return 0;
}