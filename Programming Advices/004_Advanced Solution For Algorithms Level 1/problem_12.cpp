
#include <string>
#include <iostream>
using namespace std;

void ReadNumbers(int& num1, int& num2)
{
    cout << "Please enter num1?\n";
    cin >> num1;

    cout << "Please enter num2?\n";
    cin >> num2;
}

int MaxOf2Numbers(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}

void PrintResultsint (int Max)
{
    cout << "Max number is : " << Max << endl;
}

int main()
{
    int num1, num2;

    ReadNumbers(num1, num2);

    PrintResultsint(MaxOf2Numbers(num1, num2));

    return 0;
}

