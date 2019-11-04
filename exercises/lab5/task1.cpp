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

    int maxElement = numbers[0], oddIndexesSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > maxElement)
        {
            maxElement = numbers[i];
        }
        if (i % 2 != 0)
        {
            oddIndexesSum += numbers[i];
        }
    }

    cout << "Maximum element is: " << maxElement << endl;
    cout << "Sum of elements at odd indexes is: " << oddIndexesSum << endl;

    return 0;
}