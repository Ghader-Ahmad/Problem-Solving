#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vString, string delim)
{
	string S = "";
	for (string& Word : vString)
	{
		S += Word + delim;
	}

	return S.substr(0, S.length() - delim.length());
}

string JoinString(string arr[], short Length, string delim)
{
	string S = "";
	for (short i = 0; i < Length; i++)
	{
		S += arr[i] + delim;
	}

	return S.substr(0, S.length() - delim.length());
}

int main()
{
	vector <string> vString = { "Mohammed", "Fadi", "Ali", "Maher" };
	
	string arr[] = { "Mohammed", "Fadi", "Ali", "Maher" };

	cout << "Vector after join : \n";
	cout << JoinString(vString, " ") << endl;
	
	cout << "\nArray after join  : \n";
	cout << JoinString(arr, 4, " ") << endl;

	return 0;
}