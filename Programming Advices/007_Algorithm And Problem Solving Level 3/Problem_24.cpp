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

string UpperFirstLetterOfEachWord(string S)
{
	bool IsFirstLetter = true;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && IsFirstLetter)
		{
			S[i] = toupper(S[i]);
		}
		IsFirstLetter = (S[i] == ' ' ? true : false);
	}
	return S;
}

void PrintString(string S)
{
	cout << "\n\nString after conversion : \n" << S << endl;
}

int main()
{
	PrintString(UpperFirstLetterOfEachWord(ReadString()));

	return 0;
}