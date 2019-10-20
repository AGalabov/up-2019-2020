#include <iostream>
using namespace std;

int main()
{
    int hh, mm;
    cout << "Enter number of hours: ";
    cin >> hh;
    cout << "Enter number of minutes: ";
    cin >> mm;

    int formattedMinutes = mm % 60;
    hh += mm / 60; // this is the same as: hh = hh + (mm / 60)

    int formattedHours = hh % 24;
    int formattedDays = hh / 24;

    cout << formattedDays << " days "
         << formattedHours << " hours "
         << formattedMinutes << " minutes\n"; //Note: "\n" is the same as endl100

    return 0;
}