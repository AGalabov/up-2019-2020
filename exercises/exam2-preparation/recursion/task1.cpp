#include <iostream>
#include <string.h>

using namespace std;

int fibRecursive(int n)
{
    if (n <= 2)
        return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    cout << "Test fibonaccti: " << fibRecursive(5) << " " << fibRecursive(8) << endl;
    cout << "Test factorial: " << fact(5) << " " << fact(6) << endl;
}