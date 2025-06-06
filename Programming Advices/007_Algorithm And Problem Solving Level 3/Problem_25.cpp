#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ?\n";
	getline(cin, S);
	return S;
}

string LowerFirstLetterOfEachWord(string S)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && IsFirstLetter)
		{
			S[i] = tolower(S[i]);
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
	PrintString(LowerFirstLetterOfEachWord(ReadString()));

	return 0;
}