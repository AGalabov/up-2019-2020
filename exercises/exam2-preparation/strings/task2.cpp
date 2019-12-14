#include <iostream>
#include <string.h>

using namespace std;

bool isALetter(char a)
{
    return (a >= 'a' && a <= 'z') ||
           (a >= 'A' && a <= 'Z');
}

bool isADigit(char a)
{
    return a >= '0' && a <= '9';
}

int main()
{
    char str1[1000];
    char str2[1000];
    cin.getline(str1, 1000);

    int j = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        char c = str1[i];
        if (isALetter(str1[i]) &&
            isADigit(str1[i + 1]))
        {
            int offset = str1[i + 1] - '0';
            c += offset;
            i++;
        }
        str2[j] = c;
        j++;
    }
    str2[j] = '\0';

    cout << str2 << endl;

    return 0;
}
