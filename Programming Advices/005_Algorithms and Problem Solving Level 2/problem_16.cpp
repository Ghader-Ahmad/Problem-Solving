#include <iostream>
using namespace std;

void PrintWordsAAAToZZZ()
{
	cout << "\n";
	string Word = " ";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int z = 65; z <= 90; z++)
			{
				Word = Word + char(i);
				Word = Word + char(j);
				Word = Word + char(z);

				cout << Word << endl;
				Word = " ";
			}
		}
	}
}

int main()
{
	PrintWordsAAAToZZZ();

	return 0;
}