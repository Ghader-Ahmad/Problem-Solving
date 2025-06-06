#include <string>
#include <iostream>
using namespace std;

int ReadTotalSales()
{
    int TotalSales;

    cout << "Please enter Total Sales?\n";
    cin >> TotalSales;

    return TotalSales;
}

float GetCommissionPrecentage(float TotalSales)
{
    if (TotalSales >= 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02;
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0.00;
}

float CalculateTotalComission(float TotalSales)
{
    float TotalComission = GetCommissionPrecentage(TotalSales) * TotalSales;

    return TotalComission;
}

int main()
{
    float TotalSales = ReadTotalSales();

    cout << "Comission Precentage = " << GetCommissionPrecentage(TotalSales) << endl;
    cout << "Total Comission = " << CalculateTotalComission(TotalSales) << endl;
    
    return 0;
}

