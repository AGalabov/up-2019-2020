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
        bool madeSwap = false;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                madeSwap = true;
            }
        }
        if (!madeSwap)
            break;
    }
    cout << str << endl;

    return 0;
}