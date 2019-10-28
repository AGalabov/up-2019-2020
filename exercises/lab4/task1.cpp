#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    bool hasDivisor = false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            hasDivisor = true;
            break;
        }
    }

    if (hasDivisor)
    {
        cout << num << " is not a prime number." << endl;
    }
    else
    {
        cout << num << " is a prime number." << endl;
    }

    return 0;
}