#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string SmallAllString(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	return S;
}

vector <string> SplitString(string S, string delim)
{
	vector <string> vWords;
	string sWords;
	short pos = 0;

	while ((pos = S.find(delim)) != S.npos)
	{
		sWords = S.substr(0, pos);
		if (sWords != "")
		{
			vWords.push_back(sWords);
		}
		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vWords.push_back(S);
	}

	return vWords;
}

string JoinString(vector <string> vWords, string delim)
{
	string S1;
	for (string& s : vWords)
	{
		S1 += s + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

string ReplaceWordInStringUsingSplit(string S, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
	vector <string> vWords = SplitString(S, " ");
	//string S1;

	for (string& Word : vWords)
	{
		if (MatchCase)
		{
			if (Word == StringToReplace)
			{
				Word = ReplaceTo;
			}
		}
		else
		{
			if (SmallAllString(Word) == SmallAllString(StringToReplace))
			{
				Word = ReplaceTo;
			}
		}
	}
	return JoinString(vWords, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << "Orignal String : \n";
	cout << S1 << endl;

	cout << "\nReplace with match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

	cout << "\n\nReplace with dont match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;

	return 0;
}
