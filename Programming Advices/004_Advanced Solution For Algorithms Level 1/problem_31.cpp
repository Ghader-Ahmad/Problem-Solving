
#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Please enter a Number?\n";
    cin >> Number;

    return Number;
}

void PowOf2_3_4(int Number)
{
    int a, b, c;
    
    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;

    cout << a << " " << b << " " << c << endl;
}

int main()
{
    PowOf2_3_4(ReadNumber());

    return 0;
}

