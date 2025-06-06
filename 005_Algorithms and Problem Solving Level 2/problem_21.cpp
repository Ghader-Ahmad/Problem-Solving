#include <cstdlib>
#include <iostream>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpicialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNumber = 0;
	RandNumber = rand() % +(To - From + 1) + From;

	return RandNumber;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enCharType::SpicialCharacter:
		return char(RandomNumber(33, 47));
		break;

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;
	}
}

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

string GenerateWord(enCharType CharType, short Length)
{
	string word = "";
	for (int i = 1; i <= Length; i++)
	{
		word += GetRandomCharacter(CharType);
	}

	return word;
}

string GenerateKey()
{
	string Key = "";

	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}

void GenerateKeys(int Number)
{
	cout << endl;
	for (int i = 1; i <= Number; i++)
	{
		cout << "Key [" << i << "] : ";
		cout << GenerateKey() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Please enter How many keys to generate ?"));

	return 0;
}

