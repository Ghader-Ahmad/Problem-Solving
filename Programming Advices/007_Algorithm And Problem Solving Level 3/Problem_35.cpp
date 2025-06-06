#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ? \n";
	getline(cin, S);
	return S;
}

void PrintWordInString(string S)
{
	string sWord = "", delim = " ";
	short pos = 0;
	cout << "\nYour String words are : \n\n";
	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}

		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		cout << sWord << endl;
	}
}

int main()
{
	string S1 = ReadString();

	PrintWordInString(S1);

	return 0;
}