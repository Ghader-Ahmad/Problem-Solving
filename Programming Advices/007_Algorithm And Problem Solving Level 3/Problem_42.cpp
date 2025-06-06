#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInStringUsingBuildInFunction(string S, string StringToReplace, string ReplaceTo)
{
	short pos = S.find(StringToReplace);
	while (pos != S.npos)
	{
		S = S.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S.find(StringToReplace);
	}
	return S;
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice countary";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";

	cout << "Original String : \n";
	cout << S1 << endl;

	cout << "\nString After Replace :\n";
	cout << ReplaceWordInStringUsingBuildInFunction(S1, StringToReplace, ReplaceTo) << endl;

	return 0;
}