
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientFileName = "Client.txt";

enum enATMMainMenueOptions
{
    eQuickWithdraw = 1, eNormalWithdraw = 2,
    eDeposit = 3, eCheckBalance = 4,
    eChangePassword = 5, eShowInformationClient = 6,
    eLogout = 7
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
};

stClient CurrentClient;

void Login();
void ShowATMMainMenueScreen();
void GoBackToATMMainMenueScreen();
void ShowNormalWithdrawScreen();
void ShowQuickWithdrawScreen();

vector <string> SplitString(string S, string delim)
{
    vector<string> vString;
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
    vector <string> vString = SplitString(Line, Seperator);
    stClient Client;

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stod(vString[4]);

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientData;

    stClientData += Client.AccountNumber + Seperator;
    stClientData += Client.PinCode + Seperator;
    stClientData += Client.Name + Seperator;
    stClientData += Client.Phone + Seperator;
    stClientData += to_string(Client.AccountBalance);

    return stClientData;
}

vector <stClient> LoadDateFromFile(string FileName, string Seperator = "#//#")
{
    vector <stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        stClient C;
        string Line;
        while (getline(MyFile, Line))
        {
            C = ConvertLineToRecord(Line);
            vClients.push_back(C);
        }
        MyFile.close();
    }

    return vClients;
}

void SaveDateLineToFile(vector <stClient>& vClients, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (stClient& C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }

        MyFile.close();
    }
}

bool DepositBalanceToClientByAccountNumber(vector <stClient>& vClients, string AccountNumber, double Amount)
{
    char Answer = 'y';

    cout << "\n\nAre you sure you want perform this transaction? y/n? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                cout << "\n\nDone Successfully. New Balance is: " << C.AccountBalance << endl;
                SaveDateLineToFile(vClients, ClientFileName);
                return true;
            }
        }
    }
    return false;
}

short getQuickWithdrawAmount(short QuickWithdrawOption)
{
    switch (QuickWithdrawOption)
    {
    case 1:
        return 20;

    case 2:
        return 50;

    case 3:
        return 100;

    case 4:
        return 200;

    case 5:
        return 400;

    case 6:
        return 600;

    case 7:
        return 800;

    case 8:
        return 1000;

    }
}

void PerformeQuickWithdrawOptions(short QuickWithdrawOption)
{

    if (QuickWithdrawOption == 9)
        return;

    short WithDrawBalance = getQuickWithdrawAmount(QuickWithdrawOption);

    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe Amount exceeds your balance, make another choice.\n";
        cout << "press any key to continur...";
        system("pause>0");
        ShowQuickWithdrawScreen();
        return;
    }


    vector <stClient> vClients = LoadDateFromFile(ClientFileName);
    DepositBalanceToClientByAccountNumber(vClients, CurrentClient.AccountNumber, WithDrawBalance * -1);
    CurrentClient.AccountBalance -= WithDrawBalance;
}

short ReadQuickWithdrawOption()
{
    short Choose = 0;

    while (Choose < 1 || Choose > 9)
    {
        cout << "Choose what to do withdraw from [1] to [9]? ";
        cin >> Choose;
    }

    return Choose;
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "=============================================\n";

    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";

    cout << "=============================================\n";

    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;


    PerformeQuickWithdrawOptions(ReadQuickWithdrawOption());
}

int ReadWithDrawAmount()
{
    int Amount = 0;
    cout << "\nEnter an amount multiple of 5's ? ";
    cin >> Amount;

    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    }
    return Amount;

}

void PerformNormalWithDrawOption()
{
    int WithDrawBalance = ReadWithDrawAmount();

    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe Amount exceeds your balance, make another choice.\n";
        cout << "press any key to continur...";
        system("pause>0");
        ShowNormalWithdrawScreen();
        return;
    }

    vector <stClient> vClients = LoadDateFromFile(ClientFileName);
    DepositBalanceToClientByAccountNumber(vClients, CurrentClient.AccountNumber, WithDrawBalance * -1);
    CurrentClient.AccountBalance -= WithDrawBalance;
}

void ShowNormalWithdrawScreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "=============================================\n";

    PerformNormalWithDrawOption();
}

double ReadDepositAmount()
{
    double Amount = 0;
    cout << "\nEnter a positive Deposit Amount? ";
    cin >> Amount;

    while (Amount <= 0)
    {
        cout << "\nEnter a positive Deposit Amount? ";
        cin >> Amount;
    }
    return Amount;
}

void PerformDepositScreen()
{
    double DepositAmount = ReadDepositAmount();

    vector<stClient> vClients = LoadDateFromFile(ClientFileName);
    DepositBalanceToClientByAccountNumber(vClients, CurrentClient.AccountNumber, DepositAmount);
    CurrentClient.AccountBalance += DepositAmount;
}

void ShowDepositScreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "=============================================\n";

    PerformDepositScreen();
}

void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "=============================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;

}

string ReadNewPassward()
{
    string Passward;
    cout << "\nPlase Enter a new passward? ";
    cin >> Passward;

    return Passward;
}

void PerformChangePasswardOption()
{
    string Passward = ReadNewPassward();
    vector <stClient> vClients = LoadDateFromFile(ClientFileName);
    CurrentClient.PinCode = Passward;

    for (stClient& C : vClients)
    {
        if (C.AccountNumber == CurrentClient.AccountNumber)
        {
            C.PinCode = Passward;
            SaveDateLineToFile(vClients, ClientFileName);
            break;
        }
    }

}

void ShowChangePasswardSecreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tChange Passward Screen\n";
    cout << "=============================================\n";
    PerformChangePasswardOption();

}

void ShowInformationClientScreen()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\tShow Information Client Screen\n";
    cout << "=============================================\n";

    cout << "\nAccount Number  : " << CurrentClient.AccountNumber;
    cout << "\nPin Code        : " << CurrentClient.PinCode;
    cout << "\nName            : " << CurrentClient.Name;
    cout << "\nPhone           : " << CurrentClient.Phone;
    cout << "\nAccount Balance : " << CurrentClient.AccountBalance;

    cout << "\n=============================================\n\n";

}

void PerformeATMMainMenueOptions(enATMMainMenueOptions ATMMainMenue)
{
    switch (ATMMainMenue)
    {
    case enATMMainMenueOptions::eQuickWithdraw:
        system("cls");
        ShowQuickWithdrawScreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eNormalWithdraw:
        system("cls");
        ShowNormalWithdrawScreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eCheckBalance:
        system("cls");
        ShowCheckBalanceScreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eChangePassword:
        system("cls");
        ShowChangePasswardSecreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eShowInformationClient:
        system("cls");
        ShowInformationClientScreen();
        GoBackToATMMainMenueScreen();
        break;

    case enATMMainMenueOptions::eLogout:
        Login();
        break;
    }
}

void GoBackToATMMainMenueScreen()
{
    cout << "\nPress any key to go back to Main Menue...\n";
    system("pause>0");
    ShowATMMainMenueScreen();
}

short ReadATMMainMenueOption()
{
    short Choose = 0;
    cout << "Choose what do you want to do? [1 to 7]? ";
    cin >> Choose;
    return Choose;
}

void ShowATMMainMenueScreen()
{
    system("cls");

    cout << "=============================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "=============================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdarw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Change Password.\n";
    cout << "\t[6] Show Information Client.\n";
    cout << "\t[7] Logout.\n";
    cout << "=============================================\n";

    PerformeATMMainMenueOptions((enATMMainMenueOptions)ReadATMMainMenueOption());
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
    vector <stClient> vClients = LoadDateFromFile(ClientFileName);

    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;

    else
        return false;
}

void Login()
{
    bool LoginFalied = false;

    string AccountNumber, PinCode;

    do
    {
        system("cls");
        cout << "\n-----------------------------------------\n";
        cout << "\t\tLogin Screen\n";
        cout << "-----------------------------------------\n";

        if (LoginFalied)
        {
            cout << "Invlaid Account Number/PinCode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFalied = !LoadClientInfo(AccountNumber, PinCode);


    } while (LoginFalied);

    ShowATMMainMenueScreen();

}

int main()
{
    Login();

    return 0;
}
