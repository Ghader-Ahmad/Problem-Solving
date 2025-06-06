#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime = 1 , NotPrime = 2 };

int RandomNumber(int From, int To)
{
    int RandNumber = rand() % (To - From + 1) + From;
    return RandNumber;
}

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i < M; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "\nPlease enter a number of elements ?\n";
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
    cout << endl;;
}

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CopyPrimeNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arrLDestination)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddArrayElements(arrSource[i], arrDestination, arrLDestination);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;
    FillArrayWithRandomNumber(arr, arrLength);

    int arr2[100], arr2Length = 0;
    CopyPrimeNumber(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements :\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Prime number :\n";
    PrintArray(arr2, arr2Length);

    return 0;
}


