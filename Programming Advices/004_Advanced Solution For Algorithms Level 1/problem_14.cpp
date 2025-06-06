
#include <string>
#include <iostream>
using namespace std;

void ReadNumbers(int& num1, int& num2)
{
    cout << "Please enter Number 1?\n";
    cin >> num1;

    cout << "Please enter Number 2?\n";
    cin >> num2;
}

void Swap(int& num1, int& num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void PrintNumbers(int num1, int num2)
{
    cout << "\nThe first number: " << num1 << endl;
    cout << "The Second number: " << num2 << endl << endl;
}

int main()
{
    int num1, num2;

    ReadNumbers(num1, num2);

    cout << "\nThe numbers before swap :\n";
    PrintNumbers(num1, num2);

    Swap(num1, num2);

    cout << "\nThe numbers after swap :\n";
    PrintNumbers(num1, num2);

    return 0;
}
