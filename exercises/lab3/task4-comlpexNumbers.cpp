#include <iostream>
#include <cmath>
using namespace std;

/*
Credits to: Nikolai Zhelqzkov
*/
int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0)
    {
        cout << "Izrodeno uravnenie = " << c << endl;
    }
    else if (b != 0 && a == 0)
    {
        float x = (c * (-1)) / b;
        cout << "Lineino uravnenie x = " << x << endl;
    }
    else
    {
        float x1, x2, re, d, im;
        re = -b / (2 * a);
        d = b * b - 4 * (a * c);
        im = sqrt(fabs(d)) / (2 * a);

        if (d > 0)
        {
            x1 = re + im;
            x2 = re - im;
            cout << "x1 = " << x1 << " x2= " << x2 << endl;
        }
        else if (d < 0)
        {
            cout << "Complex numbers :" << endl;
            cout << "x1 = ( " << re << ", " << im << " )" << endl;
            cout << "x2 = ( " << re << ", " << im * (-1) << " )" << endl;
        }
        else if (d == 0)
        {
            x1 = re;
            x2 = x1;
            cout << "Dvoen koren x1 = x2 = " << x2 << endl;
        }
    }
    return 0;
}