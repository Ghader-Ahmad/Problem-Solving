#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int RandomNumber(int From, int To)
{
    int RandNumber = rand() % (To - From + 1) + From;
    return RandNumber;
}

void FillArrayWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d    ", 2, arr[i][j]);
        }
        cout << "\n";
    }
}

void PrintMiddleRow(int arr[3][3], short Rows, short Cols)
{
    short MidRow = Rows / 2;
    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d    ", 2, arr[MidRow][j]);
    }
}

void PrintMiddleCol(int arr[3][3], short Rows, short Cols)
{
    short MidCol = Cols / 2;
    for (short i = 0; i < Rows; i++)
    {
        printf(" %0*d    ", 2, arr[i][MidCol]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
                                                        
    FillArrayWithRandomNumber(arr, 3, 3);
    cout << "\nMatrix :\n";
    PrintMatrix(arr, 3, 3);

    cout << "\n\nMiddle Row of Matrix is :\n";
    PrintMiddleRow(arr, 3, 3);

    cout << "\n\nMiddle Col of Matrix is :\n";
    PrintMiddleCol(arr, 3, 3);

    return 0;
}
