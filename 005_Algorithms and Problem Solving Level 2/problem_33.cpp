#include <iostream>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpicialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
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

string GenerateWord(enCharType CharType, int Length)
{
	string word = "";
	for (int i = 0; i < Length; i++)
	{
		word += GetRandomCharacter(CharType);
	}
	return word;
}

string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey();
	}
}

void PrintStringArray(string arr[100], int arrLength)
{
	cout << "\nArray elements :" << endl;
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array [" << i + 1 << "] : ";
		cout << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	int arrLength = 0;
	arrLength = ReadPositiveNumber("How many keys do you want to generate ?\n");

	FillArrayWithKeys(arr, arrLength);

	PrintStringArray(arr, arrLength);
	
	return 0;
   
}
