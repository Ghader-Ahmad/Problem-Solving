
#include <iostream>
using namespace std;

enum enPassFail {Pass=1 , Fail=0};

int ReadMark()
{
    int Mark;

    cout << "Please enter a Mark?\n";
    cin >> Mark;

    return Mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;

    else
        return enPassFail::Fail;
}

void PrintResult(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\nPass\n";

    else
        cout << "\nFail\n";
}

int main()
{
    PrintResult(ReadMark());

    return 0;
}

