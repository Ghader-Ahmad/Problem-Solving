#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNumber = rand() % (To - From + 1) + From;
    return RandNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "How many Number of elements ?\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
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

void CopyArrayInReversedOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
  
    for (int i = 0; i <= arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arrLength = 0;

    FillArrayWithRandomNumber(arr1, arrLength);
    int arr2[100];
    CopyArrayInReversedOrder(arr1, arr2, arrLength);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 elements after copying array 1 in reversed order : \n";
    PrintArray(arr2, arrLength);

    return 0;
}


