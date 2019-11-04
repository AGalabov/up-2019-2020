#include <iostream>
using namespace std;

int main()
{
    int n, numbers[10][10];

    cout << "n = ";
    cin >> n;

    cout << "Enter " << n << " x " << n << " matrix:" << endl;

    for (int i = 0; i < n; i++) // row
    {
        for (int j = 0; j < n; j++) // column
        {
            cout << "numbers[" << i << "][" << j << "] = ";
            cin >> numbers[i][j];
        }
    }

    double oddRowSum = 0, evenRowSum = 0;
    for (int i = 0; i < n; i++) // row
    {
        for (int j = 0; j < n; j++) // column
        {
            if (i % 2 == 0)
            {
                evenRowSum += numbers[i][j];
            }
            else
            {
                oddRowSum += numbers[i][j];
            }
        }
    }

    cout << "Result: " << oddRowSum / evenRowSum << endl;

    return 0;
}