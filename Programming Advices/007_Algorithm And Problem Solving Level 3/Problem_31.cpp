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

char ReadCharacter()
{
	char Ch;
	cout << "\nPlease Enter Your Character ?\n";
	cin >> Ch;
	return Ch;
}

char InvertLetterCase(char Ch)
{
	return (islower(Ch) ? toupper(Ch) : tolower(Ch));
}

short CountLetter(string S, char Letter, bool MatchCase = true)
{
	short Counter = 0;
	for (short i = 0; i < S.length(); i++)
	{
		if (MatchCase)
		{
			if (S[i] == Letter)
			{
				Counter++;
			}
		}
		else
		{
			if (tolower(S[i]) == tolower(Letter))
			{
				Counter++;
			}
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char Ch1 = ReadCharacter();

	cout << "\n\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;

	cout << "Letter \'" << Ch1 << "\' Or \'";
	cout << InvertLetterCase(Ch1) << "\' ";
	cout << "Count = " << CountLetter(S1, Ch1, false) << endl;

	return 0;
}