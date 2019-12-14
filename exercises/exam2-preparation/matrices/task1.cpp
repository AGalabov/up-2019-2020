#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int a[10][10];
    int n; // we'll use only N x N matrices
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int sumNadGlavenDiag = 0;
    int sumPodVtorDiag = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i < j)
                sumNadGlavenDiag += a[i][j];
            if (i + j > n - 1)
                sumPodVtorDiag += a[i][j];
        }
    }

    cout << sumNadGlavenDiag << " + " << sumPodVtorDiag << " = " << sumNadGlavenDiag + sumPodVtorDiag << endl;
    return 0;
}
