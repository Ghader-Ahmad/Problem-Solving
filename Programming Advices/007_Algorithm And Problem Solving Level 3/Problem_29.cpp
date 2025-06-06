#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please enter your string ? \n";
	getline(cin, S);
	return S;
}

short CountCapitalLetters(string S)
{
	short CountUpLetters = 0;
	for (int i = 0; i < S.length(); i++)
	{
		if (isupper(S[i]))
		{
			CountUpLetters++;
		}
	}
	return CountUpLetters;
}

short CountSmallLetters(string S)
{
	short CountSmLetter = 0;
	for (int i = 0; i < S.length(); i++)
	{
		if (islower(S[i]))
		{
			CountSmLetter++;
		}
	}
	return CountSmLetter;
}

int main()
{
	string S = ReadString();

	cout << "\n\nString Length = " << S.length() << endl;
	cout << "Capital Letters Count = " << CountCapitalLetters(S) << endl;
	cout << "Small Letters Count = " << CountSmallLetters(S) << endl;

	return 0;
}