#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 3 == 0)
    {
        cout << "FIZZ";
    }
    if (num % 5 == 0)
        cout << "BUS"; //Note: Curly brackets {} can be ommited for single lines

    cout << endl;

    return 0;
}