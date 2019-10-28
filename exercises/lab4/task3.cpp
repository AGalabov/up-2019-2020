#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    double inputNum;
    cin >> inputNum;
    double currMin = inputNum, currMax = inputNum;

    for (int i = 1; i < n; i++) // We start from 1 because we already read 1 number
    {
        cin >> inputNum;
        if (inputNum > currMax)
        {
            currMax = inputNum;
        }
        if (inputNum < currMin)
        {
            currMin = inputNum;
        }
    }

    cout << "Difference between max and min is: " << currMax - currMin << endl;

    return 0;
}