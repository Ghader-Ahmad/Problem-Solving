#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string>& vString, string delim)
{
    string S;
    
    for (string& Word : vString)
    {
        S += Word + delim;
    }
    return S.substr(0, S.length() - delim.length());
}

int main()
{
    vector <string> vString = { "Mohammed", "Fadi", "Ali", "Maher", "Maher"};

    cout << "Vector after join : \n";
    cout << JoinString(vString, " @#! ") << endl;

    return 0;
}