#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNumber = rand() % (To - From + 1) + From;
    return RandNumber;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "\nPlease enter a number of elements :\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
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

int EvenCount(int arr[100], int arrLength)
{
    int Count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
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

    cout << "\nArray elements :\n";
    PrintArray(arr, arrLength);

    cout << "\nEven Numbers count is : ";
    cout << EvenCount(arr, arrLength) << endl;

    return 0;
}

