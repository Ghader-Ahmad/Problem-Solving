#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S;
    cout << "Please Enter Your String ?\n";
    getline(cin, S);
    return S;
}

bool IsVowel(char Ch)
{
    Ch = tolower(Ch);
    return ((Ch == 'e') || (Ch == 'o') || (Ch == 'i') || (Ch == 'u') || (Ch == 'a'));
}

void PrintVowelsInString(string S)
{
    cout << "\n\nVowel in string are : ";
    for (short i = 0; i < S.length(); i++)
    {
        if (IsVowel(S[i]))
        {
            cout << S[i] << "     ";
        }
    }
    cout << endl;
}

int main()
{
    string S = ReadString();

    PrintVowelsInString(S);

    return 0;
}