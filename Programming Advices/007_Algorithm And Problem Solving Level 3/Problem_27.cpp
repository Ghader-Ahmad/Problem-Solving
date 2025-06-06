#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadCharacter()
{
	char c;
	cout << "Please enter your character ? \n";
	cin >> c;
	return c;
}

char InvertLetterCase(char c)
{
	return islower(c) ? toupper(c) : tolower(c);

}

int main()
{
	char c = ReadCharacter();

	cout << "\n\nChar after inverting case : \n" << InvertLetterCase(c) << endl;

	return 0;
}