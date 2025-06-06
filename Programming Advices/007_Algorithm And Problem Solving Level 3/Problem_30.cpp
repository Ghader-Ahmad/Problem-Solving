#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S;
    cout << "Please Enter Your String ? \n";
    getline(cin, S);
    return S;
}

char ReadCharacter()
{
    char c;
    cout << "\nPlease Enter a Character ?\n";
    cin >> c;
    return c;
}

short CounterOfCharacterInString(string S, char Letter)
{
    short Counter = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == Letter)
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadCharacter();

    cout << "\n\nLetter \'" << Ch1 << "\' Count = " << CounterOfCharacterInString(S1, Ch1) << endl;
    system("pause>0");
    return 0;
}