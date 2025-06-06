#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
	string S;
	cout << "Plaese enter your string ?\n";
	getline(cin, S);
	return S;
}

string UpperAllString(string S)
{
	for (int i = 0; i < S.length(); i++)
	{
		S[i] = toupper(S[i]);
	}
	return S;
}

string LowerAllString(string S)
{
	for (int i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	return S;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\nString after Upper : \n" << UpperAllString(S1) << endl;

	cout << "\n\nString after Lower : \n" << LowerAllString(S1) << endl;

	return 0;
}