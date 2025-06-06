#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
	char Ch;
	cout << "Please Enter Your Character ?\n";
	cin >> Ch;
	return Ch;
}

bool IsVowel(char Ch)
{
	Ch = tolower(Ch);

	return ((Ch == 'e') || (Ch == 'a') || (Ch == 'i') || (Ch == 'u') || (Ch == 'o'));
}

int main()
{
	char Ch1 = ReadChar();

	if (IsVowel(Ch1))
	{
		cout << "\n\nYES Letter \'" << Ch1 << "\' is vowel.\n";
	}
	else
	{
		cout << "\n\nNO Letter \'" << Ch1 << "\' is not vowel.\n";
	}

	return 0;
}