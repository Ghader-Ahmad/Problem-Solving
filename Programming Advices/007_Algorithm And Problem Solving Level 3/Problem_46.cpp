#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClientData
{
	string AccountNumber;
	string PinCde;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string S, string delim = "#//#")
{
	vector <string> vWords;
	string sWord = "";
	short pos = 0;
	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}
		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vWords.push_back(S);
	}
	return vWords;
}

stClientData ConvertLineToRecord(string S)
{
	vector <string> vWords = SplitString(S);
	stClientData ClientData;

	ClientData.AccountNumber = vWords.at(0);
	ClientData.PinCde = vWords.at(1);
	ClientData.Name = vWords.at(2);
	ClientData.Phone = vWords.at(3);
	ClientData.AccountBalance = stod(vWords.at(4));

	return ClientData;
}

void PrintClientData(stClientData ClientData)
{
	cout << "\n\nThe following is the extracted client record :\n\n";

	cout << "Account Number : " << ClientData.AccountNumber << endl;
	cout << "PinCode        : " << ClientData.PinCde << endl;
	cout << "Name           : " << ClientData.Name << endl;
	cout << "Phone          : " << ClientData.Phone << endl;
	cout << "AccountBalance : " << ClientData.AccountBalance << endl;
}

int main()
{
	string S1 = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#789456123#//#5000.000000";

	cout << "Line Record is : \n";
	cout << S1 << endl;

	stClientData ClientData = ConvertLineToRecord(S1);

	PrintClientData(ClientData);

	return 0;
}
