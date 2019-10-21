#include <iostream>
using namespace std;

int main()
{
    int hours, minutes, startingMonth, days, months = 0;
    int hoursToMinutes;
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter starting month: ";
    cin >> startingMonth;
    hoursToMinutes = hours * 60;
    minutes += hoursToMinutes;

    if (minutes <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        hours = minutes / 60;
        minutes %= 60;
        days = hours / 24;
        hours %= 24;

        if (days > 31 && startingMonth == 1 || startingMonth == 3 || startingMonth == 5 || startingMonth == 7 || startingMonth == 8 || startingMonth == 10 || startingMonth == 12)
        {
            months = 1;
            days %= 31;
        }
        else if (days > 30 && startingMonth == 4 || startingMonth == 6 || startingMonth == 9 || startingMonth == 11)
        {
            months = 1;
            days %= 30;
        }
        else
        {
            months = 1;
            days %= 28;
        }

        cout << "It has been: "
             << months << " months, "
             << days << " days, "
             << hours << " hours and "
             << minutes << " minutes!" << endl;
    }

    return 0;
}