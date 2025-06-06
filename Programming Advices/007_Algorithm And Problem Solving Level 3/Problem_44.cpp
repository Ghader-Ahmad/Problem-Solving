#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemovedPauncuationsFromString(string S)
{
	string S2;

	for (short i = 0; i < S.length(); i++)
	{
		if (!ispunct(S[i]))
		{
			S2 += S[i];
		}
	}
	return S2;
}


int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "Original String : \n";
	cout << S1 << endl;

	cout << "\nPauncuations Removed : \n";
	cout << RemovedPauncuationsFromString(S1) << endl;

	return 0;
}