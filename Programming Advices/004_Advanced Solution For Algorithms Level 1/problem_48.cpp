#include <string>
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);
	return Number;
}

float MonthlyInstallment(float LoanAmount, float HowManyMonth)
{
	return (float)LoanAmount / HowManyMonth;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter Loan Amount?");
	float HowManyMonth = ReadPositiveNumber("How Many Months you need to settle the loan ?");

	cout << "\nMonthly Installment amount = " << MonthlyInstallment(LoanAmount, HowManyMonth);
	cout << endl;

	return 0;
}

