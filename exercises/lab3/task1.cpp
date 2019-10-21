#include <iostream>
using namespace std;

int main()
{
    char symbol;
    cout << "Enter a single symbol: ";
    cin >> symbol;

    switch (symbol)
    {
    case 'I':
        cout << 1;
        break;
    case 'V':
        cout << 5;
        break;
    case 'X':
        cout << 10;
        break;
    case 'L':
        cout << 50;
        break;
    case 'C':
        cout << 100;
        break;
    case 'D':
        cout << 500;
        break;
    case 'M':
        cout << 1000;
        break;
    default:
        cout << "Not a valid Roman numeral!";
    }
    cout << endl;

    // Note: Keep in mind the break keyword.
    // If ommited code for next cases will be executed as well.

    return 0;
}