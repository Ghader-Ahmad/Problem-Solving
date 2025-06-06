#include <string>
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < 0);
    

    return Number;
}

float CalculateTotalBillAfterServicesAndTax(float BillValue)
{
    float TotalBill;

    TotalBill = BillValue * 1.1;
    TotalBill = TotalBill * 1.16;

    return TotalBill;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Please enter Total Bill?\n");

    cout << endl;

    cout << "Total Bill = " << TotalBill << endl;
    cout << "Total Bill After Services Fee And Sales Tax = " <<
        CalculateTotalBillAfterServicesAndTax(TotalBill) << endl;

    return 0;
}

