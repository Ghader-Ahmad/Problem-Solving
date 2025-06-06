
#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please enter a number?\n";
    cin >> N;

    return N;
}

void PrintRangeFrom1ToN_UsingWhile(int N)
{
    cout << "\nRange printed Using while statment: \n";
    int i = 1;
    while (i <= N)
    {
        cout << i << endl;
        i++;
    }

}

void PrintRangeFrom1ToN_UsingDoWhile(int N)
{
    cout << "\nRange printed Using do while statment: \n";
    int i = 1;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= N);
}

void PrintRangeFrom1ToN_UsingFor(int N)
{
    cout << "\nRange printed Using for statment: \n";
    for (int  i = 1; i <= N; i++)
    {
        cout << i << endl;
    }
}

int main()
{
    int N = ReadNumber();

    PrintRangeFrom1ToN_UsingWhile(N);
    PrintRangeFrom1ToN_UsingDoWhile(N);
    PrintRangeFrom1ToN_UsingFor(N);

    return 0;
}

