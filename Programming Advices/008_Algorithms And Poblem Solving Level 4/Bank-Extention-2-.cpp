
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

const string ClientFileName = "Client.txt";
const string UserFileName = "User.txt";

void ShowMeanMenu();
void ShowTransactiosMenu();
void ShowManageUsersMenueScreen();
void Login();

enum enMainMenuOptions
{
	enListMenu = 1, enAddNewClient = 2,
	enDeleteClient = 3, enUpdateClient = 4,
	enFindClient = 5, enShowTransactionsMenu = 6,
	enManageUsers = 7, enExist = 8
};

enum enTransactionMenue
{
	enDeposit = 1, enWithdraw = 2,
	enShowTotalBalance = 3, enShowMainMenue = 4
};

enum enMangeUsersMenueOptions
{
	enListUsers = 1, enAddNewUser = 2,
	enDeleteUser = 3, enUpdateUser = 4,
	enFindUser = 5, enMainMenue = 6
};

enum enMainMenuePermission
{
	pListClient = 1, pAddNewClient = 2,
	pDeleteClient = 4, pUpdateClient = 8,
	pFindClient = 16, pTransaction = 32,
	pManager = 64, pAllAccess = -1
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

struct stUser
{
	string Name;
	string Password;
	int Permission;
	bool FlagForDelete = false;
};

stUser UserCurrent;

bool CheckAccessPermission(enMainMenuePermission MainMenuePermission)
{
	if (UserCurrent.Permission == enMainMenuePermission::pAllAccess)
		return true;

	if ((MainMenuePermission & UserCurrent.Permission) == MainMenuePermission)
		return true;
	else
		return false;
}

void ShowAccessDeniedMessage()
{
	cout << "\n\n-----------------------------------------------\n";
	cout << "Access Denied,\n";
	cout << "You dont Have Permission To Do this,\n";
	cout << "Please Conact Your Admin.\n";
	cout << "-----------------------------------------------\n";
}

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
		while (getline(Client, Line))
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
	if (!CheckAccessPermission(enMainMenuePermission::pListClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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
	if (!CheckAccessPermission(enMainMenuePermission::pAddNewClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

	if (Client.is_open())
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
	if (!CheckAccessPermission(enMainMenuePermission::pDeleteClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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
	if (!CheckAccessPermission(enMainMenuePermission::pUpdateClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n----------------------------------------\n";
	cout << "\tUpdate Client Screen";
	cout << "\n----------------------------------------\n";

	vector <stClient> vClients = LoadDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientByAccountNumber(vClients, AccountNumber);
}

void ShowFindClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermission::pFindClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

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

void PerformMeanMenuOption(enMainMenuOptions MainMenuScreen)
{

	switch (MainMenuScreen)
	{
	case enMainMenuOptions::enListMenu:
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::enAddNewClient:
		system("cls");
		ShowAddNewClients();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::enDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::enUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::enFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::enShowTransactionsMenu:
		system("cls");
		ShowTransactiosMenu();
		break;

	case enMainMenuOptions::enManageUsers:
		system("cls");
		ShowManageUsersMenueScreen();
		break;

	case enMainMenuOptions::enExist:
		system("cls");
		//ShowEndScreen();
		Login();
		break;

	}

}

short ReadMainMenuOption()
{
	short Choose = 0;

	cout << "Choose What do you want to do? [1 to 8]? ";
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
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";

	cout << "==========================================\n";

	PerformMeanMenuOption((enMainMenuOptions)ReadMainMenuOption());
}


///////////////////////////////////////////////////// Transactios Menue ////////////////////////////////////////////////


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
				C.AccountBalance += Amount;
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
	if (!CheckAccessPermission(enMainMenuePermission::pTransaction))
	{
		ShowAccessDeniedMessage();
		GoBackToMainMenu();
		return;
	}

	system("cls");

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


/////////////////////////////////////////////////// Maneger User Menue ////////////////////////////////////////////////


stUser ConvertLineToRecordInUser(string Line, string Seperator = "#//#")
{
	vector <string> vString = SplitString(Line, Seperator);

	stUser User;

	User.Name = vString[0];
	User.Password = vString[1];
	User.Permission = stoi(vString[2]);

	return User;
}

vector <stUser> LoadUsersDataFromFile(string FileName, string Seperator = "#//#")
{
	vector <stUser> vUser;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vUser.push_back(ConvertLineToRecordInUser(Line));
		}
		MyFile.close();
	}
	return vUser;
}

bool FineUserByUsernameAndPassword(string Username, string Password, stUser& User)
{
	vector<stUser> vUsers = LoadUsersDataFromFile(UserFileName);

	for (stUser& U : vUsers)
	{
		if (U.Name == Username && U.Password == Password)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool FindUserByUsername(vector <stUser>& vUsers, string Username, stUser& User)
{
	for (stUser& U : vUsers)
	{
		if (U.Name == Username)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool UserExistsByUsername(vector <stUser>& vUsers, string Name)
{
	for (stUser& U : vUsers)
	{
		if (U.Name == Name)
		{
			return true;
		}
	}
	return false;
}

short ReadMangeUsersMenueOption()
{
	short Choose = 0;
	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Choose;
	return Choose;
}

void GoBackToMangeMenueScreen()
{
	cout << "\n\n\nPress any key to go back to Transaction Menue...";
	system("pause>0");
	ShowManageUsersMenueScreen();
}

void PrintUsersRecordLine(stUser User)
{
	cout << "| " << left << setw(15) << User.Name;
	cout << "| " << left << setw(40) << User.Password;
	cout << "| " << left << setw(10) << User.Permission;
}

void ShowAllUsersScreen()
{
	vector <stUser> vUsers = LoadUsersDataFromFile(UserFileName);

	cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).\n";
	cout << "----------------------------------------------------------------";
	cout << "-----------------------------------------------------\n";

	cout << "| " << left << setw(15) << "Name";
	cout << "| " << left << setw(40) << "Password";
	cout << "| " << left << setw(10) << "Permission";

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n";

	if (vUsers.size() == 0)
	{
		cout << "\t\t\t\tNo Users Availble In the system!\n";
	}


	for (stUser& U : vUsers)
	{
		PrintUsersRecordLine(U);
		cout << endl;
	}
	

	cout << "\n------------------------------------------------------------";
	cout << "---------------------------------------------------------\n";
}

int ReadPermissionToSet()
{
	int Permission = 0;
	char Answer = 'y';

	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;

	if (toupper(Answer) == 'Y')
	{
		return enMainMenuePermission::pAllAccess;
	}

	cout << "\nDo you want to give access to : \n";

	cout << "\nShow Client List? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pListClient;
	}

	cout << "\nAdd New Client? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pAddNewClient;
	}

	cout << "\nDelete Client? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pDeleteClient;
	}

	cout << "\nUpdate Client? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pUpdateClient;
	}

	cout << "\nFind Client? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pFindClient;
	}

	cout << "\nTransactions? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pTransaction;
	}

	cout << "\nMange Users? y/n? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		Permission += enMainMenuePermission::pManager;
	}


	return Permission;

}

stUser ReadNewUser(vector <stUser>& vUsers)
{
	stUser User;

	cout << "\nEnter Username? ";
	getline(cin >> ws, User.Name);

	while (UserExistsByUsername(vUsers,User.Name))
	{
		cout << "\nUser with[" << User.Name << "] already exists, Enter another Username? ";
		getline(cin >> ws, User.Name);
	}

	cout << "\nEnter Password? ";
	getline(cin, User.Password);

	User.Permission = ReadPermissionToSet();

	return User;
}

string ConvertUserRecordToLine(stUser User, string Seperator = "#//#")
{
	string sUser;

	sUser += User.Name + Seperator;
	sUser += User.Password + Seperator;
	sUser += to_string(User.Permission);
	return sUser;
}

void AddNewUser()
{
	vector <stUser> vUsers = LoadUsersDataFromFile(UserFileName);
	stUser User = ReadNewUser(vUsers);
	AddDataLineToFile(ConvertUserRecordToLine(User), UserFileName);
}

void AddNewUsers()
{
	char AddMore = 'Y';

	while (toupper(AddMore) == 'Y')
	{
		cout << "Adding New User:\n\n";

		AddNewUser();

		cout << "\n\nUser Added Successfully, do you want to add more users? Y/N? ";
		cin >> AddMore;
	}
}

void ShowAddNewUsersScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tAdd New User Screen";
	cout << "\n---------------------------------\n";

	cout << "Adding New User: \n";
	
	AddNewUsers();

}

string ReadUsername()
{
	string Username;
	cout << "\nPlease enter  Username? ";
	cin >> Username;
	return Username;
}

void SaveDataUserToFile(vector<stUser>& vUsers, string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (stUser& U : vUsers)
		{
			if (U.FlagForDelete == false)
			{
				MyFile << ConvertUserRecordToLine(U) << endl;
			}
		}
		MyFile.close();
	}
}

void PrintUserCard(stUser User)
{
	cout << "\nThe following are the User detials:\n";
	cout << "----------------------------------------\n";
	cout << "Name       : " << User.Name << endl;
	cout << "Passward   : " << User.Password << endl;
	cout << "Primission : " << User.Permission << endl;
	cout << "----------------------------------------\n";
}

bool MarkUserForDeleting(vector <stUser>& vUsers, string Username)
{
	for (stUser& U : vUsers)
	{
		if (U.Name == Username)
		{
			U.FlagForDelete = true;
			return true;
		}
	}
	return false;
}

bool DeleteUserByUsername(vector <stUser> vUsers, string Username)
{
	stUser User;
	char Answer = 'y';

	if (FindUserByUsername(vUsers,Username,User))
	{
		PrintUserCard(User);

		cout << "\n\nAre you sure you want delete this user? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkUserForDeleting(vUsers, Username);
			SaveDataUserToFile(vUsers, UserFileName);

			vUsers = LoadUsersDataFromFile(UserFileName);

			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
	}

	else
	{
		cout << "\nUser with Username (" << Username << ") is Not Found!";
		return false;
	}

}

void ShowDeleteUserScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDelete User Screen";
	cout << "\n---------------------------------\n";

	vector <stUser> vUsers = LoadUsersDataFromFile(UserFileName);
	string Username = ReadUsername();

	DeleteUserByUsername(vUsers, Username);
}

stUser ChangeUserRecord(string Username)
{
	stUser User;
	User.Name = Username;

	cout << "\nEnter Password? ";
	cin >> User.Password;

	User.Permission = ReadPermissionToSet();
	
	return User;
}

bool UpdateUserByUsername(vector<stUser>& vUsers, string Username)
{
	stUser User;
	char Answer = 'y';

	if (FindUserByUsername(vUsers, Username, User))
	{
		PrintUserCard(User);

		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			stUser User = ChangeUserRecord(Username);

			for (stUser& U : vUsers)
			{
				if (U.Name == Username)
				{
					U = User;
					break;
				}
			}
			SaveDataUserToFile(vUsers, UserFileName);

			cout << "\n\nUser Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << Username << ") is Not Found!";
		return false;
	}
}

void ShowUpdateUserScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDelete User Screen";
	cout << "\n---------------------------------\n";

	vector<stUser> vUsers = LoadUsersDataFromFile(UserFileName);
	string Username = ReadUsername();

	UpdateUserByUsername(vUsers, Username);
}

void ShowFindUserScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tFind User Screen";
	cout << "\n---------------------------------\n";

	vector <stUser> vUsers = LoadUsersDataFromFile(UserFileName);
	string Username = ReadUsername();

	stUser User;

	if (FindUserByUsername(vUsers, Username, User))
	{
		PrintUserCard(User);
	}
	else
	{
		cout << "\n\nUser with Username (" << Username << ") is Not Found!.";
	}

}

void PerformeMangeUsersMeneuOption(enMangeUsersMenueOptions ManageUsers)
{
	switch (ManageUsers)
	{

	case enListUsers:
		system("cls");
		ShowAllUsersScreen();
		GoBackToMangeMenueScreen();
		break;

	case enAddNewUser:
		system("cls");
		ShowAddNewUsersScreen();
		GoBackToMangeMenueScreen();
		break;

	case enDeleteUser:
		system("cls");
		ShowDeleteUserScreen();
		GoBackToMangeMenueScreen();
		break;

	case enUpdateUser:
		system("cls");
		ShowUpdateUserScreen();
		GoBackToMangeMenueScreen();
		break;

	case enFindUser:
		system("cls");
		ShowFindUserScreen();
		GoBackToMangeMenueScreen();
		break;

	case enMainMenue:
		system("cls");
		ShowMeanMenu();
		break;

	}
}

void ShowManageUsersMenueScreen()
{
	if (!CheckAccessPermission(enMainMenuePermission::pManager))
	{
		ShowAccessDeniedMessage();
		GoBackToMainMenu();
		return;
	}

	system("cls");

	cout << "===============================================\n";
	cout << "\t\tManage Users Menue Screen";
	cout << "\n===============================================\n";

	cout << "\t[1] List Users." << endl;
	cout << "\t[2] Add New User." << endl;
	cout << "\t[3] Delete User." << endl;
	cout << "\t[4] Update User." << endl;
	cout << "\t[5] Find User." << endl;
	cout << "\t[6] Main Menue." << endl;

	cout << "===============================================\n";

	PerformeMangeUsersMeneuOption((enMangeUsersMenueOptions)ReadMangeUsersMenueOption());	
}

bool LoadUserInfo(string Username, string Password)
{
	if (FineUserByUsernameAndPassword(Username, Password, UserCurrent))
		return true;

	else
		return false;
}

void Login()
{
	bool LoginFailed = false;
	string Username, Password;

	do
	{
		system("cls");

		cout << "\n---------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n---------------------------------\n";

		if (LoginFailed)
		{
			cout << "Invlaid Username/Password!\n";
		}

		cout << "Enter Username? ";
		getline(cin >> ws, Username);

		cout << "Enter Password? ";
		getline(cin, Password);

		LoginFailed = !LoadUserInfo(Username, Password);

	} while (LoginFailed);

	ShowMeanMenu();
}




int main()
{
	Login();

	system("pause>0");

	return 0;
}