#include <string>
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);
	return Number;
}

float TotalMonth(float LoanAmount, float MonthlyInstallment)
{
	return (float)LoanAmount / MonthlyInstallment;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter Loan Amount?");
	float MonthlyInstallment = ReadPositiveNumber("Please enter Monthly Installment?");

	cout << "\nTotal Month to pay = " << TotalMonth(LoanAmount, MonthlyInstallment) << endl;

	return 0;
}

