
#include <iostream>
using namespace std;

string ReadPassword()
{
    string Password;
    cout << "Please enter a 3-letter Password (all capital) ?" << endl;
    cin >> Password;

    return Password;
}

bool GuessPassword(string OrginalPassword)
{
    cout << "\n";
    string word = "";
    int counter = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                
                counter++;
                cout << "Trial ["<< counter << "] : " << word << endl;
                if (word == OrginalPassword)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found after " << counter << " Trial(s)\n";
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}

int main()
{
    GuessPassword(ReadPassword());

    return 0;
}
