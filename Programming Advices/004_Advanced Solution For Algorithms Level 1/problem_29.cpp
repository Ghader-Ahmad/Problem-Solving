
#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please enter a number?\n";
    cin >> N;

    return N;
}

enum enOddEven {Odd = 1 , Even = 2};

enOddEven CheckOddOrEven(int N)
{
    if (N % 2 == 0)
        return enOddEven::Even;
    else
        return enOddEven::Odd;
}

int SumEvenNumberFrom1ToN_UsingWhile(int N)
{
    cout << "\nSum Even Number From 1 To N Using While : " << endl;

    int counter = 1;
    int sum = 0;
    while (counter <= N)
    {
        if (CheckOddOrEven(counter) == enOddEven::Even)
        {
            sum += counter;
        }
        counter++;
    }
    return sum;
}

int SumEvenNumberFrom1ToN_UsingDoWhile(int N)
{
    cout << "\nSum Even Number From 1 To N Using Do While : " << endl;

    int counter = 1;
    int sum = 0;
    do
    {
        if (CheckOddOrEven(counter) == enOddEven::Even)
        {
            sum += counter;
        }
        counter++;
    } while (counter <= N);

    return sum;
}

int SumEvenNumberFrom1ToN_Usingfor(int N)
{
    cout << "\nSum Even Number From 1 To N Using for: " << endl;

    int sum = 0;
    for (int  counter = 0; counter <= N; counter++)
    {
        if (CheckOddOrEven(counter) == enOddEven::Even)
        {
            sum += counter;
        }
    }
    return sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumEvenNumberFrom1ToN_UsingWhile(N) << endl;
    cout << SumEvenNumberFrom1ToN_UsingDoWhile(N) << endl;
    cout << SumEvenNumberFrom1ToN_Usingfor(N) << endl;

    return 0;
}

