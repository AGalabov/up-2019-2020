#include <iostream>
using namespace std;

int main()
{
    int year, CURRENT_YEAR = 2019;
    cout << "Enter a positive number - year: ";
    cin >> year;

    bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

    if (isLeapYear)
    {
        if (year < 2019)
            cout << year << " was a leap year!" << endl;
        if (year == 2019)
            cout << year << " is a leap year!" << endl;
        if (year > 2019)
            cout << year << " will be a leap year!" << endl;
    }
    else
    {
        if (year < 2019)
            cout << year << " wasn't a leap year!" << endl;
        if (year == 2019)
            cout << year << " isn't a leap year!" << endl;
        if (year > 2019)
            cout << year << " won't be a leap year!" << endl;
    }

    return 0;
}