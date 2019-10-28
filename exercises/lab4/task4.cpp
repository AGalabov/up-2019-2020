#include <iostream>
using namespace std;

int main()
{
    int currNum, prevNum, sum = 0;
    cin >> currNum;
    prevNum = currNum;

    while (currNum >= prevNum)
    {
        sum += currNum;
        prevNum = currNum;
        cin >> currNum;
    }
    cout << "Sum is: " << sum << endl;

    return 0;
}