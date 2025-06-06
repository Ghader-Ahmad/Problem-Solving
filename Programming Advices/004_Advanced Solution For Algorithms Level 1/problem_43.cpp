#include <string>
#include <iostream>
using namespace std;

struct stTaskDuration
{
    int NumberOfDay, NumberOfHour, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    stTaskDuration TaskDuration;
    float Remainder=0;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHours = 60 * 60;
    const int SecondsPerMinutes = 60;

    TaskDuration.NumberOfDay = floor(TotalSeconds / SecondsPerDay);
    Remainder = TotalSeconds % SecondsPerDay;

    TaskDuration.NumberOfHour = floor(Remainder / SecondsPerHours);
    Remainder = TotalSeconds % SecondsPerHours;

    TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinutes);
    Remainder = TotalSeconds % SecondsPerMinutes;

    TaskDuration.NumberOfSeconds = Remainder;

    return TaskDuration;
}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
    cout << TaskDuration.NumberOfDay << " : " << TaskDuration.NumberOfHour << " : " << TaskDuration.NumberOfMinutes
        << " : " << TaskDuration.NumberOfSeconds << endl;
}

int main()
{
    int TotalSeconds = ReadPositiveNumber("Please enter Total Seconds?\n");

    PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));

    return 0;
}
