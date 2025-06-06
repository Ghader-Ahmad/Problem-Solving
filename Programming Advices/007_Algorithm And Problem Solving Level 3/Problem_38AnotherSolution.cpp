#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String ? \n";
	getline(cin, S);
	return S;
}

string TrimLeft(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ')
		{
			return S.substr(i, S.length() - i);
		}
	}
	return "";
}

string TrimRight(string S)
{
	for (short i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string S)
{
	return (TrimLeft(TrimRight(S)));
}

int main()
{
	string S1 = ReadString();

	cout << "String     = " << S1 << "\n\n";
	cout << "Trim Left  = " << TrimLeft(S1) << endl;
	cout << "Trim Right = " << TrimRight(S1) << endl;
	cout << "Trim       = " << Trim(S1) << endl;

	string S2 = "ghade";

	cout << S2.substr(0, 4);

	return 0;
}