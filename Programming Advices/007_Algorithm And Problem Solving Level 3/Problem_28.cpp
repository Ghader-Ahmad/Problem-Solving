#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please enter your string ?\n";
	getline(cin, S);

	return S;
}

char InvertLetterCase(char c)
{
	return (islower(c) ? toupper(c) : tolower(c));
}

string InvertAllStringLettersCase(string S)
{
	for (int i = 0; i < S.length(); i++)
	{
		S[i] = InvertLetterCase(S[i]);
	}

	return S;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\nString after Inverting All Letters Case : \n" << InvertAllStringLettersCase(S1) << endl;

	return 0;
}