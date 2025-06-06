#include <string>
#include <iostream>
using namespace std;

int ReadNumber()
{
    int num;
    cout << "Please enter a number?\n";
    cin >> num;

    return num;
}

float CalculateHalfNumber(int num)
{
    return (float)num / 2;
}

void PrintReuslts(int num)
{
    string Result = "Half of " + to_string(num) + " is " + to_string(CalculateHalfNumber(num));

    cout << endl << Result << endl;
}

int main()
{
    PrintReuslts(ReadNumber());

    return 0;
}

