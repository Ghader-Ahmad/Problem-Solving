
#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Please enter PIN Code?" << endl;
	cin >> PinCode;

	return PinCode;
}

bool Login()
{
	string PinCode;
	int counter = 3;
	do
	{
		counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F");
			cout << "\nWrong Pin, You have " << counter << " more tries" << endl;
		}
	} while (counter >= 1 && PinCode != "1234");
	return 0;
}

int main()
{
	if (Login())
	{
		cout << "Your Balance is : " << 7500 << endl;
		system("color 2F");
    }
	else
	{
		cout << "\nYour Card Blocked call the bank for help.\n";
	}

	return 0;
}


