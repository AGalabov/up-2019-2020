#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);

    int len = strlen(str);

    for (int i = 0; i < len - 1; i++)
    {
        int indexOfMinValue = i;
        for (int j = i + 1; j < len; j++)
        {
            if (str[indexOfMinValue] > str[j])
            {
                indexOfMinValue = j;
            }
        }
        if (indexOfMinValue != i)
        {
            char temp = str[i];
            str[i] = str[indexOfMinValue];
            str[indexOfMinValue] = temp;
        }
    }
    cout << str << endl;

    return 0;
}