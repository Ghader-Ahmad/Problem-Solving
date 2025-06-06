
#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDriverLicense;
    bool HasRecommendation;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please enter your Age?\n";
    cin >> Info.Age;

    cout << "Do you have a driver license?\n";
    cin >> Info.HasDriverLicense;

    cout << "Do you have a Recommendation?\n";
    cin >> Info.HasRecommendation;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
        return (Info.Age > 21 && Info.HasDriverLicense);
    }
}

void PrintResult(stInfo Info)
{
    if (IsAccepted(Info))
    {
        cout << "\nHired";
    }
    else
    {
        cout << "\nRejected";
    }
}


int main()
{
    PrintResult(ReadInfo());

    return 0;
}


