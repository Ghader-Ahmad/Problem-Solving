#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CopyDistinctNumbersToArray(int Sourcearr[100], int Distinationarr[100], int SourceLength, int& DistinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(Sourcearr[i], Distinationarr, DistinationLength))
        {
            AddArrayElements(Sourcearr[i], Distinationarr, DistinationLength);
        }
    }
}

int main()
{
    int arrSource[100], arrDistination[100], SourceLength = 0, DistinationLength = 0;
    FillArray(arrSource, SourceLength);

    CopyDistinctNumbersToArray(arrSource, arrDistination, SourceLength, DistinationLength);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arrSource, SourceLength);

    cout << "\nArray 2 distinct elements :\n";
    PrintArray(arrDistination, DistinationLength);

    return 0;
}