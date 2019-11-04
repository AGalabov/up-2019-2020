#include <iostream>
using namespace std;

int main()
{
    int n, numbers[1024];
    cout << "Enter number of elements: n=";
    cin >> n;

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    if (n > 0)
    {
        cout << numbers[0] << " ";
    }
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] <= numbers[i - 1])
        {
            cout << endl;
        }
        cout << numbers[i] << " ";
    }

    return 0;
}