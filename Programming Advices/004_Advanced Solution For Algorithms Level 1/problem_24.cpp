
#include <iostream>
using namespace std;

int ReadAge()
{
    int Age;
    cout << "Please enter your age?\n";
    cin >> Age;

    return Age;
}

bool ValiadateNumberInRange(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}

void PrintResult(int Age)
{
    if (ValiadateNumberInRange(Age, 18, 45))
        cout << Age << " is valid age\n";
    else
        cout << Age << " is  invalid age\n";
}

int main()
{
    PrintResult(ReadAge());

    return 0;
}

