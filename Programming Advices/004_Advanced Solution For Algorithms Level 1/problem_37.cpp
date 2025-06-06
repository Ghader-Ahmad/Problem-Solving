#include <string>
#include <iostream>
using namespace std;

float ReadNumber(string Message)
{
    int Number;
    cout << Message << endl;
    cin >> Number;

    return Number;
}

float SumNumbers()
{
    int sum = 0, Number = 0, counter = 1;

    do
    {
        Number = ReadNumber("Please enter number " + to_string(counter));
        if (Number == -99)
        {
            break;
        }
        sum += Number;
        counter++;
    } while (Number != -99);

    return sum; 
}

int main()
{
    cout << endl << "Result = " << SumNumbers() << endl;

    return 0;
}

