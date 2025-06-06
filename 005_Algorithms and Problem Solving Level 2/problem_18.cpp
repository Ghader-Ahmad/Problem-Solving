#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
	string Text;
	cout << "Please enter a Text?\n";
	getline(cin,Text);

	return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char(int(Text[i]) + EncryptionKey);
	}

	return Text;
}

string DescryptText(string Text, short EncryptionKey)
{

	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char(int(Text[i]) - EncryptionKey);
	}

	return Text;
}

int main()
{
	const short EncryptionKey = 2;
	string Text = ReadText();
	string TextAfterEncryption = EncryptText(Text, EncryptionKey);
	string TextAfterDescryption = DescryptText(TextAfterEncryption, EncryptionKey);

	cout << "\nText Befor Encryption : " << Text << endl;
	cout << "\nText After Encryption : " << TextAfterEncryption << endl;
	cout << "\nText After Descryption : " << TextAfterDescryption << endl;

	return 0;
}