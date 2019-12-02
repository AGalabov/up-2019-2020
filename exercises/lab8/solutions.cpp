#include <iostream>
#include <cstring>

using namespace std;

bool check(double a, double b)
{
    // The number of zeroes sets the precision: 3 zeroes means that atleast the
    // first 3 digits after the decimal point of the two numbers are equal.
    double eps = 0.0000001;
    double sum = a + b;
    double result = 42.6;
    return result - eps <= sum && sum <= result + eps;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverese(char *a)
{
    int len = strlen(a);
    for (int i = 0; i < len / 2; ++i)
    {
        swap(a[i], a[len - 1 - i]);
    }
}

int main()
{
    cout << "-------------TASK 0----------------" << endl;
    cout << check(1.5, 2) << endl;       // should be false => 0
    cout << check(42.6, 0) << endl;      // should be true => 1
    cout << check(21.3, 21.3) << endl;   // should be true => 1
    cout << check(21.31, 21.29) << endl; // shoulde be true => 1

    cout << "-------------TASK 1----------------" << endl;
    int a = 3, b = 5;
    cout << "Before: a=" << a << " b=" << b << endl;
    swap(a, b);
    cout << "After: a=" << a << " b=" << b << endl;

    cout << "-------------TASK 2----------------" << endl;
    char str[100];
    cout << "Enter str: " << endl;
    cin.getline(str, 100);
    cout << "Before a=" << str << endl;
    reverese(str);
    cout << "After a=" << str << endl;

    return 0;
}