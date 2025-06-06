#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNumber = rand() % (To - From + 1) + From;
    return RandNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "\nPlease enter a number of elements : \n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int PositiveCount(int arr[100], int arrLength)
{
    int Count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
        {
            Count++;
        }
    }
    return Count;
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;

    FillArrayWithRandomNumber(arr, arrLength);

    cout << "\nArray elements : ";
    PrintArray(arr, arrLength);

    cout << "\nPositive Numbers count is : ";
    cout<< PositiveCount(arr, arrLength) << endl;

    return 0;
}


