#include <iostream>
#include<string>
using namespace std;

struct stClientData
{
    string AccountNumber;
    string PinCde;
    string Name;
    string Phone;
    double AccountBalance = 0;
};

stClientData ReadNewClient()
{
    stClientData ClientData;

    cout << "Enter Account Number? ";
    getline(cin, ClientData.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, ClientData.PinCde);
    cout << "Enter Name? ";
    getline(cin, ClientData.Name);
    cout << "Enter Phone? ";
    getline(cin, ClientData.Phone);
    cout << "Enter AccountBalance? ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

string ConvertRecordToLine(stClientData ClientData, string Separator = "#//#")
{
    string stClientRecord;

    stClientRecord += ClientData.AccountNumber + Separator;
    stClientRecord += ClientData.PinCde + Separator;
    stClientRecord += ClientData.Name + Separator;
    stClientRecord += ClientData.Phone + Separator;
    stClientRecord += to_string(ClientData.AccountBalance);

    return stClientRecord;
}

int main()
{
    cout << "Please Enter Client Data: \n\n";

    stClientData ClientData = ReadNewClient();

    cout << "\n\nClient Record for Saving is:\n";
    cout << ConvertRecordToLine(ClientData) << endl;

    return 0;
}