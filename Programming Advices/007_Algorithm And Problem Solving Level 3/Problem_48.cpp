#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
const string ClientFileName = "Client.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
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

stClient ConsertLineToRecord(string Line, string Seperator = "#//#")
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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
	fstream Client;
	Client.open(FileName, ios::in);
	vector <stClient> Clients;
	if (Client.is_open())
	{
		string Line;
		while (getline(Client, Line))
		{
			Clients.push_back(ConsertLineToRecord(Line));
		}
		Client.close();
	}
	return Clients;
}

void PrintClientRecord(stClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintALlClientData(vector <stClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List(" << vClients.size() << ") Client(s).";
	cout << "\n---------------------------------------------------------";
	cout << "----------------------------------------------------------- \n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Account Balance";

	cout << "\n---------------------------------------------------------";
	cout << "----------------------------------------------------------- \n";

	for (stClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "---------------------------------------------------------";
	cout << "----------------------------------------------------------- \n";
}

int main()
{
	vector <stClient> vCleints = LoadClientsDataFromFile(ClientFileName);

	PrintALlClientData(vCleints);

	return 0;
}