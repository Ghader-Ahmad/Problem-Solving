#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ?\n";
	getline(cin, S);
	return S;
}

vector <string> SplitString(string S, string delim)
{
	vector <string> vWords;
	short pos = 0;
	string sWord;
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

void PrintWords(vector <string>& vWords)
{
	for (string& S1 : vWords)
	{
		cout << S1 << endl;
	}
}

int main()
{
	string S1 = ReadString();
	vector <string> vWords = SplitString(S1, " ");

	cout << "\nTokens = " << vWords.size() << endl;
	PrintWords(vWords);


	return 0;
}
