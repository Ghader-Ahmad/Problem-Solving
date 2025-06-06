#include <string>
#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B, int& C)
{
    cout << "Please enter number A?\n";
    cin >> A;

    cout << "Please enter number B?\n";
    cin >> B;

    cout << "Please enter number C?\n";
    cin >> C;
}

int Maxof3Numbers(int A, int B, int C)
{
    if (A > B)
        if (A > C)
            return A;
        else
            return C;
    else
        if (B > C)
            return B;
        else
            return C;
}

void PrintRuselts(int Max)
{
    cout << "Max number is : " << Max << endl;
}

int main()
{
    int A, B, C;

    ReadNumbers(A, B, C);

    PrintRuselts(Maxof3Numbers(A, B, C));

    return 0;
}