#include <string>
#include <iostream>
using namespace std;

string ReadPinCode()
{
    string PinCode;
    cout << "Please enter PIN Code?\n";
    cin >> PinCode;

    return PinCode;
}

bool Login()
{
    string PinCode;

    do
    {
        PinCode = ReadPinCode();
        if (PinCode == "1234")
        {
            return 1;
        }
        else
        {
            cout << "Wring Pin!" << endl;
            system("color 4F");
        }

    } while (PinCode != "1234");

    return 0;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour Balance is : " << 7500 << endl;
    }

    return 0;
}

