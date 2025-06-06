
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

const string ClientFileName = "Client.txt";

void ShowMeanMenu();
void ShowTransactiosMenu();

enum enMainMenuScreen
{
	enListMenu = 1, enAddNewClient = 2,
	enDeleteClient = 3, enUpdateClient = 4,
	enFindClient = 5, enShowTransactionsMenu = 6,
	enExit = 7
};

enum enTransactionMenue
{
	enDeposit = 1, enWithdraw = 2,
	enShowTotalBalance = 3, enShowMainMenue = 4
};

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

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
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

vector <stClient> LoadDataFromFile(string FileName, string Seperator = "#//#")
{
	vector <stClient> vClients;
	fstream Client;
	Client.open(FileName, ios::in);
	if (Client.is_open())
	{
		string Line;
		stClient C;
		while (getline(Client,Line))
		{
			C = ConvertLineToRecord(Line);
			vClients.push_back(C);
		}

		Client.close();
	}
	return vClients;
}

void PrintClientRecordLine(stClient& Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector <stClient> vClients = LoadDataFromFile(ClientFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
	cout << "----------------------------------------------------------------";
	cout << "-----------------------------------------------------\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n";

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Availble In the system!\n";
	}

	else
	{

		for (stClient& C : vClients)
		{
			PrintClientRecordLine(C);
			cout << endl;
		}
	}

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n";
}

void GoBackToMainMenu()
{
	cout << "\n\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMeanMenu();
}

void GoBackToTransactionsMenue()
{
	cout << "\n\n\nPress any key to go back to Transaction Menue...";
	system("pause>0");
	ShowTransactiosMenu();
}

bool ClientExistsByAccountNumber(vector <stClient>& vClinets, string AccountNumber)
{
	for (stClient& C : vClinets)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}

stClient ReadNewClient(vector <stClient>& vClinets)
{
	stClient Client;

	cout << "Adding New Client: \n";

	cout << "\nEnter AccountNumber? ";
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(vClinets, Client.AccountNumber))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient& Client, string Seperator = "#//#")
{
	string S;
	
	S += Client.AccountNumber + Seperator;
	S += Client.PinCode + Seperator;
	S += Client.Name + Seperator;
	S += Client.Phone + Seperator;
	S += to_string(Client.AccountBalance);

	return S;
}

void AddDataLineToFile(string DataClient, string FileName)
{
	fstream Client;
	Client.open(FileName, ios::out | ios::app);

	if (Client.is_open())
	{
		Client << DataClient << endl;

		Client.close();
	}
}

void AddNewClient()
{
	vector <stClient> vClinets = LoadDataFromFile(ClientFileName);
	stClient Client = ReadNewClient(vClinets);
	AddDataLineToFile(ConvertRecordToLine(Client), ClientFileName);
}

void AddNewClients()
{
	char AddMore = 'Y';

	while (toupper(AddMore) == 'Y')
	{

		AddNewClient();

		cout << "\n\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	}
}

void ShowAddNewClients()
{
	cout << "\n----------------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n----------------------------------------\n";
	
	AddNewClients();
}

string ReadClientAccountNumber()
{
	string S;
	cout << "\nPlease Enter AccountNumber? ";
	getline(cin >> ws, S);
	return S;
}

bool FindClientByAccountNumber(vector <stClient>& vClients, string AccountNumber, stClient& Client)
{
	for (stClient& C : vClients)
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
	cout << "\nThe following are the client detials:\n";
	cout << "----------------------------------------\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
	cout << "----------------------------------------\n";
}

void SaveDataClientToFile(vector <stClient>& vClients, string FileName)
{
	fstream Client;
	Client.open(FileName, ios::out);
	
	if(Client.is_open())
	{
		for (stClient& C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				Client << ConvertRecordToLine(C) << endl;
			}
		}
		Client.close();
	}
}

bool MarkClientForDeleting(vector <stClient>& vClients, string AccountNumber)
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

bool DeleteClientByAccountNumber(vector <stClient> vClients, string AccountNumber)
{
	stClient Client;
	char Answer = 'Y';

	if (FindClientByAccountNumber(vClients, AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleting(vClients, AccountNumber);
			SaveDataClientToFile(vClients, ClientFileName);

			// Refreach vClients

			vClients = LoadDataFromFile(ClientFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}

	else
	{
		cout << "\nClient with Account Number(" << AccountNumber << ") is Not Found!.";
		return false;
	}
}

void ShowDeleteClientScreen()
{
	cout << "\n----------------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n----------------------------------------\n";

	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(vClients, AccountNumber);
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

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(vector <stClient> vClients, string AccountNumber)
{
	stClient Client;
	char Answer = 'Y';

	if (FindClientByAccountNumber(vClients, AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			stClient Client = ChangeClientRecord(AccountNumber);


			for (stClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = Client;
					break;
				}
			}

			SaveDataClientToFile(vClients, ClientFileName);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number(" << AccountNumber << ") is Not Found!.";
		return false;
	}

}

void ShowUpdateClientScreen()
{
	cout << "\n----------------------------------------\n";
	cout << "\tUpdate Client Screen";
	cout << "\n----------------------------------------\n";
	
	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientByAccountNumber(vClients, AccountNumber);
}

void ShowFindClientScreen()
{
	cout << "\n----------------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n----------------------------------------\n";

	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	stClient Client;

	if (FindClientByAccountNumber(vClients, AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\n\nClient with Account Number[" << AccountNumber << "] is not found!";
	}
}

void ShowEndScreen()
{
	cout << "\n----------------------------------------\n";
	cout << "\tProgram End :-)";
	cout << "\n----------------------------------------\n";

	system("color 4F");
}

void PerformMeanMenuOption(enMainMenuScreen MainMenuScreen)
{

	switch (MainMenuScreen)
	{

	case enMainMenuScreen::enListMenu:
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuScreen::enAddNewClient:
		system("cls");
		ShowAddNewClients();
		GoBackToMainMenu();
		break;

	case enMainMenuScreen::enDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuScreen::enUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuScreen::enFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuScreen::enShowTransactionsMenu:
		system("cls");
		ShowTransactiosMenu();
		break;


	case enMainMenuScreen::enExit:
		system("cls");
		ShowEndScreen();
		break;

	}

}

short ReadMainMenuOption()
{
	short Choose = 0;

	cout << "Choose What do you want to do? [1 to 7]? ";
	cin >> Choose;

	return Choose;
}

void ShowMeanMenu()
{
	system("cls");

	cout << "==========================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "==========================================\n";

	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";

	cout << "==========================================\n";

	PerformMeanMenuOption((enMainMenuScreen)ReadMainMenuOption());
}


////////////////////////////////////////////////////////// Transactios Menue //////////////////////////////////////////////////

bool DepositBalanceToClientByAccountNumber(vector <stClient>& vClients, string AccountNumber, double Amount)
{
	char Answer = 'Y';

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	cin >> Answer;

	if (toupper(Answer) == 'Y')
	{

		for (stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance +=  Amount;
				SaveDataClientToFile(vClients, ClientFileName);
				cout << "\n\nDone Successfully, New Balance : " << C.AccountBalance << endl;
				return true;
			}
		}
		return false;
	}
}

void ShowDepositScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n---------------------------------\n";

	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	stClient Client;

	while (!(FindClientByAccountNumber(vClients, AccountNumber, Client)))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double Amount = 0;
	
	cout << "\nPlease enter deposit amount? ";
	cin >> Amount;

	DepositBalanceToClientByAccountNumber(vClients, AccountNumber, Amount);
}

void PrintClientBalanceRecordLine(stClient& Client)
{
	cout << "| " << setw(15) << Client.AccountNumber;
	cout << "| " << setw(40) << Client.Name;
	cout << "| " << setw(12) << Client.AccountBalance;
}

void ShowTotalBalancesScreen()
{
	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	double TotalBalance = 0;


	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).\n";
	cout << "----------------------------------------------------------------";
	cout << "-----------------------------------------------------\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n\n";

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Availble In the system!\n";
	}

	else
	{

		for (stClient& C : vClients)
		{
			PrintClientBalanceRecordLine(C);
			TotalBalance += C.AccountBalance;
			cout << endl;
		}
	}

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n";

	cout << "\n\t\t\t\t\tTotal Balance = " << TotalBalance << endl;
}

double ReadClientWithdrawAmount()
{
	double WithdrawAmount;
	cout << "\nPlease Enter withdraw amount? ";
	cin >> WithdrawAmount;
	return WithdrawAmount;
}

void ShowWithdrawScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tWithdraw Screen";
	cout << "\n---------------------------------\n";

	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	stClient Client;

	while (!(FindClientByAccountNumber(vClients, AccountNumber, Client)))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double Amount;
	
	cout << "\nPlease enter withdraw amount ? ";
	cin >> Amount;

	while (Amount > Client.AccountBalance)
	{
		cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
		
		cout << "\nPlease enter another amount? ";
		cin >> Amount;
	}

	DepositBalanceToClientByAccountNumber(vClients, AccountNumber, Amount * -1);
}

void PerformTransactionsMenuOption(enTransactionMenue TransactionMenue)
{
	switch (TransactionMenue)
	{

	case enTransactionMenue::enDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenue();
		break;

	case enTransactionMenue::enWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenue();
		break;

	case enTransactionMenue::enShowTotalBalance:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenue();
		break;

	case enTransactionMenue::enShowMainMenue:
		ShowMeanMenu();
		break;

	}

}

short ReadTransactiosMenuOption()
{
	short Choose = 0;
	cout << "Choose What do you want to do? [1 to 4]? ";
	cin >> Choose;

	return Choose;
}

void ShowTransactiosMenu()
{
	system("cls");
	system("color DF");

	cout << "===============================================\n";
	cout << "\t\tTransctios Menu Screen\n";
	cout << "===============================================\n";

	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "===============================================\n";

	PerformTransactionsMenuOption((enTransactionMenue)ReadTransactiosMenuOption());
}

int main()
{
	ShowMeanMenu();
	system("pause>0");

	return 0;
}