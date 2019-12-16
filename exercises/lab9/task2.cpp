#include <iostream>
#include <string.h>

using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

bool isALetter(char a)
{
    return (a >= 'a' && a <= 'z') ||
           (a >= 'A' && a <= 'Z');
}

bool isCapitalLetter(char x)
{
    return 'A' <= x && x <= 'Z';
}

bool isSentanceEndingPunctuation(char x)
{
    return x == '.' || x == '?' || x == '!';
}

void toLower(char &x)
{
    x = 'a' + (x - 'A');
}

void removeCapsFromText(char *a)
{
    bool inSentance = false;
    for (int i = 0; i < strlen(a); ++i)
    {
        if (isSentanceEndingPunctuation(a[i]))
        {
            inSentance = false;
        }
        else if (isCapitalLetter(a[i]) && inSentance)
        {
            toLower(a[i]);
        }
        else if (isALetter(a[i]) && !inSentance)
        {
            inSentance = true;
        }
    }
}

int main()
{
    char a[1000];
    cin.getline(a, 1000);

    removeCapsFromText(a);

    cout << a;

    return 0;
}