#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

const string ClientFileName = "Client.txt";

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

stClientData ReadNewClient()
{
	stClientData ClientData;
	cout << "Enter Account Number? ";
	getline(cin >> ws, ClientData.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, ClientData.PinCode);

	cout << "Enter Name? ";
	getline(cin, ClientData.Name);

	cout << "Enter Phone? ";
	getline(cin, ClientData.Phone);

	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

string ConvertRecordToLine(stClientData ClientData, string Seperator = "#//#")
{
	string stClient;
	stClient += ClientData.AccountNumber + Seperator;
	stClient += ClientData.PinCode + Seperator;
	stClient += ClientData.Name + Seperator;
	stClient += ClientData.Phone + Seperator;
	stClient += to_string(ClientData.AccountBalance);

	return stClient;
}

void AddDataLineToFile(string FileName, string Line)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app); // Write and Append mode

	if (MyFile.is_open())
	{
		MyFile << Line << endl;

		MyFile.close();
	}
}

void RecetScreen()
{
	system("cls");
	system("color 0F");
}

void AddNewClient()
{
	stClientData ClientData = ReadNewClient();

	AddDataLineToFile(ClientFileName, ConvertRecordToLine(ClientData));
}

void AddClients()
{
	char AddMore = 'Y';
	while (toupper(AddMore) == 'Y')
	{
		RecetScreen();
		cout << "Adding New Client:\n\n";
		AddNewClient();

		cout << "\n\nClient Addaed Successfully, Do you want to add more clients ? ";
		cin >> AddMore;
	}
}

int main()
{
	AddClients();

	return 0;
}