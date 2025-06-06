#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ? \n";
	getline(cin, S);
	return S;
}

vector <string> SplitString(string S, string delim)
{
	vector <string> vWords;
	string sWord;
	short pos = 0;

	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}

		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vWords.push_back(S);
	}

	return vWords;
}

string TrimRight(string S)
{
	for (short i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i + 1);
		}
	}
}

string ReveseWordsInString(string S)
{
	vector <string> vWords = SplitString(S, " ");
	string S1;


	vector <string> ::iterator iter = vWords.end();

	while (iter != vWords.begin())
	{
		--iter;
		S1 += *iter + " ";
	}
	return TrimRight(S1);
}

int main()
{
	string S1 = ReadString();

	cout << "\n\nString after reversing words : \n";
	cout << ReveseWordsInString(S1) << endl;

	return 0;
}
