#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[100];
    char str2[100];

    cin.getline(str1, 100);
    cin.getline(str2, 100);
    int lengthOfStr1 = strlen(str1);
    int lengthOfStr2 = strlen(str2);
    int minimumLength;
    if (lengthOfStr1 > lengthOfStr2)
        minimumLength = lengthOfStr2;
    else
        minimumLength = lengthOfStr1;

    bool foundAnswer = false;
    for (int i = 0; i < minimumLength; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] > str2[i])
            {
                cout << "1";
            }
            if (str1[i] < str2[i])
            {
                cout << "-1";
            }
            foundAnswer = true;
            break;
        }
    }
    if (!foundAnswer)
    {
        if (lengthOfStr1 > lengthOfStr2)
        {
            cout << "1";
        }
        else if (lengthOfStr1 < lengthOfStr2)
        {
            cout << "-1";
        }
        else
            cout << "0";
    }
    cout << endl;

    cout << "Result from actual strcmp(): " << strcmp(str1, str2) << endl;
    return 0;
}