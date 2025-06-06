#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

const string ClientFileName = "Client.txt";

vector <string> SplitString(string S, string delim)
{
	vector <string> vStrig;
	string sWord;
	short pos = 0;
	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vStrig.push_back(sWord);
		}

		S.erase(0, pos + delim.length());
	}

	if (S != "")
	{
		vStrig.push_back(S);
	}
	return vStrig;
}

stClient ConvertLineToRecord(string Line, string Seperator)
{
	vector <string> vString = SplitString(Line, Seperator);
	stClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector <stClient> LoadDataFromFile(string FileName, string Seperator = "#//#")
{
	vector <stClient> vClient;
	fstream Client;

	Client.open(FileName, ios::in);
	if (Client.is_open())
	{
		string Line;
		while (getline(Client, Line))
		{
			vClient.push_back(ConvertLineToRecord(Line, Seperator));
		}

		Client.close();
	}
	return vClient;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> vClient = LoadDataFromFile(ClientFileName);

	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(stClient& Client)
{
	cout << "\nThe following are the client details :\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

string ReadAccountNumber()
{
	string ANum;
	cout << "Please Enter Account Number? ";
	cin >> ANum;
	return ANum;
}

int main()
{
	stClient Client;

	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number(" << AccountNumber << ") Not found.\n";
	}

	return 0;
}