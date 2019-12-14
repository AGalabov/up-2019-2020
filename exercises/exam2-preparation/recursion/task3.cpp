#include <iostream>
#include <string.h>
using namespace std;

bool isAscending(int a[], int n, int current)
{
    if (current == n - 1)
        return true;

    if (a[current] > a[current + 1])
        return false;

    return isAscending(a, n, current + 1);
}

// This function overload allows us to use a cleaner
// interface when calling a function
bool isAscending(int a[], int n)
{
    return isAscending(a, n, 0);
}

int main()
{
    int asc[5] = {-11, 0, 5, 12, 42};
    int notAsc[5] = {1, -1, 0, 2, -2};

    cout << isAscending(asc, 5) << endl;
    cout << isAscending(notAsc, 5) << endl;
}