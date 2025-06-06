#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

stClient ConvertLineToRecord(string Line)
{
	vector <string> vWord = SplitString(Line, Seperator);
	stClient Client;

	Client.AccountNumber = vWord[0];
	Client.PinCode = vWord[1];
	Client.Name = vWord[2];
	Client.Phone = vWord[3];
	Client.AccountBalance = stod(vWord[4]);

	return Client;
}

string ConvertRecordToLine(stClient& Client, string Seperator)
{
	string stClient;

	stClient += Client.AccountNumber + Seperator;
	stClient += Client.PinCode + Seperator;
	stClient += Client.Name + Seperator;
	stClient += Client.Phone + Seperator;
	stClient += to_string(Client.AccountBalance);

	return stClient;
}

vector <stClient> LoadClientDataFromFile(string FileName)
{
	vector <stClient> vClient;
	fstream Client;
	Client.open(FileName, ios::in);
	if (Client.is_open())
	{
		string Line;
		stClient C;
		while (getline(Client, Line))
		{
			C = ConvertLineToRecord(Line);
			vClient.push_back(C);
		}

		Client.close();
	}
	return vClient;
}

void PrintClientCard(stClient& Client)
{
	cout << "\nThe following are the clients details: \n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(vector <stClient>& vClinets, string AccountNumber, stClient& Client)
{
	for (stClient& C : vClinets)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

stClient ChangeClientRecord(string AccountNumber)
{
	stClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccounBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool MarkClientForDeletedByAccountNumber(vector <stClient>& vClients, string AccountNumber)
{
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

void SaveClientDataToFile(string FileName, vector<stClient>& vClients)
{
	fstream MyClient;
	MyClient.open(FileName, ios::out);

	if (MyClient.is_open())
	{
		string Data;

		for (stClient& C : vClients)
		{
			Data = ConvertRecordToLine(C, Seperator);
			MyClient << Data << endl;
		}
		MyClient.close();
	}
}

bool UpdateClientByAccountNumber(vector <stClient>& vClinets, string AccountNumber)
{
	stClient Client;
	char Answer = 'Y';

	if (FindClientByAccountNumber(vClinets, AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure want update this client? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			for (stClient& C : vClinets)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
				}
			}

			SaveClientDataToFile(ClientFileName, vClinets);

			cout << "\n\nClient Updated Seccessfully.\n";
			return true;
		}
		else
		{
			cout << "\n\nClient is found, But it is Not Update.\n";
			return true;
		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber << ") Not Found!.\n";
		return false;
	}

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
	vector <stClient> vClients = LoadClientDataFromFile(ClientFileName);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(vClients, AccountNumber);

	return 0;
}