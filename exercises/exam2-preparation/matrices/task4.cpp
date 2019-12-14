#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

// When used only for sorting the points we can
// skip the square root
double getDistance(double x, double y)
{
    return sqrt(x * x + y * y);
}

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a[100][2];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        double min = getDistance(a[i][0], a[i][1]);
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > getDistance(a[j][0], a[j][1]))
            {
                min = getDistance(a[j][0], a[j][1]);
                minIndex = j;
            }
        }
        swap(a[i][0], a[minIndex][0]);
        swap(a[i][1], a[minIndex][1]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "(";
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << ")\n";
    }

    return 0;
}
