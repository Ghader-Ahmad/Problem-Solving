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
	char delim = ' ';
	short pos = 0;
	while (S[pos] == delim)
	{
		pos++;
	}
	return S.erase(0, pos);
}

string TrimRight(string S)
{
	char delim = ' ';
	short pos = S.length() - 1;

	while (S[pos] == delim)
	{
		pos--;
	}

	return S.erase(pos + 1, S.length());
}

string Trim(string S)
{
	S = TrimRight(S);
	S = TrimLeft(S);
	return S;
}

int main()
{
	string S1 = ReadString();
	cout << "String     = " << S1 << "\n\n";
	cout << "Trim Left  = " << TrimLeft(S1) << endl;
	cout << "Trim Right = " << TrimRight(S1) << endl;
	cout << "Trim       = " << Trim(S1) << endl;

	return 0;
}