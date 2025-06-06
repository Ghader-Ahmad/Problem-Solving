
#include <iostream>
using namespace std;

struct stInfo
{
    string firstname;
    string lastname;
};

stInfo ReadName()
{
    stInfo Info;

    cout << "Please enter first name?\n";
    cin >> Info.firstname;

    cout << "Please enter last name?\n";
    cin >> Info.lastname;

    return Info;
}

string GetFullName(stInfo Info, bool Reversed)
{
    string FullName = "";

    if (Reversed)
        FullName = Info.lastname + " " + Info.firstname;

    else
        FullName = Info.firstname + " " + Info.lastname;

    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\nYour Full Name is : " << FullName << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadName(),false));

    return 0;
}

