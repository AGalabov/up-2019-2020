#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter a, b and c ";
    cin >> a >> b >> c;
    cout << "Solutons to the equasion: " << a << "x^2 + " << b << "x + " << c << " = 0\n";

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        cout << "There are 2 real solution:" << endl
             << "x1 = " << (-b + sqrt(discriminant)) / 2 * a << endl
             << "x2 = " << (-b - sqrt(discriminant)) / 2 * a << endl;
    }
    else if (discriminant == 0)
    {
        cout << "There is 1 real solution:" << endl
             << "x1 = " << -b / 2 * a << endl;
    }
    else
    {
        cout << "There are no real solutions!" << endl;
    }

    return 0;
}