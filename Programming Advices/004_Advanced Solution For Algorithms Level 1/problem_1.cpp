
#include <iostream>
using namespace std;

int PrintName(string name)
{
    int number = 0;
    cin >> number;
    int fact = 1;
    for (int i = number; i >= 1; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    cout<<PrintName("Ghader");
    
    return 0;
}

