#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
    cout << endl;
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool IsPalindromeArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - i - 1])
        {
            return false;
        }
    }        
    return true;
}

int main()
{
    int arr[100], arrLength = 0;
    FillArray(arr, arrLength);

    cout << "\nArray 1 elements :\n";
    PrintArray(arr, arrLength);

    if (IsPalindromeArray(arr, arrLength))
    {
        cout << "\nYes, array is palindrome \n";
    }
    else
    {
        cout << "\nNo, array is not Palindrome \n";
    }
    return 0;

    
}

