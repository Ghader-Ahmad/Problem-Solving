
#include <iostream>
using namespace std;

enum enPassFail {Pass=1, Fail=2};

void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
    cout << "Please enter Mark1?\n";
    cin >> Mark1;

    cout << "Please enter Mark2?\n";
    cin >> Mark2;

    cout << "Please enter Mark3?\n";
    cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMarks(int Mark1, int Mark2, int Mark3)
{
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckMarks(float Average)
{
    if (Average >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintResult(float Average)
{
    cout << "Average is : " << Average << endl;
    if (CheckMarks(Average) == enPassFail::Pass)
        cout << "Pass\n";
    else
        cout << "Fail\n";
}

int main()
{
    int Mark1, Mark2, Mark3;

    ReadMarks(Mark1, Mark2, Mark3);

    PrintResult(CalculateAverageMarks(Mark1, Mark2, Mark3));

    return 0;
    
}