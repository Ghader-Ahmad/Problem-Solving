
#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please enter a number?\n";
    cin >> N;

    return N;
}

void PrintRangeFromNTo1_UsingWhile(int N)
{
    cout << "\nRange printed Using while statment: \n";
    int i = N;
    while (i >= 1)
    {
        cout << i << endl;
        i--;
    }

}

void PrintRangeFromNTo1_UsingDoWhile(int N)
{
    cout << "\nRange printed Using do while statment: \n";
    int i = N;
    do
    {
        cout << i << endl;
        i--;
    } while (i >= 1);
}

void PrintRangeFromNTo1_UsingFor(int N)
{
    cout << "\nRange printed Using for statment: \n";
    for (int i = N; i >= 1; i--)
    {
        cout << i << endl;
    }
}

int main()
{
    int N = ReadNumber();

    PrintRangeFromNTo1_UsingWhile(N);
    PrintRangeFromNTo1_UsingDoWhile(N);
    PrintRangeFromNTo1_UsingFor(N);

    return 0;
}

