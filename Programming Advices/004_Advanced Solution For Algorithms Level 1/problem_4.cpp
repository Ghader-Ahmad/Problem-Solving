#include <iostream>
using namespace std;

struct stInfo
{
    int Age = 0;
    bool HasDriverLicense;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "\nPlease enter your age?\n";
    cin >> Info.Age;
    cout << "\nDo You have driver license?\n";
    cin >> Info.HasDriverLicense;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintResults(stInfo Info)
{
    if (IsAccepted(Info))
    {
        cout << "\nHired\n";
    }
    else
    {
        cout << "\nRejected\n";
    }
}

int main()
{
    PrintResults(ReadInfo());

    return 0;
}

