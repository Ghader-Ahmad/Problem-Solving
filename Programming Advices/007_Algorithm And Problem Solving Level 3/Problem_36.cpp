#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S = "";
	cout << "Please Enter Your String ?\n";
	getline(cin, S);
	return S;
}

short CountWordsInString(string S1)
{
	string delim = " ", sWord = "";
	short pos = 0, Counter = 0;
	
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	cout << "\nThe Number of words in your string is : " << CountWordsInString(ReadString()) << endl;


	return 0;
}