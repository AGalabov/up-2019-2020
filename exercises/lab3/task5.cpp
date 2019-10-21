#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n = ";
    cin >> n;

    for (int num = 1; num <= n; num++)
    {
        if (num % 3 != 0 && num % 5 != 0)
            cout << num;
        else
        {
            if (num % 3 == 0)
                cout << "FIZZ";
            if (num % 5 == 0)
                cout << "BUZZ";
        }
        cout << endl;
    }

    return 0;
}