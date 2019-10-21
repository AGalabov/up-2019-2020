#include <iostream>
using namespace std;

int main()
{
    int first = 1, second = 0, newFibonacci;
    int n;
    cout << "Enter n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        newFibonacci = first + second;
        first = second;
        second = newFibonacci;
        cout << newFibonacci << " ";
    }
    cout << endl;

    return 0;
}