#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);

    int index = 0;
    while (str[index] != '\0')
    {
        index++;
    }

    cout << "Calculated length is: " << index << endl;

    cout << "Result from actual strlen(): " << strlen(str) << endl;

    return 0;
}