#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    int tempNum = num, numberOfDigits = 0;

    while (tempNum != 0)
    {
        numberOfDigits++;
        tempNum /= 10;
    }

    int sum = 0;
    tempNum = num;

    while (tempNum != 0)
    {
        int digit = tempNum % 10;
        sum += pow(digit, numberOfDigits);
        tempNum /= 10;
    }

    if (sum == num)
    {
        cout << num << " is Narcissistic." << endl;
    }
    else
    {
        cout << num << " is not Narcissistic." << endl;
    }

    return 0;
}