#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a 3 digit number: ";
    cin >> num;

    //We take for granted that the input number is actually a 3 digit one
    cout << num % 10 << " " << (num / 10) % 10 << " " << num / 100 << endl;

    return 0;
}