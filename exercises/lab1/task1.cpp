#include <iostream>
using namespace std;

int main()
{
    int int1, int2;
    double double1, double2;
    float float1, float2;

    cout << "Enter 2 integers: ";
    cin >> int1 >> int2;
    cout << "Enter 2 double numbers: ";
    cin >> double1 >> double2;
    cout << "Enter 2 float numbers: ";
    cin >> float1 >> float2;

    cout << endl
         << "-------Operations between integers-------" << endl;
    cout << int1 << " + " << int2 << " = " << int1 + int2 << endl;
    cout << int1 << " - " << int2 << " = " << int1 - int2 << endl;
    cout << int1 << " * " << int2 << " = " << int1 * int2 << endl;
    cout << int1 << " % " << int2 << " = " << int1 % int2 << endl;
    cout << int1 << " / " << int2 << " = " << int1 / int2 << endl;

    cout << endl
         << "-------Operations between doubles-------" << endl;
    cout << double1 << " + " << double2 << " = " << double1 + double2 << endl;
    cout << double1 << " - " << double2 << " = " << double1 - double2 << endl;
    cout << double1 << " * " << double2 << " = " << double1 * double2 << endl;
    //cout << double1 << " % " << double2 << " = " << double1 % double2 << endl;
    //Note: there is no remainders when using double so the line above would cause an error
    cout << double1 << " / " << double2 << " = " << double1 / double2 << endl;

    cout << endl
         << "-------Operations between floats-------" << endl;
    cout << float1 << " + " << float2 << " = " << float1 + float2 << endl;
    cout << float1 << " - " << float2 << " = " << float1 - float2 << endl;
    cout << float1 << " * " << float2 << " = " << float1 * float2 << endl;
    //cout << float1 << " % " << float2 << " = " << float1 % float2 << endl;
    //Note: there is no remainders when using float so the line above would cause an error
    cout << float1 << " / " << float2 << " = " << float1 / float2 << endl;

    cout << endl
         << "-----------Mixed operations------------" << endl;
    cout << int1 << " + " << double1 << " = " << int1 + double1 << endl;
    cout << int1 << " + " << float1 << " = " << int1 + float1 << endl;
    cout << double1 << " + " << float1 << " = " << double1 + float1 << endl;

    cout << int1 << " - " << double1 << " = " << int1 - double1 << endl;
    cout << int1 << " - " << float1 << " = " << int1 - float1 << endl;
    cout << double1 << " - " << float1 << " = " << double1 - float1 << endl;

    cout << int1 << " * " << double1 << " = " << int1 * double1 << endl;
    cout << int1 << " * " << float1 << " = " << int1 * float1 << endl;
    cout << double1 << " * " << float1 << " = " << double1 * float1 << endl;

    cout << int1 << " / " << double1 << " = " << int1 / double1 << endl;
    cout << double1 << " / " << int1 << " = " << double1 / int1 << endl;
    cout << int1 << " / " << float1 << " = " << int1 / float1 << endl;
    cout << float1 << " / " << int1 << " = " << float1 / int1 << endl;
    cout << double1 << " / " << float1 << " = " << double1 / float1 << endl;
    // Note: int is considered as a double/float and it works just fine

    // cout << int1 << " % " << float1 << " = " << int1 % float1 << endl;
    // cout << float1 << " % " << int1 << " = " << float1 % int1 << endl;

    // Note2: because of that we cant use % to find remainders even if one
    // of the operands is an integer(no matter if left or right)
    // So the previous commented code would cause an error:

    return 0;
}