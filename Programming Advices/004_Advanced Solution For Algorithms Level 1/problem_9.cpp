

#include <iostream>
using namespace std;

void ReadNum(int& num1, int& num2, int& num3)
{
    cout << "Please enter a number 1 ?\n";
    cin >> num1;

    cout << "Please enter a number 2 ?\n";
    cin >> num2;

    cout << "Please enter a number 3 ?\n";
    cin >> num3;
}

int SumOf3Number(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

void PrintResult(int Total)
{
    cout << "Sum of three numbers is " << Total << endl;
}

int main()
{
    int num1, num2, num3;

    ReadNum(num1, num2, num3);

    PrintResult(SumOf3Number(num1, num2, num3));

    return 0;
}

