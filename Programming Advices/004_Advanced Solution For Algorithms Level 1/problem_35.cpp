#include <string>
#include <iostream>

using namespace std;

struct stPigguBankContenet
{
    int Penny;
    int Nickels;
    int Dime;
    int Quarters;
    int Dollars;
};

stPigguBankContenet ReadPigguBankContenet()
{
    stPigguBankContenet PigguBankContenet;

    cout << "Please enter a Total Penny?\n";
    cin >> PigguBankContenet.Penny;

    cout << "Please enter a Total Nickels?\n";
    cin >> PigguBankContenet.Nickels;

    cout << "Please enter a Total Dime?\n";
    cin >> PigguBankContenet.Dime;

    cout << "Please enter a Total Quarters?\n";
    cin >> PigguBankContenet.Quarters;

    cout << "Please enter a Total Dollars?\n";
    cin >> PigguBankContenet.Dollars;

    return PigguBankContenet;
}

int CalculateTotalPennies(stPigguBankContenet PigguBankContenet)
{
    int  TotalPennies = 0;
    TotalPennies = PigguBankContenet.Penny * 1 + PigguBankContenet.Nickels * 5 + PigguBankContenet.Dime * 10
        + PigguBankContenet.Quarters * 25 + PigguBankContenet.Dollars * 100;

    return TotalPennies;
}

int main()
{
    int TotalPennies = CalculateTotalPennies(ReadPigguBankContenet());

    cout << endl << "Total Pennies = " << TotalPennies << endl;
    cout << endl << "Total Dollars = " << (float)TotalPennies / 100 << endl;

    return 0;
}

