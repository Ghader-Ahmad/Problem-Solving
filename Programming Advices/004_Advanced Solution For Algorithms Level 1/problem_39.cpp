#include <string>
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;

    return Number;
}

float CalculateRemainder(float TotalBill, float TotalCachPaid)
{
    float Remainder;
    Remainder = TotalCachPaid - TotalBill;

    return Remainder;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Please enter Total Bill ?\n");
    float TotalCachPaid = ReadPositiveNumber("Please enter Total Cach Paid?\n");

    cout << endl;
    cout << "Total Bill = " << TotalBill << endl;
    cout << "Total Cach Paid = " << TotalCachPaid << endl;

    cout << "*************************\n";
    cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCachPaid) << endl;

    return 0;
}
