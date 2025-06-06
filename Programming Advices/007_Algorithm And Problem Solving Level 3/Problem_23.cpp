#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ?\n";
	getline(cin, S);
	return S;
}

void PrintFirstLetterOfEachWord(string S)
{
	bool IsFirstLetter = true;
	cout << "\n\nFirst Letter of this string : \n";
	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && IsFirstLetter)
		{
			cout << S[i] << endl;
		}
		IsFirstLetter = (S[i] == ' ' ? true : false);
	}
}

int main()
{
	string S1 = ReadString();
	PrintFirstLetterOfEachWord(S1);

	return 0;
}