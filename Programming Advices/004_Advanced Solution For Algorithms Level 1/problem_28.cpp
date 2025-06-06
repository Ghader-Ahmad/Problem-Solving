
#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please enter a number?\n";
    cin >> N;

    return N;
}

enum enOddEven {Odd = 1, Even = 2 };

enOddEven CheckOddOrEven(int Number)
{
    if (Number % 2 == 0)
        return enOddEven::Even;
    else
        return enOddEven::Odd;
}

int SumOddNumberFrom1ToN_UsingWhile(int N)
{
    cout << "\nSum Odd Number From 1 To N Using While :" << endl;

    int sum = 0;
    int counter = 1;
    while (counter <= N)
    {
        if (CheckOddOrEven(counter) == enOddEven::Odd)
        {
            sum += counter;
        }
        counter++;
    }
    return sum;
}

int SumOddNumberFrom1ToN_UsingDoWhile(int N)
{
    cout << "\nSum Odd Number From 1 To N Using Do While :" << endl;

    int counter = 1;
    int sum = 0;
    do
    {
        if (CheckOddOrEven(counter) == enOddEven::Odd)
        {
            sum += counter;
        }
        counter++;
    } while (counter <= N);
    return sum;
}

int SumOddNumberFrom1ToN_Usingfor(int N)
{
    cout << "\nSum Odd Number From 1 To N Using for :" << endl;

    int sum = 0;
    for (int counter = 1; counter <= N; counter++)
    {
        if (CheckOddOrEven(counter) == enOddEven::Odd)
        {
            sum += counter;
        }
    }
    return sum;
}

int main()
{
    int N;
    N = ReadNumber();

    cout << SumOddNumberFrom1ToN_UsingWhile(N) << endl;
    cout << SumOddNumberFrom1ToN_UsingDoWhile(N) << endl;
    cout << SumOddNumberFrom1ToN_Usingfor(N) << endl;

    return 0;
}


