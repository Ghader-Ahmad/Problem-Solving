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

bool IsVowel(char Ch)
{
	Ch = tolower(Ch);
	return ((Ch == 'e') || (Ch == 'o') || (Ch == 'i') || (Ch == 'u') || (Ch == 'a'));
}

short CountVowels(string S)
{
	short Counter = 0;
	for (short i = 0; i < S.length(); i++)
	{
		if (IsVowel(S[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S = ReadString();

	cout << "\n\nNumber of vowels is : " << CountVowels(S) << endl;

	return 0;
}