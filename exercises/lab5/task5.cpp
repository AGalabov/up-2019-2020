#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int arr1[50], arr2[50];

    cout << "Size of arr1 n = ";
    cin >> n;

    cout << "Size of arr2 m = ";
    cin >> m;

    if (n < m)
    {
        cout << "Invalid lengths - arr2 should be smaller than arr1" << endl;
    }

    cout << "Enter arr1 elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter arr2 elements:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    bool isSubsequence = false;

    for (int i = 0; i < n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i + j] != arr2[j])
                break;
            if (j == m - 1)
                isSubsequence = true;
        }
        if (isSubsequence)
            break;
    }

    if (isSubsequence)
    {
        cout << "arr2 is a subsequence of arr1!" << endl;
    }
    else
    {
        cout << "arr2 is NOT a subsequence of arr1!" << endl;
    }

    return 0;
}