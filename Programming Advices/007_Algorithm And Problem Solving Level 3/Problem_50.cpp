#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;
const string ClientFileName = "Client.txt";
const string Seperator = "#//#";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

vector <string> SplitString(string S, string delim)
{
	vector <string> vString;
	string sWord;
	short pos = 0;
	while ((pos = S.find(delim)) != S.npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}
	return vString;
}

stClient ConvertLineToRecord(string S, string Seperator)
{
	vector <string> vString = SplitString(S, Seperator);
	stClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

string ConvertRecordToLine(stClient& Client, string Seperator)
{
	string stClientData;

	stClientData += Client.AccountNumber + Seperator;
	stClientData += Client.PinCode + Seperator;
	stClientData += Client.Name + Seperator;
	stClientData += Client.Phone + Seperator;
	stClientData += to_string(Client.AccountBalance);

	return stClientData;
}

vector <stClient> LoadClientDataFromFile(string FileName)
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

void SaveClientDataToFile(vector <stClient>& vClient, string FileName)
{
	string stClientData;

	fstream Client;
	Client.open(FileName, ios::out);
	if (Client.is_open())
	{
		for (stClient& C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				Client << ConvertRecordToLine(C, Seperator) << endl;
			}
		}
		Client.close();
	}
}

void PrintClientCard(stClient& Client)
{
	cout << "\nThe following are the client detials :\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClient, stClient& Client)
{
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
	stClient Client;
	char Answer = 'Y';

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
			SaveClientDataToFile(vClient, ClientFileName);

			// Refrech vClient
			vClient = LoadClientDataFromFile(ClientFileName);

			cout << "\n\nClient Deleted Successfully.\n";
			return true;
		}

		else
		{
			cout << "\n\nClient is found , But it is Not Delete .\n";
		}
		return true;
	}
	cout << "\n\nClient with Account Number (" << AccountNumber << ") is Not Found!.\n";
	return false;
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
	vector <stClient> vClient = LoadClientDataFromFile(ClientFileName);
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClient);

	return 0;
}