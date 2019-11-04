#include <iostream>
using namespace std;

int main()
{
    int n, numbers[1024];

    cout << "Enter number of elements: n=";
    cin >> n;

    cout << "Enter " << n << " numbers:" << endl;
    if (n < 2)
    {
        cout << "Array should have atleast 2 elements!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int maxElem, secondMax;
    if (numbers[0] > numbers[1])
    {
        maxElem = numbers[0];
        secondMax = numbers[1];
    }
    else
    {
        maxElem = numbers[1];
        secondMax = numbers[0];
    }
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > maxElem)
        {
            secondMax = maxElem;
            maxElem = numbers[i];
        }
        else if (numbers[i] > secondMax)
        {
            secondMax = numbers[i];
        }
    }

    cout << "Second largest element is: " << secondMax << endl;

    return 0;
}