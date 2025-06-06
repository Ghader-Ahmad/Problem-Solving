#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, PunctLetters = 2, SpaceLetter = 3, AllLetters = 4 };

string ReadString()
{
	string S;
	cout << "Please enter your string ? \n";
	getline(cin, S);
	return S;
}

short CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::AllLetters)
{
	short Counter = 0;
	if (WhatToCount == enWhatToCount::AllLetters)
	{
		return S.length();
	}

	for (int i = 0; i < S.length(); i++)
	{
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S[i]))
		{
			Counter++;
		}

		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S[i]))
		{
			Counter++;
		}

		if (WhatToCount == enWhatToCount::PunctLetters && ispunct(S[i]))
		{
			Counter++;
		}
		if (WhatToCount == enWhatToCount::SpaceLetter && S[i] == ' ')
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString Length         = " << CountLetters(S1) << endl;
	cout << "Capital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters) << endl;
	cout << "Small Letters Count   = " << CountLetters(S1, enWhatToCount::SmallLetters) << endl;
	cout << "Punct Letters Count   = " << CountLetters(S1, enWhatToCount::PunctLetters) << endl;
	cout << "Space Letters Count   = " << CountLetters(S1, enWhatToCount::SpaceLetter) << endl;

	return 0;
}